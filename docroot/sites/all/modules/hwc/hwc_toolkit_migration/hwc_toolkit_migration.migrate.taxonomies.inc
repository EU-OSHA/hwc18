<?php
class HWCTaxonomyToolsAndExamplesMigration extends AbstractNCWTaxonomyTermMigration {

  public function getMigrationURL() {
    $root = variable_get('hwc_tk_migration_root_url', '');
    $variable = variable_get('hwc_tk_migration_' . $this->getMachineName() . '_url');
    if (isset($_REQUEST['debug'])) {
      drupal_set_message($this->getMachineName() . " = " . $root . $variable);
    }
    return $root . $variable;
  }

  public function __construct($arguments) {
    parent::__construct($arguments, 'ToolsAndExamplesHWCTaxonomyTermSource', 'tools_and_examples');
    $this->description = 'Sync taxonomy "tools and examples" from HWC';
  }

  public function computeCount() {
    ncw_migration_debug('!klass: Starting counting !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    if ($this->count == -1) {
      $data = $this->fileGetContents($this->endpoint_url);
      $this->count = 0;
      if ($data = json_decode($data)) {
        if (!empty($data->items)) {
          $data = $data->items;
          foreach ($data as $ob) {
            $ob = $ob->item;
            $id = $this->itemIdentifier($ob);
            if (!in_array($id, $this->skip_ids)) {
              $this->count++;
            }
          }
        }
      }
    }
    ncw_migration_debug('!klass: Found !count items', array('!klass' => get_class($this), '!count' => $this->count));
    return $this->count;
  }

}

class ToolsAndExamplesHWCTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  function hwc_tk_migration_datasource_url() {
    $ret = NULL;
    static $errorDisplayed = FALSE;
    $ret = variable_get('hwc_tk_migration_root_url');
    if (empty($ret)) {
      $ret = 'http://hwc.localhost';
      if (!$errorDisplayed) {
        $errorDisplayed = TRUE;
        drupal_set_message("Empty 'hwc_tk_migration_root_url' variable. Using default 'http://hwc.localhost'", 'warning');
      }
    }
    return $ret;
  }

  public function itemURL($id) {
    return $this->hwc_tk_migration_datasource_url() . 'export/taxonomy_term/' . $id;
  }

  public function contentFields() {
    return array();
  }

}
