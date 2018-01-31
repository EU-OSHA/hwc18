<?php
$ext_type = '';
$items = array();
foreach ($files as $f) {
  foreach($entity->field_document_file['und'] as $delta => $document_file) {
    if ($document_file['fid'] == $f['fid']) {
      $ext_type = strtoupper(pathinfo($f['uri'], PATHINFO_EXTENSION)) . ' ' . $entity->field_file_title['und'][$delta]['value'];
      $file_uri = file_create_url($f['uri']);
      $items[] = '<a href="' . $file_uri . '">' . strtoupper($entity->field_language['und'][$delta]['value']) . '<span class="glyphicon glyphicon-circle-arrow-down"></span></a>';
    }
  }
}
$file_items = theme('item_list', array('items' => $items));

?>
<div class="publication-teaser">
  <div class="field field-files">
      <span class="publication-ext-type"><?php print $ext_type; ?></span>
      <span class="publication-download-label"><?php print t('Download in'); ?></span>
      <?php print $file_items; ?>
  </div>
</div>
