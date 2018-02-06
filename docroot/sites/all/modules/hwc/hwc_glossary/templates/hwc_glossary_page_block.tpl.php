<div class="selectCountry">
    <div class="containerSmall">
        <div class="textGlossary"><?php echo t("Find all terms:"); ?> </div>
        <div class="searchGlossary"><?php echo l(t('Search'),'glossary-search') ?></div>
        <div class="filterGlossary selected"><?php echo t("A-Z Filter"); ?> <div class="arrow"></div></div>
    </div>
</div>
<script>
    function glossaryLetters() {
        if (jQuery(".lexicon-links").length>0) {
            var letterSelected=jQuery(".lexicon-item.active").text();
            var html="<div class='letterSelected'>"+letterSelected+"</div>";
            jQuery(".lexicon-list dl").before(html);
        }
    }
    (function ($) {
        $(document).ready(function(){
            glossaryLetters();
        });
    })(jQuery);

</script>