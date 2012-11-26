<?php
/**
 * @file
 * Theme preprocess functions for google analytics.
 */

function template_preprocess_vc_admin_google_analytics_reports_summary(&$vars) {
  $vars = array_merge($vars, $vars['usage']);

  if ($vars['visits'] <= 0) {
    $vars['visitor_loyalty'] = '0.00%';
    $vars['time_on_site'] = '0:00';
    $vars['goalConversionRateAll'] = '0:00%';
  }
  else {
    $vars['visitor_loyalty'] = number_format(round(100 - ($vars['newVisits'] / $vars['visits'])*100, 2), 2) . '%';
    $vars['time_on_site'] = format_interval($vars['timeOnSite'] / $vars['visits']);
    $vars['goalConversionRateAll'] = number_format(round($vars['conversion'], 2), 2) . '%';
  }

  if ($vars['entrances'] <= 0) {
    $vars['bounces'] = '0.00%';
  }
  else {
    $vars['bounces'] = number_format(round(($vars['bounces'] / $vars['entrances'])*100, 2), 2) . '%';
  }

  $vars['entrances'] = number_format($vars['entrances']);
  $vars['pageviews'] = number_format($vars['pageviews']);

  $pages = array();
  foreach ($vars['pages'] as $key => $page) {
    if ($page['pagePath'] == '/index.html') {
      $page['pagePath'] = '/';
    }
    $vars['pages'][$key] = '<div class="odd">'.l($page['pageTitle'], "http://$page[hostname]$page[pagePath]", array('external' => TRUE, 'html' => TRUE)).'</div>';
    $vars['pages'][$key].= '<div class="even">'.format_plural($page['pageviews'], '1 View', '@views Views', array('@views' => number_format($page['pageviews']))).'</div>';
  }
  array_unshift($vars['pages'], '<h3 class="odd">Most visited pages</h3><h3 class="even">Views</h3>');
  $vars['pages'] = theme('item_list', array('items' => $vars['pages'], 'type' => 'ul'));

  $referrals = array();
  foreach ($vars['referrals'] as $referral) {
    $referrals[] = '<strong>' . $referral['source'] . '</strong> - ' . format_plural($referral['visits'], '1 Visit', '@visits Visits', array('@visits' => number_format($referral['visits'])));
  }
  $vars['referrals'] = theme('item_list', array('items' => $referrals, 'type' => 'ul'));

  $keywords = array();
  foreach ($vars['keywords'] as $keyword) {
    $keywords[] = '<strong>' . $keyword['keyword'] . '</strong> - ' . format_plural($keyword['visits'], '1 Visit', '@visits Visits', array('@visits' => number_format($keyword['visits'])));
  }
  $vars['keywords'] = theme('item_list', array('items' => $keywords, 'type' => 'ul'));
  
  $vars['facebook'] = format_plural($vars['facebook'], '<div class="odd">1</div><div class="even">LIKES</div>', '<div class="odd">@visits</div><div class="even">LIKES</div>', array('@visits' => number_format($vars['facebook'])));
  $vars['twitter'] = format_plural($vars['twitter'], '<div class="odd">1</div><span><div class="even">FOLLOWERS</div>', '<div class="odd">@visits</div><div class="even">FOLLOWERS</div>', array('@visits' => number_format($vars['twitter'])));
}