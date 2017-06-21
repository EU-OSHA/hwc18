<?php

define('CASE_STUDY_TID', 521);

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_menu_publications_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_menu_case_studies_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_publications_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_case_studies_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

function osha_publication_menu_publications_form($form, $form_state) {
  $variables['form_state'] = $form_state;
  $variables['action'] = 'publications';
  $variables['facet_callback'] = '_osha_publication_menu_publications_get_facets_def';
  $variables['search_callback'] = 'osha_publication_menu_publications_search';

  return osha_publication_menu_publications_faceted_form($variables);
}

function osha_publication_menu_publications_faceted_form($variables) {
  $form_state = $variables['form_state'];
  $action = $variables['action'];
  $facet_callback = $variables['facet_callback'];
  $search_callback = $variables['search_callback'];

  drupal_set_title(t('Publications'));
  $text = hwc_req_param($form_state, 'text');
  $form = array(
    '#action' => $action,
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-3'))
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-9')),
    )
  );
  $form['left-column']['search']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search')),
    '#prefix' => '<div id="search">',
  );
  $form['left-column']['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );

  $form['#token'] = FALSE;
  $form['content']['slideshow'] = array(
    '#type' => 'markup',
    '#markup' => views_embed_view('publications_slideshow', 'slidehow'),
  );
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/form.js'
  );
  if (!empty($text)) {
    $form['content']['search_phrase'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="results-for">' . t('Results for !text', array('!text' => '<span class="searched-text">' . check_plain($text) .'</span>')) . '</div>',
    );
  }

  $facets_def = call_user_func($facet_callback);

  $response = call_user_func($search_callback, $form_state);

  $form['content']['results-native'] = osha_publication_menu_publications_native_results($form_state, $response);

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _osha_publication_facet_value_clear($facets);
  }

  $query_params = drupal_get_query_parameters();

  foreach ($facets_def as $field_name => $facet_def) {
    if (!empty($facets[$field_name])) {
      $values_list = call_user_func($facet_def['options_callback'], $facet_def['options_callback_args']);
      $options = array();
      foreach ($facets[$field_name] as $facet_value) {
        if (!empty($values_list[$facet_value['filter']])) {
          if ($facet_value['filter'] == CASE_STUDY_TID) {
            continue;
          }
          $options[$facet_value['filter']] = $values_list[$facet_value['filter']];// . ' ' . strtr('(@no)', array('@no' => $facet_value['count']));
          $form['left-column'][$field_name] = array(
            '#type' => 'checkboxes',
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, array()),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array('search-facet-field')),
          );
        }
      }

      if (!empty($form['left-column'][$field_name]['#default_value'])) {
        foreach ($form['left-column'][$field_name]['#default_value'] as $val) {
          if (!empty($options[$val])) {
            $filter_label = '<span class="glyphicon glyphicon-remove"></span>' . $options[$val];
            $query = _osha_publication_strip_param_value($query_params, $field_name, $val) ?: ['text' => ''];
            $form['left-column']['search']['filters'][] = array(
              '#type' => 'markup',
              '#markup' => l($filter_label, $action, array('query' => $query, 'html' => TRUE)),
            );
          }
        }
      }
    }
  }

  if (!empty($query_params)) {
    // Clear filter link
    // it's really just a link to current url without params.
    $form['left-column']['link'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="clear_filters">' . l(t('Clear filters'), current_path()) . '</div>',
    );
  }

  $native_nids = $form['content']['results-native']['#nids'];
  $form['content']['results-related'] = osha_publication_menu_publications_search_related($form_state, $native_nids);
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
    $form['content']['results-related'] = $form_state['#results-related'];
  }
  if (empty($form['content']['results-native']['#nids'])) {
    $form['content']['results-native']['#markup'] = '<p class="no-results">' . t('No results found to match your search.') . '</p>';
  }

  return $form;
}

