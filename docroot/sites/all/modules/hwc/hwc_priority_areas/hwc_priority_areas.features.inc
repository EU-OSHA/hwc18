<?php
/**
 * @file
 * hwc_priority_areas.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_priority_areas_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_priority_areas_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
