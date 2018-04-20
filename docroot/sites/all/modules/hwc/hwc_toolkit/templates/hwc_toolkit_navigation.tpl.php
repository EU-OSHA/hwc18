<?php

$prev = hwc_toolkit_nav_prev($nid);
$next = hwc_toolkit_nav_next($nid);
if ($prev || $next) {
  print '<div class="col-xs-12 col-sm-12 col-md-9">';
  print '<div class="key-next-prev-buttons">';
  if ($prev) {
    print '<span class="prev-button"><a href="' . $prev['href'] . '" class="previous-button">' . t('Prev topic') . ' ' . $prev['title'] . '</a></span>';
  }
  if ($next) {
    print '<span class="next-button"><a href="' . $next['href'] . '" class="nexting-button">' . t('Next topic') . ' ' . $next['title'] . '</a></span>';
  }
  print '</div>';
  print '</div>';
}