function osha_publication_menu_publications_search($form_state) {
  $facets_def = _osha_publication_menu_publications_get_facets_def();
  $text = hwc_req_param($form_state, 'text');

  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _osha_publication_get_query();

  $query->condition('status', 1);
  $query->condition('type', 'publication');
  $query->condition('field_file:file', 0, '>');
  $query->condition('field_publication_type', CASE_STUDY_TID, "<>");
  $query->keys($text);
  $query->fields(array('title_field', 'body:value'));

  $query->setOption('search_api_facets', $facets_def);
  foreach ($facets_def as $field_name => $facet_def) {
    $selected_values = hwc_req_param($form_state, $field_name, array());
    if (!empty($selected_values) && is_array($selected_values)) {
      $filter = $query->createFilter($facet_def['operator'], ['facet:' . $field_name]);
      foreach ($selected_values as $value) {
        $filter->condition($field_name, $value);
        $query->filter($filter);
      }
    }
  }
  return $server->search($query);
}

function osha_publication_menu_publications_native_results($form_state, $results) {
  global $language;
  $restrict = [];
  if (!empty($results['results'])) {
    foreach ($results['results'] as $result) {
      list($lng, $nid) = explode('_', $result['id'], 2);
      $restrict[] = $nid;
    }
  }
  if (empty($restrict)) {
    return array(
      '#nids' => '',
    );
  }
  $languages = hwc_req_param($form_state, 'language', array($language->language));

  $nids = [];
  foreach($restrict as $pnid) {
    $q = db_select('field_data_field_file', 'b');
    $q->fields('b', array('entity_id'));
    $q->innerJoin('node', 'a', 'a.nid = b.entity_id AND a.vid = b.revision_id');
    $q->condition('b.bundle', 'publication');
    $q->condition('b.entity_id', $pnid);
    $q->condition('b.language', $languages, 'IN');
    $c = $q->countQuery()->execute()->fetchField();
    if ($c >= count($languages)) {
      $nids[] = $pnid;
    }
  }
  $nids = array_unique($nids);
  if (empty($nids)) {
    return array();
  }

  //Order publications by publication_date
  $q = db_select('field_data_field_publication_date', 'a');
  $q->fields('a', array('entity_id'));
  $q->condition('entity_id', $nids, 'IN');
  $q->orderBy('field_publication_date_value', 'DESC');
  $nids = $q->execute()->fetchCol();

  $per_page = 4;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $pager_params = array('languages' => $languages);
  $text = hwc_req_param($form_state, 'text');
  $is_search = !empty($text);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  $ret = array(
    '#nids' => $nids,
    '#prefix' => '<h2 class="h4-title">' . t('Publications available') . '</h2>',
    'results-native' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
    ))
  );
  return $ret;
}

function osha_publication_menu_publications_search_related($form_state, $native_nids) {
  global $language;
  $ret = array();
  $languages = hwc_req_param($form_state, 'language', array($language->language));
  if(!empty($languages)) {
    if (in_array('en', $languages)) {
      return $ret;
    }
  }
  else {
    if($language->language == 'en') {
      return $ret;
    }
  }
  $text = hwc_req_param($form_state, 'text');
  $relevant_for = hwc_req_param($form_state, 'relevant_for', array());
  $publication_type = hwc_req_param($form_state, 'publication_type', array());
  $is_search = !empty($text);

  // Select all publications having field_file available in filtered languages.
  $q = db_select('node', 'a');
  $q->innerJoin('field_data_field_publication_type', 'b', 'a.nid = b.entity_id');
  $q->leftJoin('field_data_field_publication_date', 'pd', 'a.nid = pd.entity_id');
  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'publication');
  $q->condition('a.status', 1);
  $q->condition('b.field_publication_type_tid', CASE_STUDY_TID, '!=');
  $q->orderBy('pd.field_publication_date_value', 'DESC');
  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }
  if (!empty($publication_type)) {
    $q->condition('b.field_publication_type_tid', $publication_type, 'IN');
  }
  if (!empty($relevant_for)) {
    $q->innerJoin('field_data_field_priority_area', 'fs', 'fs.entity_id = a.nid AND fs.revision_id = a.vid');
    $q->condition('fs.field_priority_area_tid', $relevant_for, 'IN');
  }
  $nids = $q->execute()->fetchCol();
  if (!empty($native_nids)) { // Remove the nodes displayed above (native)
    $nids = array_filter($nids, function($nid) use ($native_nids) {
      return !in_array($nid, $native_nids);
    });
  }
  if (empty($nids)) {
    return array();
  }
  $per_page = 3;
  $current_page = pager_default_initialize(count($nids), $per_page, 1);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $languages = hwc_req_param($form_state, 'language', array($language->language));
  $pager_params = array('languages' => $languages);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  $ret = array(
    '#prefix' => '<h4>' . t('Other relevant publications in English') . '</h4>',
    'results-related' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
      'element' => 1,
    ))
  );
  return $ret;
}

