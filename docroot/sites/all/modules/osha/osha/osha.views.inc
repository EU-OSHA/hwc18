<?php

/**
 * Alter the view tmgmt_node_selection_view to show latest node state.
 *
 * Alter LEFT JOIN node_revision ON node.vid = node_revision.vid
 * to LEFT JOIN node_revision ON node.nid = node_revision.nid
 */
function osha_views_query_alter(&$view, &$query) {
  if ($view->name == 'event_schedule_rev') {
    $node = menu_get_object();
    if ($node) {
      $revision_ids = [];
      foreach ($node->field_schedule[LANGUAGE_NONE] as $schedule) {
        $revision_ids[] = $schedule['revision_id'];
      }
      if ($revision_ids) {
        $query->where[0]['conditions'][0]['field'] = 'field_collection_item_revision.revision_id';
        $query->where[0]['conditions'][0]['operator'] = 'in';
        $query->where[0]['conditions'][0]['value'] = $revision_ids;
      }
    }
  }
  // Switch from JOIN to LEFT JOIN with workbench_moderation_node_history
  // to allow adding content types which are not moderated (i.e. page).
  if ($view->name == 'administration_content') {
    if (isset($query->table_queue['workbench_moderation_node_history']['join']->type)) {
      $query->table_queue['workbench_moderation_node_history']['join']->type = 'LEFT';
    }
    if (isset($query->table_queue['node_revision'])) {
      $query->table_queue['node_revision']['join']->field = 'nid';
      $query->table_queue['node_revision']['join']->left_field = 'nid';
    }
    // Overwrite the view.
    if (in_array('views', arg())) {
      drupal_set_message('Be careful! Overwriting query in osha.views.inc. Changing filters order may affect the view.', 'warning');
    }
    $query->where[2]['conditions'][1]['field'] = 'node.type';
  }
}
