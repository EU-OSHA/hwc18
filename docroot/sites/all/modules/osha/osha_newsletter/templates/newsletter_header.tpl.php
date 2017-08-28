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
    print t("Occupational Safety and Health News &ndash; Europe &ndash; ");
    print t($newsletter_ready_date);
  ?>
</span>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="preheader template-container">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" width="100%" class="language-bar" style="max-width:100%;">
          <tbody>
            <tr>
              <td style="font-size: 12px; padding-left: 30px; padding-right: 30px; font-family: Arial,sans-serif;">
                <?php
                 if ($languages) {
                   $languages_text = [];
                   foreach ($languages as $l) {
                     if ($l->language != "tr" && $l->language != "ru") {
                       $languages_text[] = strtr('<a href="!link" style="text-decoration: none; color: !color; ">!text</a>',
                          [
                            '!link' => url('entity-collection/' . $newsletter_id, array('absolute' => TRUE, 'language' => $l, 'query' => $url_query)),
                            '!color' => ($l->language == $language->language) ? '#003399' : '#606060',
                            '!text' => $l->native
                          ]);
                    }
                  }
                 }
                ?>
                <?php foreach ($languages_text as $lidx =>  $lang_text) { ?>
                  <?php if ($lidx > 0): ?>
                    <span style="color: #606060;"> | </span>
                  <?php endif; ?>
                  <?php print $lang_text;?>
                <?php } ?>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family: Oswald, Arial,sans-serif;" class="header template-container">
  <tbody>
    <tr>
        <td style="padding: 10px;">
            <div class="illustration">
                <img width="250" src="http://eu-osha.github.io/hwc-splashpage/img/osha-illustration.png" alt="Osha illustration">
            </div>
        </td>
        <td style="padding: 10px;">
            <span class="title" style="font-size: 1.2rem;font-weight: 700;color: #003399;">
        Healthy
        Workplaces
        MANAGE
        DANGEROUS
        SUBSTANCES
      </span>
        </td>
      <td class="osha-logos" style="padding: 10px;">
        <?php
          global $base_url;
          $eu_osha_img = 180;
          print l(theme('image', array(
            'path' => $directory . '/images/EU-OSHA-en.png',
            'width' => $eu_osha_img,
            'alt' => 'European Agency for Safety and Health at Work',
            'attributes' => array('style' => 'border: 0px; width: '.$eu_osha_img.'px; max-width: '.$eu_osha_img.'px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
          ?>
        </td>
        <td class="osha-logos" style="padding: 10px;">
        <?php
          print theme('image', array(
            'path' => $directory . '/images/europeLogo.png',
            'width' => 63,
            'height' => 41,
            'alt' => 'EU',
            'attributes' => array('style' => 'border: 0px; width: 63px; max-width: 63px; height: 41px; max-height: 41px;')
          ));
        ?>
      </td>
        <td style="padding: 10px;">
            <span class="logo">
        <a href="/"><img src="http://eu-osha.github.io/hwc-splashpage/img/osha-logo-hw.png" alt="Healthy Workplaces logo"></a>
      </span>
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
                <td style="background-color: #003399; width: 70%; text-align: left; font-size: 24px; font-weight: 200; color: #ffffff; font-family: Oswald, Arial,sans-serif;">
                    <div class="newsletter-number" style="font-size: 20px; font-weight: 200; text-align: left;"><?php print $newsletter_title; ?></div>
                </td>
                <td style="background-color: #003399; width: 70%; text-align: left; font-size: 24px; font-weight: 200; color: #ffffff; font-family: Oswald, Arial,sans-serif;">
                    <div class="newsletter-month" style="font-size: 26px; text-align: right;"><?php print $newsletter_ready_date; ?></div>
                </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>