function osha_publication_menu_case_studies_form($form, $form_state) {
  $variables['form_state'] = $form_state;
  $variables['action'] = 'case-studies';
  $variables['facet_callback'] = '_osha_publication_menu_case_studies_get_facets_def';
  $variables['search_callback'] = 'osha_publication_menu_case_studies_search';
  return osha_publication_menu_case_studies_faceted_form($variables);
}

function osha_publication_menu_case_studies_search($form_state) {
  $facets_def = _osha_publication_menu_case_studies_get_facets_def();
  $text = hwc_req_param($form_state, 'text');

  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _osha_publication_get_query();

  $query->condition('status', 1);
  $query->condition('type', 'publication');
  $query->condition('field_file:file', 0, '>');
  $query->condition('field_publication_type', CASE_STUDY_TID);
  $query->keys($text);
  $query->fields(array('title_field', 'body:value'));
  $query->sort('field_publication_date', 'DESC');

  $query->setOption('search_api_facets', $facets_def);
  foreach ($facets_def as $field_name => $facet_def) {
    $selected_values = hwc_req_param($form_state, $field_name, array());
    if (!empty($selected_values) && is_array($selected_values)) {
      $filter = $query->createFilter($facet_def['operator'], ['facet:' . $field_name]);
      foreach ($selected_values as $value) {
        $filter->condition($field_name, $value);
        $query->filter($filter);
      }
    }
  }
  return $server->search($query);
}

function osha_publication_menu_case_studies_faceted_form($variables) {
  global $language;

  $form_state = $variables['form_state'];
  $action = $variables['action'];
  $facet_callback = $variables['facet_callback'];
  $search_callback = $variables['search_callback'];

  drupal_set_title(t('Publications'));
  $text = hwc_req_param($form_state, 'text');
  $form = array(
    '#action' => $action,
    '#method' => 'GET',
    '#token' => FALSE,
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-3'))
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-9')),
    )
  );
  $form['left-column']['search']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search Case studies')),
    '#prefix' => '<div id="search">',
  );
  $form['left-column']['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/form.js',
  );

  $facets_def = call_user_func($facet_callback);

  $response = call_user_func($search_callback, $form_state);

  $languages = hwc_req_param($form_state, 'languages', array($language->language));

  $restrict = array();
  if (!empty($response['results'])) {
    foreach ($response['results'] as $result) {
      list($lng, $nid) = explode('_', $result['id'], 2);
      $restrict[] = $nid;
    }
  }
  $nids = array_unique($restrict);
  $form['content']['results-native'] = array(
    '#nids' => '',
  );
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
  }

  $per_page = 5;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  if ($nodes) {
    foreach($nodes as $node) {
      $node->filter_languages = $languages;
    }
    $pager_params = array('languages' => $languages);
    if (!empty($text)) {
      $pager_params['text'] = $text;
    }
    $form['content']['results-native'] = array(
      '#nids' => $nids,
      'results-native' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
      '#suffix' => theme('pager', array(
        'tags' => array('<', '<', '', '>', '>'),
        'quantity' => 9,
        'parameters' => $pager_params,
      ))
    );
  }
  if (empty($form['content']['results-native']['#nids'])) {
    $form['content']['results-native']['#markup'] = '<p class="no-results">' . t('No results found to match your search.') . '</p>';
  }

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _osha_publication_facet_value_clear($facets);
  }

  $query_params = drupal_get_query_parameters();

  foreach ($facets_def as $field_name => $facet_def) {
    if (!empty($facets[$field_name])) {
      $values_list = call_user_func($facet_def['options_callback'], $facet_def['options_callback_args']);
      $options = array();
      foreach ($facets[$field_name] as $facet_value) {
        if (!empty($values_list[$facet_value['filter']])) {
          if ($facet_value['filter'] == CASE_STUDY_TID) {
            continue;
          }
          $options[$facet_value['filter']] = $values_list[$facet_value['filter']]; // . ' ' . strtr('(@no)', array('@no' => $facet_value['count']));
          $form['left-column'][$field_name] = array(
            '#type' => 'checkboxes',
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, array()),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array('search-facet-field')),
          );
        }
      }

      if (!empty($form['left-column'][$field_name]['#default_value'])) {
        foreach ($form['left-column'][$field_name]['#default_value'] as $val) {
          if (!empty($options[$val])) {
            $filter_label = '<span class="glyphicon glyphicon-remove"></span>' . $options[$val];
            $query = _osha_publication_strip_param_value($query_params, $field_name, $val) ?: ['text' => ''];
            $form['left-column']['search']['filters'][] = array(
              '#type' => 'markup',
              '#markup' => l($filter_label, $action, array('query' => $query, 'html' => TRUE)),
            );
          }
        }
      }
    }
  }

  if (!empty($query_params)) {
    // Clear filter link
    // it's really just a link to current url without params.
    $form['left-column']['link'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="clear_filters">' . l(t('Clear filters'), current_path()) . '</div>',
    );
  }
  return $form;
}

