[![Build Status](https://travis-ci.org/subhojit777/dc_ajax_add_cart.svg?branch=8.x-1.x)](https://travis-ci.org/subhojit777/dc_ajax_add_cart)

Using this module you can ajaxify the add to cart operation. The updated cart
will be displayed without page refresh and a popup message will be shown after
you add an item to cart.

## `8.x`

### Features:
- *Ajax add to cart form* as a product variation display formatter
- *Ajax product removal from cart* as a views field
- *Ajax update cart* as a views field
- *Ajax confirmation popup* on adding a product variation to cart. This is available as a product variation display.

### Installation and usage:
- Install the module in a Drupal Commerce installation. Steps for installing
  module in Drupal can be found [here](https://www.drupal.org/docs/8/extending-drupal-8/installing-drupal-8-modules).
- Go to `admin/commerce/config/product-types/default/edit/display`, select
  **Ajax add to cart** form format for `Variations`.
- If you want the ability to remove product from cart *ajax-ifically*, OR
  update the cart *ajax-ifically*, enable `dc_ajax_add_cart_views` module.
  This is provided as a sub-module.
- Edit the cart view, add field *Remove button (Ajax)*, for ajax removal of
  product from cart.
- Edit the cart view, add field *Quantity text field (Ajax)*, for ajax update
  of cart.
- If you want *add to cart* confirmation messages to appear in a modal popup, enable the
  `dc_ajax_add_cart_popup` module. This is provided as a sub-module. Go to
  `admin/commerce/config/product-variation-types/default/edit/display`, check
  **Ajax add to cart popup** under `Custom Display Settings`, and click `Save`.

### Known issues:
- [Throbber message appears twice on multiple update cart operation](https://www.drupal.org/project/dc_ajax_add_cart/issues/2941531)
- [Update cart feedback message does not stays on update cart operation](https://www.drupal.org/project/dc_ajax_add_cart/issues/2941532)

## `7.x`

### Features:
- Shopping cart block (minified version of cart page), that updates every time
  you add product to cart.
- Remove product from cart through AJAX
- Pop up message will appear showing the current item you have added to cart.
- Update product quantity in cart itself

### Installation and usage:
- Install the module in a Drupal Commerce installation. Steps for installing
  module in Drupal can be found
  [here](http://drupal.org/documentation/install/modules-themes/modules-7).
- Go to blocks page `admin/structure/block` and place the blocks called
  **AJAX shopping cart** and **AJAX shopping cart teaser** in desired regions.
  If you are working on
  [Commerce Kickstart](https://www.drupal.org/project/commerce_kickstart)
  distribution and have "Commerce Kickstart Theme" as the default theme then it
  would be best if you put block "AJAX shopping cart" in "Sidebar Second" region
  and AJAX Custom shopping cart teaser" in "User Bar Second" region. Remove the
  default block from "User Bar Second" region.
- This module provides a popup message that the product item has been
  successfully added to cart. By default Commerce Kickstart distribution also
  provides a similar kind of popup message that appears on page refresh. You can
  disable the default popup message if you disable this rule:
  "Kickstart Add to Cart message".
- This module provides template files to provide further customizations. Copy
  the template files in theme's templates directory and make desired changes.
- Configuration of the module can be found on this page
  `admin/commerce/config/ajax-cart`.

## How it is different from other related modules:
- [Commerce Cart Ajax](https://www.drupal.org/project/dc_cart_ajax) - This
  module ajax-ifies only cart page. It does not ajax-ifies the teaser cart
  block. However, this module provides ajax-ified cart block and teaser cart
  block, and you can place them anywhere.
- [Commerce Ajax Cart](https://www.drupal.org/project/commerce_ajax_cart) - This
  module ajax-ifies only the teaser cart block.

You can implement ajax cart using these two modules (with some customizations as
per your need). But "Commerce Ajax Add to Cart" provides ajax cart out of the
box, and also you can customize its appearance.

Credits:
----------
Icons taken fron http://iconfinder.com
