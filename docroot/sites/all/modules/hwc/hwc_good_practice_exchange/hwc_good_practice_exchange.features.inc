<?php
/**
 * @file
 * hwc_good_practice_exchange.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_good_practice_exchange_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