function _osha_publication_menu_case_studies_get_facets_def() {
  return array(
    'language' => array(
      'label' => t('Language'),
      'field' => 'language',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_language_list_options',
      'options_callback_args' => array(TRUE, TRUE),
    ),
    'field_priority_area' => array(
      'label' => t('Topics'),
      'field' => 'field_priority_area',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_taxonomy_filter_options_list',
      'options_callback_args' => array('priority_area'),
    ),
  );
}

function _osha_publication_menu_publications_get_facets_def() {
  return array(
    'field_publication_type' => array(
      'label' => t('Publications type'),
      'field' => 'field_publication_type',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_taxonomy_filter_options_list',
      'options_callback_args' => array('publication_types'),
    ),
    'language' => array(
      'label' => t('Language'),
      'field' => 'language',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_language_list_options',
      'options_callback_args' => array(TRUE, TRUE),
    ),
    'field_priority_area' => array(
      'label' => t('Topics'),
      'field' => 'field_priority_area',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_taxonomy_filter_options_list',
      'options_callback_args' => array('priority_area'),
    ),
  );
}

function _osha_publication_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load(SOLR_SEARCH_INDEX);
  $query = new SearchApiQuery($index);
  $query->fields(array()); // Avoid PHP notice
  $solr = new SearchApiSolrService($server);
  return array($solr, $query);
}

function _osha_publication_language_list_options($prefix = TRUE, $native = TRUE) {
  // used by hwc_practical_tool_get_facets_def and _oira_promotional_material_search_form_get_facets
  // for tools and promotional materials we don't exclude Catalan
  $disabled = osha_disabled_language_list();
  unset($disabled['ca']);
  $languages = osha_language_list_options($native, TRUE, $disabled);
  if ($prefix) {
    foreach ($languages as $lang_code => $value) {
      $languages[$lang_code] = strtoupper($lang_code) . ' - ' . $value;
    }
  }
  return $languages;
}

function _osha_publication_taxonomy_filter_options_list($vocabulary, $default = array()) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  if (!empty($vocabulary)) {
    $terms = taxonomy_term_load_multiple(array(), array('vid' => $vocabulary->vid));
    foreach($terms as $key => $term) {
      $default[$term->tid] = $term->name;
    }
  }
  return $default;
}

function _osha_publication_facet_value_clear(&$facets) {
  if (!empty($facets)) {
    foreach ($facets as &$facet_field) {
      foreach ($facet_field as &$facet_value) {
        // The filters come wrapped in ".
        $facet_value['filter'] = trim($facet_value['filter'], '"');
      }
    }
  }
}

function _osha_publication_strip_param_value($params, $name, $value = NULL) {
  if (!empty($params[$name])) {
    if (!is_array($params[$name])) {
      unset($params[$name]);
    }
    else {
      $flipped = array_flip($params[$name]);
      if (array_key_exists($value, $flipped)) {
        unset($params[$name][$flipped[$value]]);
        if (empty($params[$name])) {
          unset($params[$name]);
        }
      }
    }
  }
  return $params;
}

