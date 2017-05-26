<?php
$update_id = $content['dashboard_item_id'];
$entities = entity_load('dashboard_item', [$update_id]);
$variables = unserialize($entities[$update_id]->variables);

$company = $variables['company'];
$variables = $variables['companyStatusUpdate'];
$share = $variables['share'];

$main_title   = @$share['comment'];
$title = @$share['content']['title'];
$submittedUrl = @$share['content']['submittedUrl'];
$background_image = @$share['content']['submittedImageUrl'];

if ($submittedUrl) {
  $parse = parse_url($submittedUrl);
  $host = $parse['host'];
}

$timestamp = '';
if ($content['timestamp']) {
  $timestamp = timeago_format_date(intval($content['timestamp']));
}

$company_name = $company['name'];
$company_href = '/company-beta/' . $company['id'];
$avatar_image = variable_get('social_linkedin_company_avatar_image', '');

echo '
<div class="feed-s-update">
  <article>
    <div class="feed-s-update__scroll">
            
      <div class="feed-s-post-meta">
        <a href="' . $company_href . '" class="feed-s-post-meta__actor-link">    
          <div class="feed-s-avatar-image">
            <img src="' . $avatar_image . '" class="avatar company" alt="' . htmlspecialchars($company_name) . '">
          </div>
        </a>
        <a href="' . $company_href . '" class="feed-s-post-meta__profile-link">  
          <h3 class="feed-s-post-meta__actor">
            <span class="feed-s-post-meta__name">' . $company_name . '</span>
            <time class="feed-s-post-meta__timestamp">' . $timestamp . '</time>
          </h3>
        </a>
      </div>      
';

if ($main_title) {
  echo '<div class="feed-s-update__description">' . $main_title . '</div>';
}

if ($title) {
echo '      <div class="feed-s-update__update-content-wrapper">
        <div class="feed-s-hero-entity__image-container">
          <a target="_blank" href="' . $submittedUrl . '">
              <div class="feed-s-hero-entity__image" style="background-image: url(&quot;' . $background_image . '&quot;);"> </div>
          </a>
        </div>
        <a target="_blank" href="' . $submittedUrl . '">
          <article class="feed-s-image-description">
            <div class="feed-s-image-description">
              <h2 class="feed-s-image-description__headline">
                <div class="truncate-multiline--truncation-target"><span>' . $title . '</span></div>  
              </h2>
              <h3 class="feed-s-image-description__byline">' . $host . '</h3>
            </div>
          </article>
        </a>
      </div>
';
}
?>
    </div>
  </article>  
</div>
