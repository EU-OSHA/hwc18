/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_sort = {
        attach: function(context, settings) {
            jQuery('#edit-sort-by').change(function(){
                jQuery('#views-exposed-form-search-site #edit-sort-by--2').val(jQuery(this).val());
            });
            form = document.getElementById('osha-search-sort-form');
            if (form) {
                form.onsubmit = function() {
                    return false;
                };
            }
        }
    }
})(jQuery);
