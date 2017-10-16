<?php if (!isset($_REQUEST['test'])) { ?>
<script>
jQuery(document).ready(function ($) {
    var options = {
        $AutoPlay: false,
        $AutoPlaySteps: 1,
        $SlideDuration: 160,
    //    $SlideWidth: 800,
        $SlideHeight: 230,
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
    new $JssorSlider$("publications_slideshow", options);
});
</script>
<div id="publications_slideshow">
    <div id="num_slides" data-u="slides" style="">
      <?php print $rows ?>
    </div>
    <div data-u="navigator" class="jssorb03">
        <div class="prototype" data-u="prototype"></div>
    </div>
    <span data-u="arrowleft" class="jssora03l publications"></span>
    <span data-u="arrowright" class="jssora03r publications"></span>
</div>
<?php
}
else { ?>
<div id="publications_slideshow" class="carousel slide" data-ride="carousel">
    <!-- Indicators -->
    <ol class="carousel-indicators jssorb03"><?php
      $total = osha_publication_result_count();
      $class = "active";
      for ($i = 0; $i < $total; $i++) {
        echo '<li data-target="#publications_slideshow" data-slide-to="' . $i . '" class="' . $class . '"></li>';
        $class = '';
      }
      ?>
    </ol>

    <!-- Wrapper for slides -->
    <div class="carousel-inner" id="num_slides">
      <?php print str_replace('row-1', 'row-1 active', $rows); ?>
    </div>

    <!-- Left and right controls -->
    <a class="jssora03l left carousel-control" href="#publications_slideshow" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left"></span>
        <span class="sr-only"><?php echo t('Previous'); ?></span>
    </a>
    <a class="jssora03r right carousel-control" href="#publications_slideshow" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right"></span>
        <span class="sr-only"><?php echo t('Next'); ?></span>
    </a>
</div>
<?php
}
