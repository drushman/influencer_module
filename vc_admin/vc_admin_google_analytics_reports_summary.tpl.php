<?php
/**
 * @file
 * Theme implementation to display the Google Analytics summary.
 */
?>

<div class="google-analytics-summary google-analytics-reports">
  <div class="google-analytics-visits">    
    <div class="google-analytics-conversion">
      <h3><?php print t('Conversion'); ?></h3>
      <div class="google-analytics-conversion-data">
        <?php print $goalConversionRateAll; ?>
      </div>
    </div>
    <div class="google-analytics-visitor-loyalty">
      <h3><?php print t('Visitor Loyalty'); ?></h3>
      <div class="google-analytics-visitor-loyalty-data">
        <?php print $visitor_loyalty; ?>
      </div>
    </div>
    <div class="google-analytics-social">
      <div class="google-analytics-facebook">
        <?php print $facebook; ?>
      </div>
      <div class="google-analytics-twitter">
        <?php print $twitter; ?>
      </div>
    </div>
  </div>

  <div class="google-analytics-visits-chart">
    <h3><?php print t('Site Statistics'); ?></h3>
    <div class="google-analytics-visits-chart-desc"><?php print t('Visits Over the Past 30 Days'); ?></div>
    <?php print $visit_chart; ?>
  </div>

  <div class="google-analytics-site-info">
    <h3><?php print t('Site Information'); ?></h3>
    <ul>
      <li class="first">
        <div class="odd"><?php print $entrances; ?></div>
        <div class="even"><?php print t('Visits'); ?></div>
      </li>
      <li>
        <div class="odd"><?php print $pageviews; ?></div>
        <div class="even"><?php print t('Pageviews'); ?></div>
      </li>
      <li>
        <div class="odd"><?php print $bounces; ?></div>
        <div class="even"><?php print t('Bounce Rate'); ?></div>
      </li>
      <li class="last">
        <div class="odd"><?php print $time_on_site; ?></div>
        <div class="even"><?php print t('Avg. Time on Site'); ?></div>
      </li>
    </ul>
  </div>
  <div class="google-analytics-top">
    <div class="google-analytics-pages">      
      <ul>
        <?php print $pages; ?>
      </ul>
    </div>
  
    <div class="clearfix">
      <div class="google-analytics-referrals">
        <h3><?php print t('Top Referrals'); ?></h3>
        <?php print $referrals; ?>
      </div>
  
      <div class="google-analytics-keywords">
        <h3><?php print t('Top Searches'); ?></h3>
        <?php print $keywords; ?>
      </div>
    </div>
  </div>
</div>