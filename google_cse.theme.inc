<?php

/**
 * @file
 * Themeable functions for Google Custom Search Engine.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function google_cse_get_cse_tag() {
  $config = config('google_cse.settings');
  $display = $config->get('google_cse_custom_results_display');
  $attributes = filter_xss($config->get('google_cse_tag_attributes'));

  switch ($display) {
    case 'overlay':
    case 'compact':
    case 'full-width':
      return '<gcse:search ' . $attributes . '></gcse:search>';

    case 'two-page':
      return '<gcse:searchbox-only ' . $attributes . '></gcse:searchbox-only><gcse:searchresults-only ' . $attributes . '></gcse:searchresults-only>';


    case 'two-column':
      return '<gcse:searchbox ' . $attributes . '></gcse:searchbox><gcse:searchresults ' . $attributes . '></gcse:searchresults>';


    case 'results-only':
      return '<gcse:searchresults-only ' . $attributes . '></gcse:searchresults-only>';

    case 'google-hosted':
      return '<gcse:searchbox-only ' . $attributes . '></gcse:searchbox-only>';

    default:
      watchdog('google_cse', 'Invalid custom result display %display',
               array('%display' => $display), WATCHDOG_CRITICAL);
  }
}

/**
 * The search results page can be themed/customized.
 */
function template_preprocess_google_cse_results(&$variables) {
  $config = config('google_cse.settings');
  $variables['results_searchbox_form'] = $variables['form'] ? backdrop_get_form('google_cse_results_searchbox_form') : '';
  $variables['cse_tag'] = google_cse_get_cse_tag();
  $variables['noscript'] = t('You must enable JavaScript to view the search results.');
  $variables['prefix'] = filter_xss_admin($config->get('google_cse_results_prefix'));
  $variables['suffix'] = filter_xss_admin($config->get('google_cse_results_suffix'));

  if (google_cse_validate_request()) {
    backdrop_add_js(backdrop_get_path('module', 'google_cse') . '/google_cse_results.js',
                  array('scope' => 'footer'));
    backdrop_add_css('' . $config->get('google_cse_custom_css') . '', 'external');
  }
}

/**
 * Validate GET parameters to avoid displaying inappropriate search results.
 */
function google_cse_validate_request() {
  return (empty($_GET['cx']) || $_GET['cx'] == config_get('google_cse.settings', 'google_cse_cx'));
}

/**
 * Form builder for the searchbox forms.
 */
function google_cse_results_searchbox_form($form, &$form_state) {
  $config = config('google_cse.settings');
  $form = array();
  if ($config->get('google_cse_results_display') == 'here') {
    $cof = $config->get('google_cse_cof_here');
  }
  else {
    $form['#action'] = '//' . $config->get('google_cse_domain') . '/cse';
    $cof = $config->get('google_cse_cof_google');
  }
  $form['#method'] = 'get';
  $form['cx'] = array(
    '#type' => 'hidden',
    '#value' => $config->get('google_cse_cx'),
  );
  $form['cof'] = array(
    '#type' => 'hidden',
    '#value' => $cof,
  );
  $form['query'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($_GET['query']) ? $_GET['query'] : '',
  );
  $form['sa'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );
  $form['query']['#size'] = intval($config->get('google_cse_results_searchbox_width'));
  $form['query']['#title'] = t('Enter your keywords');

  return $form;
}
