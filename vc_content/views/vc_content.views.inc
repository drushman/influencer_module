<?php

/**
 * @file
 * Implementation hook_views_data
 */

function vc_content_views_data() {
  $data = array();

  $data['node_type']['table']['group']  = t('Node types');

  $data['node_type']['table']['base'] = array(
    'field' => 'type', 
    'title' => t('Node types'), 
    'help' => t('Node types.'), 
  );
  
  $data['node_type']['type'] = array(
    'title' => t('The machine-readable name of this type. '), 
    'help' => t('The machine-readable name of this type.'), 
    'field' => array(
      'click sortable' => TRUE,
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['node_type']['name'] = array(
    'title' => t('The human-readable name of this type.'), 
    'help' => t('The human-readable name of this type.'), 
    'field' => array(
      'click sortable' => TRUE,
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
 
  return $data;  
}