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

    jQuery(document).ready(function ($) {
        var options = {
            $AutoPlay: false,
            $AutoPlaySteps: 1,
            $SlideDuration: 160,
//    $SlideWidth: 800,
            $SlideHeight: 625,
            $SlideSpacing: 1,
            $DisplayPieces: 1,
            $HWA: false,
            $BulletNavigatorOptions: {
                $Class: $JssorBulletNavigator$,
                $ChanceToShow: 1,
                $AutoCenter: 1
            },
            $ArrowNavigatorOptions: {
                $Class: $JssorArrowNavigator$,
                $ChanceToShow: 1,
                $AutoCenter: 2,
                $Steps: 1
            }
        };
        new $JssorSlider$("latest_tweets", options);
    });
</script>
<div id="latest_tweets" class="latest_tweets">
    <div id="num_slides" data-u="slides" style="">
      <?php
      foreach ($items as $title => $rows) {
        foreach ($rows as $i=>$row) {
          foreach ($row['content'] as $column) {
            print '<div>' . $column['content'] . '</div>';
          }
        }
      }
      ?>
    </div>
    <div data-u="navigator" class="jssorb03">
        <div class="prototype" data-u="prototype"></div>
    </div>
    <span data-u="arrowleft" class="jssora03l publications"></span>
    <span data-u="arrowright" class="jssora03r publications"></span>
</div>
