<?php
/**
 * @file
 * hwc_practical_tool.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hwc_practical_tool_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_360a915c-f1c6-4b3e-b1dc-ff84b5e20b36';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'Audio visual',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'audio_visual' => 'audio_visual',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'df2633ed-6f19-436a-82a4-70cf3470174e';
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-020511e6-004b-4654-a4b0-8d50094b675f';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '020511e6-004b-4654-a4b0-8d50094b675f';
  $display->content['new-020511e6-004b-4654-a4b0-8d50094b675f'] = $pane;
  $display->panels['middle'][0] = 'new-020511e6-004b-4654-a4b0-8d50094b675f';
  $pane = new stdClass();
  $pane->pid = 'new-b4bbcef9-d0fc-4e09-a7cd-f8303ec25cfa';
  $pane->panel = 'middle';
  $pane->type = 'node_type_desc';
  $pane->subtype = 'node_type_desc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b4bbcef9-d0fc-4e09-a7cd-f8303ec25cfa';
  $display->content['new-b4bbcef9-d0fc-4e09-a7cd-f8303ec25cfa'] = $pane;
  $display->panels['middle'][1] = 'new-b4bbcef9-d0fc-4e09-a7cd-f8303ec25cfa';
  $pane = new stdClass();
  $pane->pid = 'new-4417d844-209c-4dbe-901d-48c3b78e1677';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_sector_industry_covered';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4417d844-209c-4dbe-901d-48c3b78e1677';
  $display->content['new-4417d844-209c-4dbe-901d-48c3b78e1677'] = $pane;
  $display->panels['middle'][2] = 'new-4417d844-209c-4dbe-901d-48c3b78e1677';
  $pane = new stdClass();
  $pane->pid = 'new-7c727e5a-b54b-4f67-ab42-26efcc9867da';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_tasks_covered';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '7c727e5a-b54b-4f67-ab42-26efcc9867da';
  $display->content['new-7c727e5a-b54b-4f67-ab42-26efcc9867da'] = $pane;
  $display->panels['middle'][3] = 'new-7c727e5a-b54b-4f67-ab42-26efcc9867da';
  $pane = new stdClass();
  $pane->pid = 'new-03d2b942-e176-44f2-9aa3-c622886e2d23';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_biological_hazard';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '03d2b942-e176-44f2-9aa3-c622886e2d23';
  $display->content['new-03d2b942-e176-44f2-9aa3-c622886e2d23'] = $pane;
  $display->panels['middle'][4] = 'new-03d2b942-e176-44f2-9aa3-c622886e2d23';
  $pane = new stdClass();
  $pane->pid = 'new-89d13948-4e54-4fbc-bf86-3f3c040d7ace';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_hazard_physical_state';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '89d13948-4e54-4fbc-bf86-3f3c040d7ace';
  $display->content['new-89d13948-4e54-4fbc-bf86-3f3c040d7ace'] = $pane;
  $display->panels['middle'][5] = 'new-89d13948-4e54-4fbc-bf86-3f3c040d7ace';
  $pane = new stdClass();
  $pane->pid = 'new-354049c8-78e5-48c1-8f71-6ca898f3e146';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_hazard_health_effects';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '354049c8-78e5-48c1-8f71-6ca898f3e146';
  $display->content['new-354049c8-78e5-48c1-8f71-6ca898f3e146'] = $pane;
  $display->panels['middle'][6] = 'new-354049c8-78e5-48c1-8f71-6ca898f3e146';
  $pane = new stdClass();
  $pane->pid = 'new-7293a883-00ba-4e3f-8db8-b14c27344e81';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_exposure_route';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '7293a883-00ba-4e3f-8db8-b14c27344e81';
  $display->content['new-7293a883-00ba-4e3f-8db8-b14c27344e81'] = $pane;
  $display->panels['middle'][7] = 'new-7293a883-00ba-4e3f-8db8-b14c27344e81';
  $pane = new stdClass();
  $pane->pid = 'new-b28b4438-6acf-4882-ad2c-89880baf6ea6';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'smart_trim_format',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'summary_handler' => 'full',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'b28b4438-6acf-4882-ad2c-89880baf6ea6';
  $display->content['new-b28b4438-6acf-4882-ad2c-89880baf6ea6'] = $pane;
  $display->panels['middle'][8] = 'new-b28b4438-6acf-4882-ad2c-89880baf6ea6';
  $pane = new stdClass();
  $pane->pid = 'new-bb4d6585-a484-4cc4-b82a-d5a592ce4ae0';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_summary';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'smart_trim_format',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'bb4d6585-a484-4cc4-b82a-d5a592ce4ae0';
  $display->content['new-bb4d6585-a484-4cc4-b82a-d5a592ce4ae0'] = $pane;
  $display->panels['middle'][9] = 'new-bb4d6585-a484-4cc4-b82a-d5a592ce4ae0';
  $pane = new stdClass();
  $pane->pid = 'new-6401b0b3-53fc-4518-98a0-20e03c9451f7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_cas_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '6401b0b3-53fc-4518-98a0-20e03c9451f7';
  $display->content['new-6401b0b3-53fc-4518-98a0-20e03c9451f7'] = $pane;
  $display->panels['middle'][10] = 'new-6401b0b3-53fc-4518-98a0-20e03c9451f7';
  $pane = new stdClass();
  $pane->pid = 'new-b7e18d74-24fd-4929-b1b2-5bb50a803724';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ec_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = 'b7e18d74-24fd-4929-b1b2-5bb50a803724';
  $display->content['new-b7e18d74-24fd-4929-b1b2-5bb50a803724'] = $pane;
  $display->panels['middle'][11] = 'new-b7e18d74-24fd-4929-b1b2-5bb50a803724';
  $pane = new stdClass();
  $pane->pid = 'new-58e4a9e1-2bbc-4730-b7e9-ab12213a2753';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_prevention_measure_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '58e4a9e1-2bbc-4730-b7e9-ab12213a2753';
  $display->content['new-58e4a9e1-2bbc-4730-b7e9-ab12213a2753'] = $pane;
  $display->panels['middle'][12] = 'new-58e4a9e1-2bbc-4730-b7e9-ab12213a2753';
  $pane = new stdClass();
  $pane->pid = 'new-6c560d01-0b20-4b65-a98c-939d54be62c8';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_material_purpose_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '6c560d01-0b20-4b65-a98c-939d54be62c8';
  $display->content['new-6c560d01-0b20-4b65-a98c-939d54be62c8'] = $pane;
  $display->panels['middle'][13] = 'new-6c560d01-0b20-4b65-a98c-939d54be62c8';
  $pane = new stdClass();
  $pane->pid = 'new-1a545e55-e698-4440-b4d9-231471ac047d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_item_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = '1a545e55-e698-4440-b4d9-231471ac047d';
  $display->content['new-1a545e55-e698-4440-b4d9-231471ac047d'] = $pane;
  $display->panels['middle'][14] = 'new-1a545e55-e698-4440-b4d9-231471ac047d';
  $pane = new stdClass();
  $pane->pid = 'new-32375261-4f6a-4420-b21b-4f5da788e9e4';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_target_group';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '32375261-4f6a-4420-b21b-4f5da788e9e4';
  $display->content['new-32375261-4f6a-4420-b21b-4f5da788e9e4'] = $pane;
  $display->panels['middle'][15] = 'new-32375261-4f6a-4420-b21b-4f5da788e9e4';
  $pane = new stdClass();
  $pane->pid = 'new-e6bd8168-2b1a-4961-85fb-ee4b097b505a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_year';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'osha_day_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'field_formatter_class' => '',
      'osha_date_theme' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = 'e6bd8168-2b1a-4961-85fb-ee4b097b505a';
  $display->content['new-e6bd8168-2b1a-4961-85fb-ee4b097b505a'] = $pane;
  $display->panels['middle'][16] = 'new-e6bd8168-2b1a-4961-85fb-ee4b097b505a';
  $pane = new stdClass();
  $pane->pid = 'new-7e5fcd38-b3da-4505-ba7d-dda7dcb5deca';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'hwc_practical_tool-hwc_practical_tool_back_to_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 17;
  $pane->locks = array();
  $pane->uuid = '7e5fcd38-b3da-4505-ba7d-dda7dcb5deca';
  $display->content['new-7e5fcd38-b3da-4505-ba7d-dda7dcb5deca'] = $pane;
  $display->panels['middle'][17] = 'new-7e5fcd38-b3da-4505-ba7d-dda7dcb5deca';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_360a915c-f1c6-4b3e-b1dc-ff84b5e20b36'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__practical_tool_details';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Practical tool details',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'practical_tool_details',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'practical_tool' => 'practical_tool',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'practical_tool_details';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '545f69dd-e116-42e2-84f3-054360f7be44';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__practical_tool_details';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-17e4ba2d-cfaa-4abd-86fc-95793b7a896a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '17e4ba2d-cfaa-4abd-86fc-95793b7a896a';
  $display->content['new-17e4ba2d-cfaa-4abd-86fc-95793b7a896a'] = $pane;
  $display->panels['middle'][0] = 'new-17e4ba2d-cfaa-4abd-86fc-95793b7a896a';
  $pane = new stdClass();
  $pane->pid = 'new-dbe6a5c3-c9c2-4e06-9375-c621746fa6d5';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_access_tool_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dbe6a5c3-c9c2-4e06-9375-c621746fa6d5';
  $display->content['new-dbe6a5c3-c9c2-4e06-9375-c621746fa6d5'] = $pane;
  $display->panels['middle'][1] = 'new-dbe6a5c3-c9c2-4e06-9375-c621746fa6d5';
  $pane = new stdClass();
  $pane->pid = 'new-2bb1117c-639c-4418-bd68-2caa41b5e0b8';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'shs_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'linked' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2bb1117c-639c-4418-bd68-2caa41b5e0b8';
  $display->content['new-2bb1117c-639c-4418-bd68-2caa41b5e0b8'] = $pane;
  $display->panels['middle'][2] = 'new-2bb1117c-639c-4418-bd68-2caa41b5e0b8';
  $pane = new stdClass();
  $pane->pid = 'new-9f3c2633-133a-4798-8bf4-3121b92383a5';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_tool_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'shs_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'linked' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '9f3c2633-133a-4798-8bf4-3121b92383a5';
  $display->content['new-9f3c2633-133a-4798-8bf4-3121b92383a5'] = $pane;
  $display->panels['middle'][3] = 'new-9f3c2633-133a-4798-8bf4-3121b92383a5';
  $pane = new stdClass();
  $pane->pid = 'new-5ba23bf6-8452-4173-ba14-920c18ac8087';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_provider';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5ba23bf6-8452-4173-ba14-920c18ac8087';
  $display->content['new-5ba23bf6-8452-4173-ba14-920c18ac8087'] = $pane;
  $display->panels['middle'][4] = 'new-5ba23bf6-8452-4173-ba14-920c18ac8087';
  $pane = new stdClass();
  $pane->pid = 'new-3de5993f-8af1-4d01-be26-9c78f9f586c1';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '3de5993f-8af1-4d01-be26-9c78f9f586c1';
  $display->content['new-3de5993f-8af1-4d01-be26-9c78f9f586c1'] = $pane;
  $display->panels['middle'][5] = 'new-3de5993f-8af1-4d01-be26-9c78f9f586c1';
  $pane = new stdClass();
  $pane->pid = 'new-d56ffd82-10b5-4386-958c-2777853bbf08';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_additional_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd56ffd82-10b5-4386-958c-2777853bbf08';
  $display->content['new-d56ffd82-10b5-4386-958c-2777853bbf08'] = $pane;
  $display->panels['middle'][6] = 'new-d56ffd82-10b5-4386-958c-2777853bbf08';
  $pane = new stdClass();
  $pane->pid = 'new-02d7c136-f951-4699-87eb-d28672a3fd65';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_access_tool_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '02d7c136-f951-4699-87eb-d28672a3fd65';
  $display->content['new-02d7c136-f951-4699-87eb-d28672a3fd65'] = $pane;
  $display->panels['middle'][7] = 'new-02d7c136-f951-4699-87eb-d28672a3fd65';
  $pane = new stdClass();
  $pane->pid = 'new-5191f675-de94-4325-99c9-a1eb9598fe75';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_available_languages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'language_list_formatter',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'format' => array(
        'name' => 'name',
        'iso' => 0,
        'name_native' => 0,
      ),
      'separator' => ',',
      'label' => 'Languages:',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '5191f675-de94-4325-99c9-a1eb9598fe75';
  $display->content['new-5191f675-de94-4325-99c9-a1eb9598fe75'] = $pane;
  $display->panels['middle'][8] = 'new-5191f675-de94-4325-99c9-a1eb9598fe75';
  $pane = new stdClass();
  $pane->pid = 'new-ae6519dd-fdf0-4243-85d0-31800a0b5d40';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_access_tool_link_fc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'access_tool_link_details',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'delete' => '',
      'add' => '',
      'description' => 1,
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'ae6519dd-fdf0-4243-85d0-31800a0b5d40';
  $display->content['new-ae6519dd-fdf0-4243-85d0-31800a0b5d40'] = $pane;
  $display->panels['middle'][9] = 'new-ae6519dd-fdf0-4243-85d0-31800a0b5d40';
  $pane = new stdClass();
  $pane->pid = 'new-4ea61eda-ab16-477e-849f-d1b59140cfa6';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_external_urls';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
      'field_formatter_class' => '',
      'view_mode' => 'osha_resources',
      'links' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '4ea61eda-ab16-477e-849f-d1b59140cfa6';
  $display->content['new-4ea61eda-ab16-477e-849f-d1b59140cfa6'] = $pane;
  $display->panels['middle'][10] = 'new-4ea61eda-ab16-477e-849f-d1b59140cfa6';
  $pane = new stdClass();
  $pane->pid = 'new-3c0ae43b-bd78-4414-baca-fe35dd1cb3ae';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'hwc_practical_tool-hwc_practical_tool_back_to_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '3c0ae43b-bd78-4414-baca-fe35dd1cb3ae';
  $display->content['new-3c0ae43b-bd78-4414-baca-fe35dd1cb3ae'] = $pane;
  $display->panels['middle'][11] = 'new-3c0ae43b-bd78-4414-baca-fe35dd1cb3ae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__practical_tool_details'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_practical_tool_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'practical_tools_listing';
  $page->task = 'page';
  $page->admin_title = 'Practical tools listing';
  $page->admin_description = '';
  $page->path = 'practical-tools';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_practical_tools_listing__panel_context_f90c4d3e-683b-4dd2-a516-4b046ab3e75f';
  $handler->task = 'page';
  $handler->subtask = 'practical_tools_listing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Practical tools listing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
    'middle' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Practical tools';
  $display->uuid = '286d97ce-6c9e-4437-852b-031f77a40961';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_practical_tools_listing__panel_context_f90c4d3e-683b-4dd2-a516-4b046ab3e75f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-84992a82-9ee8-44c2-8b19-f23a24a82abe';
  $pane->panel = 'middle';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '139',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'section-introduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '84992a82-9ee8-44c2-8b19-f23a24a82abe';
  $display->content['new-84992a82-9ee8-44c2-8b19-f23a24a82abe'] = $pane;
  $display->panels['middle'][0] = 'new-84992a82-9ee8-44c2-8b19-f23a24a82abe';
  $pane = new stdClass();
  $pane->pid = 'new-65a196f7-6a56-4168-94c7-f950af997e21';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'hwc_practical_tool-hwc_practical_tool_listing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '65a196f7-6a56-4168-94c7-f950af997e21';
  $display->content['new-65a196f7-6a56-4168-94c7-f950af997e21'] = $pane;
  $display->panels['middle'][1] = 'new-65a196f7-6a56-4168-94c7-f950af997e21';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-84992a82-9ee8-44c2-8b19-f23a24a82abe';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['practical_tools_listing'] = $page;

  return $pages;

}
