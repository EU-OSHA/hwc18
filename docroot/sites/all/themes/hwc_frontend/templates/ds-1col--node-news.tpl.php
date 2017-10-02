<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
<?php if (!empty($content['submit_content_form'])): ?>
  <div class="node-submit-validation-form">
    <?php print drupal_render($content['submit_content_form']); ?>
  </div>
<?php endif; ?>

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<?php print $ds_content; ?>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
<?php
if (!empty($elements['node_share_popup'])) {
    print render($elements['node_share_popup']);
?>
<style>
    #share-popup-container {
        position: fixed;
        left: 0;
        top: 0;
        width: 100%;
        height: 100%;
        background-color: rgba(0,0,0,0.7);
        z-index: 1000000;
    }
    #share-popup-container .close-share-popup-container {
        position: fixed;
        top: 20px;
        right: 20px;
    }
    #share-popup-container .close-share-popup-container button.close-share-popup {
        background: #fff;
        border-radius: 100%;
        border: none;
        padding: 0;
    }
    #share-popup-container .close-share-popup-container .close-share-popup span {
        display: block;
        width: 30px;
        height: 30px;
        line-height: 25px;
        font-size: 24px;
    }
    #share-popup-container .share-popup-title {
        text-align: center;
        margin-top: 20%;
        color: #fff;
    }
    #share-popup-container .share-popup-title h3 {
        font-size: 3em;
        margin: 0;
    }
    #share-popup-container .share-popup-title h4 {
        font-size: 2em;
        margin-top: 1em;
        color: #fff;
    }
    #share-popup-container .share-widget-container {
        width: 100%;
        text-align: center;
    }
    #share-popup-container .osha-share-widget ul {
        list-style: none;
        padding: 0;
    }
    #share-popup-container .osha-share-widget li {
        vertical-align: middle;
        display: inline-block;
        padding: 0 4px;
    }
    #share-popup-container .osha-share-widget li.osha-share-widget-button {
        width: 20px;
        height: 20px;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-button {
        width: 70px;
        height: 70px;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-button a {
        width: 60px;
        height: 60px;
        margin: 5px;
        background-size: 100% 100%!important;
        background-repeat: no-repeat!important;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-button a:hover {
        width: 70px;
        height: 70px;
        margin: 0;
        transition: all 0.2s ease;
    }
    #share-popup-container .osha-share-widget li.osha-share-widget-button a {
        display: inline-block;
        text-indent: 100%;
        white-space: nowrap;
        overflow: hidden;
        width: 20px;
        height: 20px;
        background: #eee;
        color: transparent !important;
        border: 0 !important;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-facebook a {
        background-image: url(/sites/all/themes/hwc_frontend/images/share-popup/facebook.png) !important;
        background-color: rgba(0, 0, 0, 0) !important;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-twitter a {
        background-image: url(/sites/all/themes/hwc_frontend/images/share-popup/twitter.png) !important;
        background-color: rgba(0, 0, 0, 0) !important;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-linkedin a {
        background-image: url(/sites/all/themes/hwc_frontend/images/share-popup/linkedin.png)!important;
        background-color: rgba(0, 0, 0, 0) !important;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-google-plus a {
        background-image: url(/sites/all/themes/hwc_frontend/images/share-popup/google-plus.png)!important;
        background-color: rgba(0, 0, 0, 0) !important;
    }
    #share-popup-container .share-widget-container .osha-share-widget .osha-share-widget-print a {
        background-image: url(/sites/all/themes/hwc_frontend/images/share-popup/print_icon.png)!important;
        background-color: rgba(0, 0, 0, 0) !important;
    }
</style>
  <?php
}
