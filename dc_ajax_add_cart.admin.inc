<?php

/**
 * @file
 * dc_ajax_add_cart.admin.inc
 */

/**
 * Commerce AJAX Add to Cart settings form.
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Current form state.
 *
 * @return array
 *   Drupal system settings form.
 */
function dc_ajax_add_cart_ajax_cart_settings_form($form, &$form_state) {
  $form['dc_ajax_add_cart_checkout_redirect'] = array(
    '#type' => 'select',
    '#title' => t('Checkout button redirect'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_CHECKOUT_REDIRECT, 'cart_page'),
    '#options' => array(
      'cart_page' => t('Cart page'),
      'checkout_page' => t('Checkout page'),
    ),
    '#decription' => t('Configure where you want to redirect after clicking checkout button on AJAX Shopping Cart.'),
  );

  $form['dc_ajax_add_cart_show_labels'] = array(
    '#type' => 'radios',
    '#title' => t('Show labels'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_SHOW_LABELS, 'label'),
    '#options' => array(
      'label' => t('Yes'),
      'no_label' => t('No'),
    ),
    '#description' => t('Configure whether you want to show labels in AJAX Shopping Cart'),
  );

  $form['dc_ajax_add_cart_empty_cart_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Empty cart message'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_EMPTY_CART_MESSAGE, 'Shopping cart is empty'),
    '#description' => t('Message that will be displayed if the cart is empty.'),
  );

  $form['dc_ajax_add_cart_remove_cart'] = array(
    '#type' => 'select',
    '#title' => t('Remove cart'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_REMOVE_CART, 'link'),
    '#options' => array(
      'link' => t('Display remove from cart as link'),
      'image' => t('Display remove from cart as image'),
    ),
    '#description' => t('Configure how you want to display the Remove from Cart button'),
  );

  return system_settings_form($form);
}

/**
 * Commerce AJAX Add to Cart teaser settings.
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Current form state.
 *
 * @return array
 *   Drupal system settings form.
 */
function dc_ajax_add_cart_cart_teaser_settings_form($form, &$form_state) {
  $form['dc_ajax_add_cart_empty_cart_teaser_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Empty cart message'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_EMPTY_CART_TEASER_MESSAGE, 'Empty'),
    '#description' => t('Message that will be displayed on cart teaser if cart is empty.'),
  );

  $form['dc_ajax_add_cart_item_suffix_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Item suffix text'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_ITEM_SUFFIX_TEXT, 'item'),
    '#description' => t('Suffix text that will be displayed after the number of items in cart teaser. Multiple items will be detected and the text will be changed according to that.'),
  );

  return system_settings_form($form);
}

/**
 * Popup message settings.
 *
 * @param array $form
 *   Drupal array form.
 *
 * @param array $form_state
 *   Current form state.
 *
 * @return array
 *   Drupal array form.
 */
