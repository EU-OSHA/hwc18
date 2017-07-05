<?php
/**
 * @file
 * hwc_good_practice_exchange.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_good_practice_exchange_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'good_practice_exchange';
  $page->task = 'page';
  $page->admin_title = 'good-practice-exchange';
  $page->admin_description = '';
  $page->path = 'good-practice-exchange';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_good_practice_exchange__panel';
  $handler->task = 'page';
  $handler->subtask = 'good_practice_exchange';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Content',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '3298',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cdcf5b90-805d-4c6a-a708-1df9daf95edc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_good_practice_exchange__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-dd5c67fd-91b6-4951-bcbc-12dcdb862549';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_image';
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
    'context' => 'context_entity:node_1',
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
  $pane->uuid = 'dd5c67fd-91b6-4951-bcbc-12dcdb862549';
  $display->content['new-dd5c67fd-91b6-4951-bcbc-12dcdb862549'] = $pane;
  $display->panels['center'][0] = 'new-dd5c67fd-91b6-4951-bcbc-12dcdb862549';
  $pane = new stdClass();
  $pane->pid = 'new-a6d5b7cb-a0a7-4f7d-adcb-e590bfab2a00';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
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
    ),
    'context' => 'context_entity:node_1',
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
  $pane->uuid = 'a6d5b7cb-a0a7-4f7d-adcb-e590bfab2a00';
  $display->content['new-a6d5b7cb-a0a7-4f7d-adcb-e590bfab2a00'] = $pane;
  $display->panels['center'][1] = 'new-a6d5b7cb-a0a7-4f7d-adcb-e590bfab2a00';
  $pane = new stdClass();
  $pane->pid = 'new-1260ea2d-bda5-483e-9a3a-c9ee0a9ce3b6';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
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
      'summary_handler' => 'full',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'context_entity:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1260ea2d-bda5-483e-9a3a-c9ee0a9ce3b6';
  $display->content['new-1260ea2d-bda5-483e-9a3a-c9ee0a9ce3b6'] = $pane;
  $display->panels['center'][2] = 'new-1260ea2d-bda5-483e-9a3a-c9ee0a9ce3b6';
  $pane = new stdClass();
  $pane->pid = 'new-449d8322-01ee-428a-83b1-c327dc4999a7';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '449d8322-01ee-428a-83b1-c327dc4999a7';
  $display->content['new-449d8322-01ee-428a-83b1-c327dc4999a7'] = $pane;
  $display->panels['center'][3] = 'new-449d8322-01ee-428a-83b1-c327dc4999a7';
  $pane = new stdClass();
  $pane->pid = 'new-f5eb3bc8-1368-408a-88d4-ed34819ac917';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_good_practice_exchange-gpe_links';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'f5eb3bc8-1368-408a-88d4-ed34819ac917';
  $display->content['new-f5eb3bc8-1368-408a-88d4-ed34819ac917'] = $pane;
  $display->panels['center'][4] = 'new-f5eb3bc8-1368-408a-88d4-ed34819ac917';
  $pane = new stdClass();
  $pane->pid = 'new-b202e51f-96bb-4bbc-872f-3118418b7a07';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_good_practice_exchange-gpe_tools_publications';
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
  $pane->uuid = 'b202e51f-96bb-4bbc-872f-3118418b7a07';
  $display->content['new-b202e51f-96bb-4bbc-872f-3118418b7a07'] = $pane;
  $display->panels['center'][5] = 'new-b202e51f-96bb-4bbc-872f-3118418b7a07';
  $pane = new stdClass();
  $pane->pid = 'new-87eb0c94-bce5-4fa0-a9f5-ba2b63ee9952';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'osha_newsletter-osha_newsletter_image';
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
  $pane->uuid = '87eb0c94-bce5-4fa0-a9f5-ba2b63ee9952';
  $display->content['new-87eb0c94-bce5-4fa0-a9f5-ba2b63ee9952'] = $pane;
  $display->panels['center'][6] = 'new-87eb0c94-bce5-4fa0-a9f5-ba2b63ee9952';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['good_practice_exchange'] = $page;

  return $pages;

}
