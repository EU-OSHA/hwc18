<?php

if (empty($campaign_id)) {
  if (!empty($variables['elements']['#campaign_id'])) {
    $campaign_id = $variables['elements']['#campaign_id'];
  }
  elseif (!empty($variables['campaign_id'])) {
    $campaign_id = $variables['campaign_id'];
  }
}

$url_query = array();
if (!empty($campaign_id)) {
  $url_query = array('pk_campaign' => $campaign_id);
}

global $language;
$directory = drupal_get_path('module','osha_newsletter');
?>

<span class="preview-text" style="color: transparent; display: none !important; height: 0; max-height: 0; max-width: 0; opacity: 0; overflow: hidden; mso-hide: all; visibility: hidden; width: 0;">
  <?php
    $newsletter_ready_date = format_date(strtotime($newsletter_date), 'custom', 'F Y');
    print t("Healthy Workplaces Campaign Newsletter &ndash; ");
    print t($newsletter_ready_date);
  ?>
</span>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="preheader template-container">
  <tbody>
    <tr>
      <td height="6" style="background-color: #003399;"">
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family: Arial,sans-serif;" class="header template-container">
  <tbody>
    <tr>
      <td width="219" style="max-width: 219px;">
      <!-- @todo: replace with HWC logo -->
        <?php
          global $base_url;
          print l(theme('image', array(
            'path' => $directory . '/images/hwc_image.png',
            'width' => 219,
            'height' => 108,
            'alt' => 'Healthy Workplaces Campaign',
            'attributes' => array('style' => 'border: 0px; width: 219px; max-width: 219px; height: 108px; max-height: 108px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
        ?>
      </td>
      <td width="121" style="width: 121px; max-width: 121px; font-family: Arial; font-size: 16px; font-weight: bold; color: #003399; vertical-align: middle;">
        Healthy Workplaces MANAGE DANGEROUS SUBSTANCES
      </td>
      <td class="osha-logos">
        <?php
          global $base_url;
          print l(theme('image', array(
            'path' => $directory . '/images/logo-osha2.png',
            'width' => 140,
            'height' => 88,
            'alt' => 'European Agency for Safety and Health at Work',
            'attributes' => array('style' => 'border: 0px; width: 140px; max-width: 140px; height: 88px; max-height: 88px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
          ?>
      </td>
      <td>
        <?php
          print theme('image', array(
            'path' => $directory . '/images/europeLogo.png',
            'width' => 57,
            'height' => 37.09,
            'alt' => 'EU',
            'attributes' => array('style' => 'border: 0px; margin-left: 20px; width: 57px; max-width: 57px; height: 37.09px; max-height: 37.09px;')
          ));
        ?>
      </td>
      <td class="osha-info">
        <?php
          print l(theme('image', array(
            'path' => $directory . '/images/healthy_workplaces.png',
            'width' => 87,
            'height' => 81.5,
            'alt' => 'Healthy Workplaces',
            'attributes' => array('style' => 'border: 0px; width: 87px; max-width: 87px; height: 81.5px; max-height: 81.5px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
        ?>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" class="template-container">
  <tbody>
    <tr>
      <td style="padding-top: 0px; padding-bottom: 25px;">
        <table border="0" cellpadding="0" cellspacing="0" width="100%" class="header-title">
          <tbody>
            <tr>
              <td style="background-color: #6ca638; width: 70%; text-align: left; font-size: 24px; font-weight: 200; color: #ffffff; font-family: Arial,sans-serif;">
                <?php print t("Healthy Workplaces Campaign Newsletter");?>
              </td>
              <td style="background-color: #6ca638; width: 30%; text-align: right; font-size: 14px; font-weight: 200; color: #ffffff; font-family: Arial,sans-serif;" class="hidden-print">
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>
