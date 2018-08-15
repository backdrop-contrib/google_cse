# Google Custom Search Engine

- [Google Custom Search Engine](#google-custom-search-engine)
    - [Overview](#overview)
    - [Quick Setup](#quick-setup)
    - [Blocks](#blocks)
    - [Installation](#installation)
    - [Credits](#credits)
    - [License](#license)

## Overview

Google Custom Search Engine (CSE) is an embedded search engine that can
be used to search any set of one or more sites.  No Google API key is
required.  Read more at http://www.google.com/cse/.

## Quick Setup

Currently the default Search module must be disabled for Google CSE to be
configured. After installing this module, go to admin/config/search/cse-settings
to configure it by entering Google's unique ID for your
CSE.  Once you have granted permission for one or more roles to search
the Google CSE, a separate self-contained search block needs to be enabled and placed
in order to use Google CSE.

## Blocks

The include Google CSE block can optionally be enabled at
admin/structure/block.  The "Google CSE" block provides a search box and
also displays the search results.  After entering search terms, the user
will be returned to the same page (via GET request) and the results will
be displayed.


## Installation

Place the google_cse directory in your backdrop modules directory.  
Enable the Google CSE module at admin/modules, configure it at
admin/config/search/settings, and assign permissions for "Google
CSE" at admin/people/permissions.

To configure this module, you will need your CSE's unique ID.  Go to
http://www.google.com/cse/manage/all, select your search engine then
click the "Search engine ID" button to the right of "Details".

## Credits (Seeking Additional Maintainers!)

* Ported to Backdrop CMS by [Jesus Ortiz Tovar](https://github.com/jeor0980)
* Originally written for Drupal by [Mark Burdett (mfb)](https://www.drupal.org/u/mfb) and [others](https://www.drupal.org/node/131984/committers)

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
