/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_sort = {
        attach: function(context, settings) {
            jQuery('#edit-sort-by').change(function(){
                jQuery('#block-views-exp-documents-page-1 #edit-sort-by--2, #block-views-exp-documents-page-2 #edit-sort-by--2').val(jQuery(this).val());
                jQuery('#block-views-exp-documents-page-1, #block-views-exp-documents-page-2').submit();
            });
            jQuery('#edit-sort-order').change(function(){
                jQuery('#block-views-exp-documents-page-1 #edit-sort-order--2, #block-views-exp-documents-page-2 #edit-sort-order--2').val(jQuery(this).val());
                jQuery('#block-views-exp-documents-page-1, #block-views-exp-documents-page-2').submit();
            });
            if (jQuery('#hwc-good-practice-exchange-sort-form').length) {
              document.getElementById('hwc-good-practice-exchange-sort-form').onsubmit = function() {
                return false;
              };
            }
        }
    }
})(jQuery);
