<?php

/**
 * @file
 * Xmlsitemap Bulk link exclude form operations inc.
 */

/**
 * Manual link entry form, where user will enter the exclude urls in new line.
 */
function xml_sitemap_bulk_link_exclude_form($form, &$form_state) {

  $form['xml_sitemap_bulk_link_exclude_array'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the sitemap links to be excluded.'),
    '#description' => t('Please enter each xml sitemap link to be excluded in newline.<br> Example:<br> taxonomy/term/123<br>node/123'),
    '#default_value' => variable_get('xml_sitemap_bulk_link_exclude_array', ''),
    '#size' => 30,
  );

  // Set a submit handler manually because the default submit handler
  // gets overridden by the system_settings_form() submit handler.
  $form['#submit'][] = 'xml_sitemap_bulk_link_exclude_form_submit';

  return system_settings_form($form);
}

/**
 * Textbox form validation.
 */
function xml_sitemap_bulk_link_exclude_form_validate($form, &$form_state) {
  $link_text = isset($form_state['values']['xml_sitemap_bulk_link_exclude_array']) ? $form_state['values']['xml_sitemap_bulk_link_exclude_array'] : '';
  if (!empty($link_text)) {
    $get_exclude_array = xml_sitemap_bulk_link_exclude_get_exclude_links($link_text);
    foreach ($get_exclude_array as $key => $value) {
      if (isset($get_exclude_array[$key]) && strpos($value, '/') !== FALSE) {
        $url_validate = explode("/", $value);
        if (($url_validate[0] == "node" && !is_numeric($url_validate[1])) || ($url_validate[0] != "node" && $url_validate[0] != "taxonomy") || ($url_validate[0] == "taxonomy" && ($url_validate[1] != "term" || !is_numeric($url_validate[2])))) {
          form_set_error('form_description', t('Invalid input. Please provide valid links.'));
        }
      }
      else {
        form_set_error('form_description', t('Invalid input. Please provide valid links.'));
      }
    }
    $form_state['values']['xml_sitemap_bulk_link_exclude_array'] = $get_exclude_array;
  }
  else {
    form_set_error('form_description', t("There are no links entered to exclude."));
  }
}

/**
 * Manual sitemap link entry textbox Submit function.
 */
function xml_sitemap_bulk_link_exclude_form_submit($form, &$form_state) {
  $exclude_values = isset($form_state['values']['xml_sitemap_bulk_link_exclude_array']) ? $form_state['values']['xml_sitemap_bulk_link_exclude_array'] : '';
  $column_index = "loc";
  if (!empty($exclude_values)) {
    foreach ($exclude_values as $key => $value) {
      if (isset($exclude_values[$key])) {
        $fields = array('status' => 0, 'status_override' => 1);
        $conditions[$column_index] = $value;
        // Xmlsitemap module function is invoked here.
        xmlsitemap_link_update_multiple($fields, $conditions);
      }
    }
  }
  else {
    drupal_set_message(t("There are no links entered to exclude."));
  }
}

/**
 * Function to convert new line urls into array of urls.
 */
function xml_sitemap_bulk_link_exclude_get_exclude_links($link_text) {
  $arrayList = preg_split("/\\r\\n|\\r|\\n/", $link_text);
  return $arrayList;
}

/**
 * Sitemap URL table values.
 */
function xml_sitemap_bulk_link_exclude_table_list() {
  global $base_url;
  $data = array();
  $link_type = "custom";
  $query = db_query('SELECT x.loc, x.type, x.status, x.status_override
  FROM {xmlsitemap} x WHERE x.status = :status AND x.type <> :type', array(':status' => 1, ':type' => $link_type));
  $row = $query->fetchAll();
  foreach ($row as $record => $values) {
    if (isset($row[$record]) && $values->type !== "frontpage") {
      $path_alias_value = drupal_get_path_alias($values->loc);
      $path_alias_value = $base_url . "/" . $path_alias_value;
      $data[$values->loc] = array(
        $path_alias_value,
        $values->type,
        $values->status,
        $values->status_override,
      );
    }
  }
  return $data;
}

/**
 * XML table form creation.
 */
function xml_sitemap_bulk_link_exclude_table_form($form, $form_state) {
  $options = array();
  $options = xml_sitemap_bulk_link_exclude_table_list();

  $header = array('URL', 'type', 'status', 'status_override');
  $form['form_description'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose XML URLs from below table, which has to be removed from Sitemap.'),
    '#description' => t('Choose the URLs and submit.'),
  );

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No links found.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Checkbox form validation.
 */
function xml_sitemap_bulk_link_exclude_table_form_validate($form, &$form_state) {
  $check_val = isset($form_state['values']['table']) ? $form_state['values']['table'] : '';
  if (is_array($check_val) && !empty($check_val)) {
    foreach ($check_val as $key => $value) {
      if ($value == "0" || $value == '') {
        unset($check_val[$key]);
      }
    }
    if (empty($check_val)) {
      form_set_error('form_description', t('Choose some URLs to exclude before submitting.'));
    }
    else {
      $form_state['values']['table'] = $check_val;
    }
  }
}

/**
 * XML table form submit.
 */
function xml_sitemap_bulk_link_exclude_table_form_submit($form, &$form_state) {
  $check_val = isset($form_state['values']['table']) ? $form_state['values']['table'] : '';
  $column_index = "loc";
  if ($check_val !== '') {
    $fields = array('status' => 0, 'status_override' => 1);
    foreach ($check_val as $key => $value) {
      if (!is_null($check_val[$key]) || $check_val[$key] !== '') {
        $conditions[$column_index] = $value;
        // Xmlsitemap module function is invoked here.
        xmlsitemap_link_update_multiple($fields, $conditions);
      }
    }
    drupal_set_message(t('Selected xml links has been successfully removed from xml sitemap!. Please regenerate
    the sitemap to see the changes.'));
  }
}
