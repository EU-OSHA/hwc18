<?php
/**
 * @file
 * Stub file for bootstrap_menu_local_tasks().
 */

/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @param array $variables
 *   An associative array containing:
 *     - primary: (optional) An array of local tasks (tabs).
 *     - secondary: (optional) An array of local tasks (tabs).
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_menu_local_tasks()
 * @see menu_local_tasks()
 *
 * @ingroup theme_functions
 */
function bootstrap_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<div class="element-invisible">' . t('Primary tabs') . '</div>';
    $variables['primary']['#prefix'] .= '<ul class="tabs--primary nav nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<div class="element-invisible">' . t('Secondary tabs') . '</div>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}
