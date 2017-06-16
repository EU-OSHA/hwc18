<?php
/**
 * @file social-dashboard-column-plugin-style.tpl.php
 * Default simple view template to display Socail Dashboard Columns.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
?>
<script>window.twttr = (function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0],
            t = window.twttr || {};
        if (d.getElementById(id)) return t;
        js = d.createElement(s);
        js.id = id;
        js.src = "https://platform.twitter.com/widgets.js";
        fjs.parentNode.insertBefore(js, fjs);

        t._e = [];
        t.ready = function(f) {
            t._e.push(f);
        };

        return t;
    }(document, "script", "twitter-wjs"));
</script>
<?php
$slide_items = "";
$indicators = "";
foreach ($items as $title => $rows) {
  foreach ($rows as $i=>$row) {
    foreach ($row['content'] as $column) {
      $class = "item";
      $indicator_class = "";
      if (!$i) {
        $class .= " active";
        $indicator_class = "active";
      }
      $slide_to = $i;
      $indicators .= '<li data-target="#latest_tweets" data-slide-to="' . $slide_to . '" class="' . $indicator_class . '"></li>';
      $slide_items .= '<div class="' . $class . '">' . $column['content'] . '</div>';
    }
  }
}
?>
<div id="latest_tweets" class="carousel slide" data-ride="carousel" data-interval="">
    <ol class="carousel-indicators"><?php echo $indicators; ?></ol>
    <div class="carousel-inner" role="listbox"><?php echo $slide_items; ?></div>
    <a class="left carousel-control" href="#latest_tweets" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
    </a>
    <a class="right carousel-control" href="#latest_tweets" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
    </a>
</div>