function dc_ajax_add_cart_popup_message_settings_form($form, &$form_state) {
  $form['dc_ajax_add_cart_display_popup'] = array(
    '#type' => 'radios',
    '#title' => t('Display popup message'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_DISPLAY_POPUP, 'display_popup_message'),
    '#options' => array(
      'display_popup_message' => t('Yes'),
      'no_display_popup_message' => t('No'),
    ),
    '#description' => t('Configure whether you want to display a popup message after adding item to cart.'),
  );

  $form['dc_ajax_add_cart_success_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Success message'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_SUCCESS_MESSAGE, 'Item successfully added to cart'),
    '#description' => t('Success message that will appear on popup after adding item to cart.'),
  );

  $form['product_details_popup'] = array(
    '#type' => 'fieldset',
    '#title' => t('Product details in popup'),
    '#description' => t('Configure what product details you want to show in popup.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Product name display setting.
  $form['product_details_popup']['dc_ajax_add_cart_popup_product_name_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Product name'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_NAME_DISPLAY, 1),
    '#disabled' => TRUE,
    '#ajax' => array(
      'callback' => 'dc_ajax_add_cart_popup_product_name_callback',
      'wrapper' => 'popup-product-name-label-setting-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['product_details_popup']['popup_product_name_label_wrapper'] = array(
    '#prefix' => '<div id="popup-product-name-label-setting-wrapper">',
    '#suffix' => '</div>',
  );

  // Product quantity display setting.
  $form['product_details_popup']['dc_ajax_add_cart_popup_product_quantity_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Product quantity'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_QUANTITY_DISPLAY, 1),
    '#ajax' => array(
      'callback' => 'dc_ajax_add_cart_popup_product_quantity_callback',
      'wrapper' => 'popup-product-quantity-label-setting-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['product_details_popup']['popup_product_quantity_label_wrapper'] = array(
    '#prefix' => '<div id="popup-product-quantity-label-setting-wrapper">',
    '#suffix' => '</div>',
  );

  // Product price dislpay setting.
  $form['product_details_popup']['dc_ajax_add_cart_popup_product_price_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Product price'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_PRICE_DISPLAY, 1),
    '#ajax' => array(
      'callback' => 'dc_ajax_add_cart_popup_product_price_callback',
      'wrapper' => 'popup-product-price-label-setting-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['product_details_popup']['popup_product_price_label_wrapper'] = array(
    '#prefix' => '<div id="popup-product-price-label-setting-wrapper">',
    '#suffix' => '</div>',
  );

  // Product total display setting.
  $form['product_details_popup']['dc_ajax_add_cart_popup_product_total_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Product total'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_TOTAL_DISPLAY, 1),
    '#disabled' => TRUE,
    '#ajax' => array(
      'callback' => 'dc_ajax_add_cart_popup_product_total_callback',
      'wrapper' => 'popup-product-total-label-setting-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['product_details_popup']['popup_product_total_label_wrapper'] = array(
    '#prefix' => '<div id="popup-product-total-label-setting-wrapper">',
    '#suffix' => '</div>',
  );

  $form['dc_ajax_add_cart_popup_checkout'] = array(
    '#type' => 'textfield',
    '#title' => t('Checkout text'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_CHECKOUT, 'Go to checkout'),
    '#description' => t('Configure the text you want to show in checkout link.'),
  );

  $form['dc_ajax_add_cart_popup_continue_shopping'] = array(
    '#type' => 'textfield',
    '#title' => t('Continue shopping text'),
    '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_CONTINUE_SHOPPING, 'Continue shopping'),
    '#description' => t('Configure the text you want to show in continue shopping link.'),
  );

  // Product name label setting AJAX form.
  if (empty($form_state['values']) && variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_NAME_DISPLAY, 1) == 1) {
    $form['product_details_popup']['popup_product_name_label_wrapper']['dc_ajax_add_cart_popup_product_name_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_NAME_LABEL, 'no_display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product name.'),
    );
  }

  if (!empty($form_state['values']['dc_ajax_add_cart_popup_product_name_display'])
    && $form_state['values']['dc_ajax_add_cart_popup_product_name_display'] == 1) {
    $form['product_details_popup']['popup_product_name_label_wrapper']['dc_ajax_add_cart_popup_product_name_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_NAME_LABEL, 'no_display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product name.'),
    );
  }

  // Product quantity label setting AJAX form.
  if (empty($form_state['values']) && variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_QUANTITY_DISPLAY, 1) == 1) {
    $form['product_details_popup']['popup_product_quantity_label_wrapper']['dc_ajax_add_cart_popup_product_quantity_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_QUANTITY_LABEL, 'display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product quantity.'),
    );
  }

  if (!empty($form_state['values']['dc_ajax_add_cart_popup_product_quantity_display']) && $form_state['values']['dc_ajax_add_cart_popup_product_quantity_display'] == 1) {
    $form['product_details_popup']['popup_product_quantity_label_wrapper']['dc_ajax_add_cart_popup_product_quantity_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_QUANTITY_LABEL, 'display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product quantity.'),
    );
  }

  // Product price label setting AJAX form.
  if (empty($form_state['values']) && variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_PRICE_DISPLAY, 1) == 1) {
    $form['product_details_popup']['popup_product_price_label_wrapper']['dc_ajax_add_cart_popup_product_price_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_PRICE_LABEL, 'display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product price.'),
    );
  }

  if (!empty($form_state['values']['dc_ajax_add_cart_popup_product_price_display']) && $form_state['values']['dc_ajax_add_cart_popup_product_price_display'] == 1) {
    $form['product_details_popup']['popup_product_price_label_wrapper']['dc_ajax_add_cart_popup_product_price_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_PRICE_LABEL, 'display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product price.'),
    );
  }

  // Product total label setting AJAX form.
  if (empty($form_state['values']) && variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_TOTAL_DISPLAY, 1) == 1) {
    $form['product_details_popup']['popup_product_total_label_wrapper']['dc_ajax_add_cart_popup_product_total_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_TOTAL_LABEL, 'display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product total.'),
    );
  }

  if (!empty($form_state['values']['dc_ajax_add_cart_popup_product_total_display']) && $form_state['values']['dc_ajax_add_cart_popup_product_total_display'] == 1) {
    $form['product_details_popup']['popup_product_total_label_wrapper']['dc_ajax_add_cart_popup_product_total_label'] = array(
      '#type' => 'radios',
      '#title' => t('Display label'),
      '#default_value' => variable_get(DC_AJAX_ADD_CART_POPUP_PRODUCT_TOTAL_LABEL, 'display_label'),
      '#options' => array(
        'display_label' => t('Yes'),
        'no_display_label' => t('No'),
      ),
      '#description' => t('Configure whether you want to show label beside product total.'),
    );
  }

  return system_settings_form($form);
}

/**
 * Callback function for rendering name label setting form.
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Current Drupal form state.
 */
function dc_ajax_add_cart_popup_product_name_callback($form, &$form_state) {
  return $form['product_details_popup']['popup_product_name_label_wrapper'];
}

/**
 * Callback function for rendering quantity label setting form.
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Current Drupal form state.
 */
function dc_ajax_add_cart_popup_product_quantity_callback($form, &$form_state) {
  return $form['product_details_popup']['popup_product_quantity_label_wrapper'];
}

/**
 * Callback function for rendering price label setting form.
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Current Drupal form state.
 */
function dc_ajax_add_cart_popup_product_price_callback($form, &$form_state) {
  return $form['product_details_popup']['popup_product_price_label_wrapper'];
}

/**
 * Callback function for rendering total label setting form.
 *
 * @param array $form
 *   Drupal form array.
 *
 * @param array $form_state
 *   Current Drupal form state.
 */
function dc_ajax_add_cart_popup_product_total_callback($form, &$form_state) {
  return $form['product_details_popup']['popup_product_total_label_wrapper'];
}