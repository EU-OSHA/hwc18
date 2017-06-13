<?php print render($title_prefix); ?>
<?php if ($title): ?>
  <?php print $title; ?>
<?php endif; ?>
<?php print render($title_suffix); ?>
<?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
<?php endif; ?>

<?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
<?php endif; ?>

<?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
<?php endif; ?>

<script>
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
  new $JssorSlider$("napo_films", options);
});
</script>
<div id="napo_films" class="napo_films">
    <div class="num_slides" data-u="slides">
      <?php print $rows; ?>
    </div>
    <div data-u="navigator" class="jssorb03">
        <div class="prototype" data-u="prototype"></div>
    </div>	
    <span data-u="arrowleft" class="jssora03l publications"></span>
    <span data-u="arrowright" class="jssora03r publications"></span>
</div>

<?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
<?php endif; ?>

<?php if ($more): ?>
  <?php print $more; ?>
<?php endif; ?>

<?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
<?php endif; ?>
