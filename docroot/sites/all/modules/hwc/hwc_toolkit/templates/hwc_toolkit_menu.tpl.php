<div class="key-menu-container">
<ul class="menu clearfix"><?php
  foreach ($menu as $menu_nid => $menu_item1) {
    $class = "menu__item";
    if ($menu_item1['children']) {
      $class .= " expanded";
    }
    if (isset($menu_item1['active'])) {
      $class .= " active";
    }
    ?>
      <li class="<?php print $class; ?>"><a href="<?php print $menu_item1['href'];?>" class="key-<?php print $menu_item1['class'];?>"><?php print $menu_item1['title'] ?></a>
        <?php
        if ($menu_item1['children']) {
          print '<ul class="menu clearfix">';
          foreach($menu_item1['children'] as $menu_nid2 => $menu_item2) {
            $class = "menu__item";
            if ($menu_item2['children']) {
              $class .= " expanded";
            }
            if (isset($menu_item2['active'])) {
              $class .= " active";
            }
            ?>
              <li class="<?php print $class; ?>"><a href="<?php print $menu_item2['href'];?>" class="key-<?php print $menu_item2['class'];?>"><?php print $menu_item2['title'] ?></a>
            <?php
            if ($menu_item2['children']) {
              print '<ul class="menu clearfix">';
              foreach($menu_item2['children'] as $menu_nid3 => $menu_item3) {
                $class = "menu__item";
                if ($menu_item3['children']) {
                  $class .= " expanded";
                }
                if (isset($menu_item3['active'])) {
                  $class .= " active";
                }
                ?>
                  <li class="<?php print $class; ?>"><a href="<?php print $menu_item3['href'];?>" class="key-<?php print $menu_item3['class'];?>"><?php print $menu_item3['title'] ?></a></li>
                <?php
              }
              print '</ul>';
            }
            print '</li>';
          }
          print '</ul>';
        }
    print '</li>';
  }
  ?>
</ul>
</div>
<script type="text/javascript">
    jQuery(document).ready(function () {
        var hash = window.location.hash;
        if (hash) {
            var link_element = jQuery("a[href='"+ hash +"']");
            if (link_element) {
                link_element.css({ "font-weight": "bold", "text-decoration": "none" });
                link_element.parent().parent().css({"display": "block"});
                jQuery(hash).removeClass("close").addClass("active");
            }
            else {
                jQuery(".key-content > div#start").removeClass("close").addClass("active");
            }
        }
        else {
            jQuery(".key-content > div#start").removeClass("close").addClass("active");
        }
    });

    jQuery(document).ready(function () {

        jQuery(".key-menu-container a").click(function() {
            var href = jQuery(this).attr("href");

            jQuery(".key-content div.title_link.active").addClass("close");

            jQuery(href).removeClass("close");
            jQuery(href).addClass("active");

            jQuery(".key-menu-container a").css("font-weight", "normal");
            jQuery(this).css({ "font-weight": "bold", "text-decoration": "none" });
        });

    });

</script>
<style>
    .close {
        /*visibility: hidden;*/
        /*display: none;*/
    }
    .key-menu-container .active > a {
        font-weight: bold;
    }
    .key-menu-container .expanded.active .expanded.active li,
    .key-menu-container .expanded.active > ul > li,
    .key-menu-container .expanded.active {
        visibility: visible;
        display: block;
    }
    .key-menu-container .expanded li li,
    .key-menu-container li .expanded {
        visibility: hidden;
        display: none;
    }
</style>
