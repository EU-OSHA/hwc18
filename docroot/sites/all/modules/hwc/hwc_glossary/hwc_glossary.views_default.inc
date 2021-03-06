<?php
/**
 * @file
 * hwc_glossary.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hwc_glossary_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'glossary_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Glossary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Glossary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 1;
  /* Field: Taxonomy term: Description */
  $handler->display->display_options['fields']['description_field']['id'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['table'] = 'field_data_description_field';
  $handler->display->display_options['fields']['description_field']['field'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['label'] = '';
  $handler->display->display_options['fields']['description_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['description_field']['link_to_entity'] = 0;
  /* Field: Taxonomy term: Type */
  $handler->display->display_options['fields']['field_glossary_type']['id'] = 'field_glossary_type';
  $handler->display->display_options['fields']['field_glossary_type']['table'] = 'field_data_field_glossary_type';
  $handler->display->display_options['fields']['field_glossary_type']['field'] = 'field_glossary_type';
  $handler->display->display_options['fields']['field_glossary_type']['label'] = '';
  $handler->display->display_options['fields']['field_glossary_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_glossary_type']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Taxonomy term: Type (field_glossary_type) */
  $handler->display->display_options['arguments']['field_glossary_type_tid']['id'] = 'field_glossary_type_tid';
  $handler->display->display_options['arguments']['field_glossary_type_tid']['table'] = 'field_data_field_glossary_type';
  $handler->display->display_options['arguments']['field_glossary_type_tid']['field'] = 'field_glossary_type_tid';
  $handler->display->display_options['arguments']['field_glossary_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_glossary_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_glossary_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_glossary_type_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'glossary' => 'glossary',
  );
  /* Filter criterion: Taxonomy term: Type (field_glossary_type) */
  $handler->display->display_options['filters']['field_glossary_type_tid']['id'] = 'field_glossary_type_tid';
  $handler->display->display_options['filters']['field_glossary_type_tid']['table'] = 'field_data_field_glossary_type';
  $handler->display->display_options['filters']['field_glossary_type_tid']['field'] = 'field_glossary_type_tid';
  $handler->display->display_options['filters']['field_glossary_type_tid']['relationship'] = 'field_glossary_type_tid';
  $handler->display->display_options['filters']['field_glossary_type_tid']['value'] = '';
  $handler->display->display_options['filters']['field_glossary_type_tid']['vocabulary'] = 'glossary_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'about-topic/glossary-list';
  $translatables['glossary_list'] = array(
    t('Master'),
    t('Glossary'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Page'),
  );
  $export['glossary_list'] = $view;

  $view = new view();
  $view->name = 'search_term_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Search term content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search term content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Description */
  $handler->display->display_options['fields']['description_field']['id'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['table'] = 'field_data_description_field';
  $handler->display->display_options['fields']['description_field']['field'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['label'] = '';
  $handler->display->display_options['fields']['description_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['description_field']['link_to_entity'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'glossary' => 'glossary',
  );
  /* Filter criterion: Taxonomy term: Description (description_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_description_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: keys_1 */
  $handler->display->display_options['filters']['name_field_value']['id'] = 'name_field_value';
  $handler->display->display_options['filters']['name_field_value']['table'] = 'field_data_name_field';
  $handler->display->display_options['filters']['name_field_value']['field'] = 'name_field_value';
  $handler->display->display_options['filters']['name_field_value']['ui_name'] = 'keys_1';
  $handler->display->display_options['filters']['name_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_field_value']['expose']['operator_id'] = 'name_field_value_op';
  $handler->display->display_options['filters']['name_field_value']['expose']['label'] = 'Search a term:';
  $handler->display->display_options['filters']['name_field_value']['expose']['operator'] = 'name_field_value_op';
  $handler->display->display_options['filters']['name_field_value']['expose']['identifier'] = 'keys-1';
  $handler->display->display_options['filters']['name_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'glossary-search';
  $translatables['search_term_content'] = array(
    t('Master'),
    t('Search term content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Search a term:'),
    t('Page'),
  );
  $export['search_term_content'] = $view;

  return $export;
}
