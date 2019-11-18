
INTRODUCTION
------------
This module provides feature for removing multiple links from
xml sitemap in one place. It helps the user to exclude multiple
sitemap link at once without navigating to each node to make the changes.

For a full description of the module, visit the project page:

https://www.drupal.org/project/xml_sitemap_bulk_link_exclude

REQUIREMENTS
------------

This module requires the following modules:

 * XML sitemap (https://www.drupal.org/project/xmlsitemap)


INSTALLATION
------------
1. Place the entire xmlsitemap bulk link exclude folder into your Drupal
   sites/all/modules/directory.

2. Enable the xml sitemap bulk link exclude module.

3. Once the module is installed, you will find a new backend configuration form
   to exclude unwanted links from xml sitemap.

CONFIGURATION
-------------

* Configuration to exclude sitemap links can be found in
  admin/config/search/list/xml_exclude_links:

  - There are two options provided for admin user to exclude link
    from XML sitemap.

    * Manually entering the sitemap URLs in the configuration and submit.
      "admin/config/search/xml_sitemap_bulk_exclude".

    * Select the Sitemap links from auto generated sitemap links listing page
      and submit.
      "admin/config/search/list/xml_exclude_links".

 * Once the exclusion of URLs done through any of the above method.
   Re-generate the XML sitemap in "admin/config/search/xmlsitemap" to
   make the changes reflect in front.

Author
------
Logeshwaran
