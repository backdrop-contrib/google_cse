# Google Custom Search Engine

## Contents of this file

* Overview
* Quick setup
* Requirements
* Blocks
* SiteSearch
* Search module integration
* Advanced settings
* Installation
* Maintainers

## Overview

Google Custom Search Engine (CSE) is an embedded search engine that can
be used to search any set of one or more sites.  No Google API key is
required.  Read more at http://www.google.com/cse/.

## Quick Setup

After installing this module, activate Google CSE at 
admin/config/search/settings, optionally setting it as the default
search module, and configure it by entering Google's unique ID for your
CSE.  Once you have granted permission for one or more roles to search
the Google CSE, the search page can be found at search/google, and a
separate self-contained search block can also be enabled.

## Blocks

The include Google CSE block can optionally be enabled at
admin/structure/block.  The "Google CSE" block provides a search box and
also displays the search results.  After entering search terms, the user
will be returned to the same page (via GET request) and the results will
be displayed.  Do not allow this Google CSE block to appear on the
search/google page, as the search results will fail to display.

## SiteSearch

In addition to the CSE functionality, SiteSearch on one or more domains
or URL paths can optionally be configured.  Radio buttons allow users to
search on either the SiteSearch option(s) or the CSE, and searches can
default to either option.

## Advanced Settings

The collapsed advanced settings on the settings page provide various
customizations such as country and language preferences.  For example,
with the Locale module enabled, the Google CSE user interface language
can be selected dynamically based on the current user's language.

## Installation

Place the google_cse directory in your backdrop modules directory.  
Enable the Google CSE module at admin/modules, configure it at
admin/config/search/settings, and assign permissions for "Google
CSE" at admin/people/permissions.

To configure this module, you will need your CSE's unique ID.  Go to
http://www.google.com/cse/manage/all, select your search engine then
click the "Search engine ID" button to the right of "Details".

## Credits

* Ported to Backdrop CMS by [Jesus Ortiz Tovar](https://github.com/jeor0980)
* Originally written for Drupal by [Mark Burdett (mfb)](https://www.drupal.org/u/mfb) and [others](https://www.drupal.org/node/131984/committers)

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.