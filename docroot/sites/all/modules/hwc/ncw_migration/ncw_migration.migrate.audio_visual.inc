<?php

/**
 * Class NCWAudioVisualMigration migrates press contacts
 *
 * Set hwc_migration_audio_visual_url variable for explicit source URL.
 */
class NCWAudioVisualMigration extends AbstractNCWNodeMigration {

  public $new_providers = array();

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWAudioVisualSource', 'audio_visual');
    $this->description = 'Import audio_visual from NCW';
  }

  function getTermReferenceFieldsMap() {
    return [
      'field_priority_area' => 'priority_area',
      'field_provider_type' => 'provider_type',
      'field_material_country' => 'country',
      'field_sector_industry_covered' => 'nace_codes',
      'field_tasks_covered' => 'hazmap_categories',

      'field_biological_hazard' => 'biological_hazard',
      'field_hazard_physical_state' => 'hazard_physical_state',
      'field_hazard_health_effects' => 'hazard_health_effects',
      'field_exposure_route' => 'exposure_route',
      'field_worker_groups_type' => 'worker_groups',

      'field_prevention_measure_type' => 'prevention_measures',
      'field_material_purpose_type' => 'material_purpose',
      'field_target_group' => 'target_group',
      'field_evaluation' => 'evaluation',
      'field_visualisation_material_typ' => 'material_objective'
    ];
  }

  function addFieldMappings() {
    parent::addFieldMappings();
    $unmigrated_destinations = [];
    foreach($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      if ($taxonomy == 'field_provider_type') {
        continue;
      }
      $this->addFieldMapping($taxonomy . ':source_type')->defaultValue('tid');
      $this->addFieldMapping($taxonomy . ':create_term')->defaultValue(FALSE);
      $this->addFieldMapping($taxonomy, $taxonomy);
      $unmigrated_destinations[] = $taxonomy . ':ignore_case';
    }

    $this->addFieldMapping('field_country:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_country:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_country', 'field_material_country');
    $unmigrated_destinations[] = 'field_country:ignore_case';

    $this->addUnmigratedDestinations($unmigrated_destinations);
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    $map = array_keys($this->getTermReferenceFieldsMap());
    $map[] = 'field_fc_provider';
    return $map;
  }

  public function prepare($entity, stdClass $row) {
    parent::prepare($entity, $row);
    $this->new_providers = [];

    if ($entity->field_available_in_languages) { // language_field fix
      $entity->field_available_in_languages['und'] = $entity->field_available_in_languages['und'][0]['value'];
    }

    if ($entity->field_video_length) { // cck_time fix
      $hm = explode(':', $entity->field_video_length['und'][0]['value'][0]['value']);
      $entity->field_video_length['und'][0] = ['hour' => @$hm[0], 'minute' => @$hm[1]];
    }
    // field_collection_item - field_fc_provider
    $entity_ids = [];
    if ($entity->nid) {
      $result = db_query("SELECT field_fc_provider_value from field_data_field_fc_provider where entity_id=" . $entity->nid);
      foreach($result as $value) {
        $objects = entity_load('field_collection_item', [$value->field_fc_provider_value]);
        if ($objects) {
          $entity_ids[] = $value->field_fc_provider_value;
        }
      }
    }
    $fc_providers = [];
    foreach($row->field_fc_provider as $idx => $provider) {
      if (@$entity_ids[$idx]) {
        $objects = entity_load('field_collection_item', [$entity_ids[$idx]]);
        $field_collection = $objects[$entity_ids[$idx]];
      } else {
        $field_collection = entity_create('field_collection_item', array('field_name' => 'field_fc_provider'));
        if ($entity->nid) {
          $hostEntity = node_load($entity->nid);
          $field_collection->setHostEntity('node', $hostEntity, LANGUAGE_NONE, FALSE);
        }
      }
      $field_collection->field_fc_provider_name = $provider['field_fc_provider_name'];
      $field_collection->field_fc_provider_name_o = $provider['field_fc_provider_name_o'];
      $field_collection->field_fc_provider_url = $provider['field_fc_provider_url'];
      $tids = osha_migration_normalize_migrated_term_reference($provider['field_provider_type'], 'tax_provider_type');
      $field_collection->field_provider_type = [];
      foreach($tids as $tid) {
        $field_collection->field_provider_type['und'][] = ['tid' => $tid];
      }
      $field_collection->field_type_provider_other = $provider['field_type_provider_other'];
      if (!$entity->nid) {
        $this->new_providers[] = $field_collection;
      } else {
        $field_collection->save(TRUE);
        $fc_providers[] = ['value' => $field_collection->item_id, 'revision_id' => $field_collection->revision_id];
      }
    }

    $entity->field_fc_provider = [];
    if ($fc_providers) {
      $entity->field_fc_provider = ['und' => $fc_providers];
    }
  }

  /**
   * Implements Migration::complete() to configure translations
   */
  public function complete($entity, stdClass $row) {
    parent::complete($entity, $row);
    if ($this->new_providers) {
      foreach($this->new_providers as $field_collection) {
        $field_collection->setHostEntity('node', $entity, LANGUAGE_NONE, FALSE);
        $field_collection->save(TRUE);
        $entity->field_fc_provider['und'][] = ['value' => $field_collection->item_id, 'revision_id' => $field_collection->revision_id];
      }
      node_save($entity);
    }
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    foreach($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      if ($row->{$taxonomy}) {
        $orig_taxonomies = $row->{$taxonomy};
        $row->{$taxonomy} = osha_migration_normalize_migrated_term_reference($row->{$taxonomy}, 'tax_' . $vocabulary);
        if (!$row->{$taxonomy}) {
          foreach($orig_taxonomies as $orig_taxonomy) {
            watchdog('ncw_migration', "[BUG]Cannot find taxonomy '".serialize($orig_taxonomy)."', for $vocabulary", array(), WATCHDOG_ERROR);
          }
          // todo add log message 'not found tax value...
        }
      }
    }
    $row->field_country = $row->field_material_country;
  }
}


class NCWAudioVisualSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'field_priority_area' => '',
      'field_provider_type' => '',
      'field_material_country' => '',
      'field_sector_industry_covered' => '',
      'field_tasks_covered' => '',

      'field_biological_hazard' => '',
      'field_hazard_physical_state' => '',
      'field_hazard_health_effects' => '',
      'field_exposure_route' => '',
      'field_worker_groups_type' => '',

      'field_prevention_measure_type' => '',
      'field_material_purpose_type' => '',
      'field_target_group' => '',
      'field_evaluation' => '',
      'field_visualisation_material_typ' => '',
    );

    $text = [
      'field_available_in_languages'=>'',
      'body' => '',
      'body_format' => '',
      'body_language' => '',
      'body_summary' => '',
      'field_advertising' => '',
      'field_biological_hazard_other' => '',
      'field_body_original' => '',
      'field_body_original_format' => '',
      'field_cas_number' => '',
      'field_contact_address' => '',
      'field_contact_address_format' => '',
      'field_country_other' => '',
      'field_disclaimer' => '',
      'field_disclaimer_format' => '',
      'field_ec_number' => '',
      'field_evaluation_other' => '',
      'field_exposure_route_other' => '',
      'field_external_url' => '',
      'field_hazard_health_other' => '',
      'field_hazard_physical_other' => '',
      'field_image'=>'',
      'field_image_language' => '',
      'field_intellectual_property_righ' => '',
      'field_item_type' => '',
      'field_languages_other' => '',
      'field_material_purpose_other' => '',
      'field_measurement_method' => '',
      'field_media_format' => '',
      'field_notes' => '',
      'field_notes_format' => '',
      'field_other_information' => '',
      'field_other_information_format' => '',
      'field_ownership_information' => '',
      'field_ownership_information_format' => '',
      'field_prevention_measures_other' => '',
      'field_publication_year' => '',
      'field_publication_year_value2' => '',
      'field_publication_year_timezone' => '',
      'field_rights_description' => '',
      'field_sector_industry_other' => '',
      'field_selected_for_analysis' => '',
      'field_summary' => '',
      'field_summary_format' => '',
      'field_summary_language' => '',
      'field_target_group_other' => '',
      'field_tasks_other' => '',
      'field_title_original' => '',
      'field_video_length' => '',
      'field_video_length_hour' => '',
      'field_video_length_minute' => '',
      'field_visualisation_mat_other' => '',
      'field_worker_groups_other' => '',
      'title_field' => '',
      'field_fc_provider' => '',
      'field_external_url_attributes' => '',
      'field_external_url_language' => '',
      'field_external_url_title' => '',
      'title_field_language' => '',
    ];
    $fields += $text;
    return $fields;
  }
}
