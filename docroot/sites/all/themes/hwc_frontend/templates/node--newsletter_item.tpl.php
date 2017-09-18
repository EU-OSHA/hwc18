<?php
/**
 * @file
 * EU-OSHA's theme implementation to display a newsletter item in Newsletter item view mode.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */

$campaign_id = '';
if (!empty($variables['elements']['#campaign_id'])) {
  $campaign_id = $variables['elements']['#campaign_id'];
}
elseif (!empty($variables['campaign_id'])) {
  $campaign_id = $variables['campaign_id'];
}

$url_query = array();
if (!empty($campaign_id)) {
  $url_query = array('pk_campaign' => $campaign_id);
}
?>
<style>
    .page-node-129 table tr .td_h {
        vertical-align: top;
        text-align:left;
        padding-left: 5px;
        padding-top: 7px;
        width:10px;
    }
    .page-node-129 table tr .ar {
        text-align: left;
        padding-top: 5px;
        padding-bottom: 10px;
        padding-left:0px;
    }
    .page-node-129 table tr .rs2 {
        width:40px;
        padding-right: 10px;
    }
    .page-node-129 table tr .pt15 {
        padding-top: 15px;
    }
    .page-node-129 table tr .cs2 {
        width:40px;
        max-width:40px;
        padding-right: 5px;
    }
</style>
<?php if($node->title != NULL) {?>
  <table id="node-<?php print $node->nid; ?>" class="newsletter-item <?php print drupal_clean_css_identifier($node->type); ?>">
    <tbody>
      <?php if(!empty($node->old_newsletter)): ?>
        <tr>
          <td colspan="3" class="pt15"></td>
        </tr>
      <?php endif; ?>
    <?php
    if (isset($node->field_publication_date[LANGUAGE_NONE][0]['value']) && $node->type != 'newsletter_article') {
      $date = strtotime($node->field_publication_date[LANGUAGE_NONE][0]['value']);
    } if ($node->type == 'events') {
      $date = (isset($field_start_date) && !empty($field_start_date)) ? strtotime($field_start_date[0]['value']) : '';
      $country_location = (isset($field_country_code) && !empty($field_country_code)) ? $field_country_code['und'][0]['value'] : '';
      $city_location = (isset($field_city) && !empty($field_city)) ? $field_city[0]['safe_value'] : '';
      ?>
      <tr>
        <?php if (empty($node->old_newsletter)): ?>
          <td class="rs2" rowspan="2">
            <?php
              global $base_url;

            $calendar_img = 'calendar-' . date('d', $date);

            $calendar_img = !empty($node->arrow_color) ? "{$calendar_img}-{$node->arrow_color}.png" : "{$calendar_img}.png";
            $calendar_img_path = "{$base_url}/sites/all/modules/osha/osha_newsletter/images/calendars/{$calendar_img}";

              print l(theme('image', array(
              'path' => $calendar_img_path,
              'width' => 40,
              'height' => 36,
              'alt' => 'calendar',
              'attributes' => array('style' => 'border: 0px;height:35px!important;width:40px!important;max-height:35px!important;max-width:40px!important;display:block;')
            )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
              'html' => TRUE,
              'external' => TRUE,
              'query' => $url_query,
            ));
            ?>
          </td>
          <td colspan="2" class="cs2">
            <span class="item-date"><?php if (trim($country_location) != '' && trim($city_location) != '') { echo $country_location . ' ' . $city_location . ', ';} ?></span>
          </td>
        <?php else: ?>
          <td colspan="2" class="cs2">
            <span class="item-date"><?php if (trim($country_location) != '' && trim($city_location) != '') { echo $country_location . ' ' . $city_location . ', ';} ?></span>
          </td>
        <?php endif; ?>
      </tr>
      <?php
    }
    ?>
    <tr class="tr_h">
        <td class="td_h">
          <span> > </span>
        </td>
      <td class="ar">
        <?php
        $link ='node/' . $node->nid;
        if (isset($node->alt_url)) {
          $link = $node->alt_url;
        }
        switch ($node->type) {
          case 'publication':
            print l($node->title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
              'attributes' => array('class' => ['newsletter-item-view-link']),
              'query' => $url_query,
              'external' => TRUE
            ));
            break;
          case 'twitter_tweet_feed':
            if (!empty($node->field_tweet_author[LANGUAGE_NONE][0]['value'])
                && !empty($node->field_tweet_contents[LANGUAGE_NONE][0]['value'])
                && !empty($node->field_link_to_tweet[LANGUAGE_NONE][0]['value'])) {
              printf("<p class='tweet-author'><a target='_blank' href='%s'>@%s</a></p><p class='tweet-contents'>%s</p>",
                $node->field_link_to_tweet[LANGUAGE_NONE][0]['value'],
                $node->field_tweet_author[LANGUAGE_NONE][0]['value'],
                $node->field_tweet_contents[LANGUAGE_NONE][0]['value']);
            }
            else {
              goto defaultLabel;
            }
            break;
          case 'newsletter_article':
            if (!empty($node->parent_section) && $node->parent_section == 13) {
              // Coming soon section
              print render(field_view_field('node', $node, 'body', 'newsletter_item'));
            }
            else {
              goto defaultLabel;
            }
            break;
          default:
            defaultLabel:
//@todo check            print l($node->title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
//@todo check              'attributes' => array('class' => ['newsletter-item-view-link']),
            print l($node->title, url($link, array('absolute' => TRUE)), array(
              'attributes' => array('style' => 'text-decoration: none; font-family:Arial, sans-serif; font-size: 13px; font-weight: bold;'),
              'query' => $url_query,
              'external' => TRUE
            ));
            break;
        }
        ?>
      </td>
    </tr>
    <?php if(!empty($node->old_newsletter)): ?>
      <tr>
        <td colspan="3" class="pt15"></td>
      </tr>
    <?php endif; ?>
    </tbody>
  </table>
<?php } ?>
