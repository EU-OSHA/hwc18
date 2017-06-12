<?php
/**
 * @file
 * hwc_priority_areas.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hwc_priority_areas_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_b2a712c5-d2ec-4e5a-8819-7725801aa458';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Priority area',
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
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'priority_area' => 'priority_area',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
    'center' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '44fe0d5e-a782-4a04-9c93-ff1874ad4bb5';
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-232855d9-0adc-41cf-a050-f78c365d0426';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'field_formatter_class' => '',
      'image_style' => 'article_image',
      'image_link' => '',
    ),
    'context' => 'argument_term_1',
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
  $pane->uuid = '232855d9-0adc-41cf-a050-f78c365d0426';
  $display->content['new-232855d9-0adc-41cf-a050-f78c365d0426'] = $pane;
  $display->panels['center'][0] = 'new-232855d9-0adc-41cf-a050-f78c365d0426';
  $pane = new stdClass();
  $pane->pid = 'new-2b3436b0-cae6-4242-94b7-a7ab34fb5580';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:name_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => 'h1',
      'title_link' => '',
      'title_class' => '',
      'field_formatter_class' => '',
      'trim_length' => '600',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
    ),
    'context' => 'argument_term_1',
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
  $pane->uuid = '2b3436b0-cae6-4242-94b7-a7ab34fb5580';
  $display->content['new-2b3436b0-cae6-4242-94b7-a7ab34fb5580'] = $pane;
  $display->panels['center'][1] = 'new-2b3436b0-cae6-4242-94b7-a7ab34fb5580';
  $pane = new stdClass();
  $pane->pid = 'new-cfe72b59-3899-4d8e-a789-9bc596640000';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_introduction_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
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
    'context' => 'argument_term_1',
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
  $pane->uuid = 'cfe72b59-3899-4d8e-a789-9bc596640000';
  $display->content['new-cfe72b59-3899-4d8e-a789-9bc596640000'] = $pane;
  $display->panels['center'][2] = 'new-cfe72b59-3899-4d8e-a789-9bc596640000';
  $pane = new stdClass();
  $pane->pid = 'new-24f5a734-25a7-43d0-8984-23bfc1e4b712';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_links_and_info';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '24f5a734-25a7-43d0-8984-23bfc1e4b712';
  $display->content['new-24f5a734-25a7-43d0-8984-23bfc1e4b712'] = $pane;
  $display->panels['center'][3] = 'new-24f5a734-25a7-43d0-8984-23bfc1e4b712';
  $pane = new stdClass();
  $pane->pid = 'new-dc45b8e7-31cd-464f-a59c-7ea8e53cc683';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_highlights';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'dc45b8e7-31cd-464f-a59c-7ea8e53cc683';
  $display->content['new-dc45b8e7-31cd-464f-a59c-7ea8e53cc683'] = $pane;
  $display->panels['center'][4] = 'new-dc45b8e7-31cd-464f-a59c-7ea8e53cc683';
  $pane = new stdClass();
  $pane->pid = 'new-ca973aff-6bfe-4410-826a-823fe13ea13d';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_practical_tools';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'ca973aff-6bfe-4410-826a-823fe13ea13d';
  $display->content['new-ca973aff-6bfe-4410-826a-823fe13ea13d'] = $pane;
  $display->panels['center'][5] = 'new-ca973aff-6bfe-4410-826a-823fe13ea13d';
  $pane = new stdClass();
  $pane->pid = 'new-81357d1a-b21a-4301-9f94-83f69c6ffaf0';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_case_studies';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '81357d1a-b21a-4301-9f94-83f69c6ffaf0';
  $display->content['new-81357d1a-b21a-4301-9f94-83f69c6ffaf0'] = $pane;
  $display->panels['center'][6] = 'new-81357d1a-b21a-4301-9f94-83f69c6ffaf0';
  $pane = new stdClass();
  $pane->pid = 'new-5055f284-6369-4f68-9f93-2fdb6af0a644';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_publications';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '5055f284-6369-4f68-9f93-2fdb6af0a644';
  $display->content['new-5055f284-6369-4f68-9f93-2fdb6af0a644'] = $pane;
  $display->panels['center'][7] = 'new-5055f284-6369-4f68-9f93-2fdb6af0a644';
  $pane = new stdClass();
  $pane->pid = 'new-3612da0a-99af-4965-af71-093a59605e52';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_etool';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '3612da0a-99af-4965-af71-093a59605e52';
  $display->content['new-3612da0a-99af-4965-af71-093a59605e52'] = $pane;
  $display->panels['center'][8] = 'new-3612da0a-99af-4965-af71-093a59605e52';
  $pane = new stdClass();
  $pane->pid = 'new-181b6a0c-9a3e-4d64-88b5-2287352c1203';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_related_links';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '181b6a0c-9a3e-4d64-88b5-2287352c1203';
  $display->content['new-181b6a0c-9a3e-4d64-88b5-2287352c1203'] = $pane;
  $display->panels['center'][9] = 'new-181b6a0c-9a3e-4d64-88b5-2287352c1203';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_b2a712c5-d2ec-4e5a-8819-7725801aa458'] = $handler;

  return $export;
}
