<?php

namespace Drupal\Tests\dc_ajax_add_cart\Kernel;

use Drupal\Tests\commerce\Kernel\CommerceKernelTestBase;
use Drupal\dc_ajax_add_cart\RefreshPageElementsHelper;
use Drupal\Core\Ajax\AjaxResponse;

/**
 * Tests RefreshPageElementsHelper methods.
 *
 * @coversDefaultClass \Drupal\dc_ajax_add_cart\RefreshPageElementsHelper
 *
 * @ingroup dc_ajax_add_cart
 *
 * @group dc_ajax_add_cart
 */
class RefreshPageElementsHelperTest extends CommerceKernelTestBase {

  /**
   * Modules to install.
   *
   * @var array
   */
  public static $modules = [
    'block',
    'commerce_order',
    'dc_ajax_add_cart',
    'entity_reference_revisions',
    'profile',
    'state_machine',
  ];

  /**
   * The block storage.
   *
   * @var \Drupal\Core\Config\Entity\ConfigEntityStorageInterface
   */
  protected $controller;

  /**
   * Active theme name.
   *
   * @var \Drupal\Core\Theme\ThemeManagerInterface
   */
  protected $activeTheme;

  /**
   * Ajax command names expected to be present in status update ajax response.
   *
   * @var array
   */
  protected $expectedAjaxCommandNamesStatusMessagesUpdate = [
    'remove',
    'insert',
  ];

  /**
   * Ajax command names expected to be present in update cart ajax response.
   *
   * @var array
   */
  protected $expectedAjaxCommandNamesCartBlockUpdate = [
    'insert',
  ];

  /**
   * Ajax command names expected to be present when page elements updated.
   *
   * @var array
   */
  protected $expectedAjaxCommandNamesUpdatePageElements = [
    'remove',
    'insert',
  ];

  /**
   * {@inheritdoc}
   */
  protected function setUp() {
    parent::setUp();

    $this->controller = $this->container->get('entity_type.manager')->getStorage('block');
    $this->activeTheme = $this->container->get('theme.manager')->getActiveTheme();
  }

  /**
   * Asserts whether response is an ajax response.
   *
   * @param object $response
   *   The response to be checked.
   */
  protected function assertAjaxResponse($response) {
    $this->assertTrue($response instanceof AjaxResponse, 'Ajax response is not returned.');
  }

  /**
   * Places status messages block.
   */
  protected function placeStatusMessagesBlock() {
    $entity = $this->controller->create([
      'id' => "{$this->activeTheme->getName()}_messages",
      'theme' => $this->activeTheme->getName(),
      'region' => 'content',
      'plugin' => 'system_messages_block',
    ]);
    $entity->save();
  }

  /**
   * Tests ajax response when status messages block is placed.
   *
   * @covers ::getStatusMessagesBlock
   * @covers ::getResponse
   * @covers ::updateStatusMessages
   */
  public function testAjaxResponseStatusMessagesBlock() {
    $this->placeStatusMessagesBlock();

    $refereshPageElementsHelper = new RefreshPageElementsHelper(new AjaxResponse());
    $response = $refereshPageElementsHelper
      ->updateStatusMessages()
      ->getResponse();
    $this->assertAjaxResponse($response);

    // Check if the returned response has the expected ajax commands.
    $ajax_commands = $response->getCommands();
    $actual_ajax_command_names = array_map(function ($i) {
      return $i['command'];
    }, $ajax_commands);

    foreach ($this->expectedAjaxCommandNamesStatusMessagesUpdate as $ajax_command_name) {
      $this->assertTrue(in_array($ajax_command_name, $actual_ajax_command_names), "$ajax_command_name is not present");
    }
  }

  /**
   * Tests ajax response when status messages block is not placed.
   *
   * @covers ::getStatusMessagesBlock
   * @covers ::getResponse
   * @covers ::updateStatusMessages
   */
  public function testAjaxResponseNoStatusMessagesBlock() {
    $refereshPageElementsHelper = new RefreshPageElementsHelper(new AjaxResponse());
    $response = $refereshPageElementsHelper
      ->updateStatusMessages()
      ->getResponse();
    $this->assertAjaxResponse($response);

    // The returned response should not have the expected ajax commands.
    $ajax_commands = $response->getCommands();
    $actual_ajax_command_names = array_map(function ($i) {
      return $i['command'];
    }, $ajax_commands);

    foreach ($this->expectedAjaxCommandNamesStatusMessagesUpdate as $ajax_command_name) {
      $this->assertFalse(in_array($ajax_command_name, $actual_ajax_command_names), "$ajax_command_name is present");
    }
  }

  /**
   * Tests ajax response when cart block is updated.
   *
   * @covers ::getCartBlock
   * @covers ::updateCart
   * @covers ::getResponse
   */
  public function testAjaxResponseCartBlock() {
    $refereshPageElementsHelper = new RefreshPageElementsHelper(new AjaxResponse());
    $response = $refereshPageElementsHelper
      ->updateCart()
      ->getResponse();
    $this->assertAjaxResponse($response);

    // Check if the returned response has the expected ajax commands.
    $ajax_commands = $response->getCommands();
    $actual_ajax_command_names = array_map(function ($i) {
      return $i['command'];
    }, $ajax_commands);

    foreach ($this->expectedAjaxCommandNamesCartBlockUpdate as $ajax_command_name) {
      $this->assertTrue(in_array($ajax_command_name, $actual_ajax_command_names), "$ajax_command_name is not present");
    }
  }

  /**
   * Tests updatePageElements().
   *
   * @covers ::getStatusMessagesBlock
   * @covers ::updateStatusMessages
   * @covers ::getCartBlock
   * @covers ::updateCart
   * @covers ::getResponse
   */
  public function testAjaxResponseUpdatePageElements() {
    $this->placeStatusMessagesBlock();

    $refereshPageElementsHelper = new RefreshPageElementsHelper(new AjaxResponse());
    $refreshPageElements = $refereshPageElementsHelper
      ->updatePageElements();
    $this->assertInstanceOf(RefreshPageElementsHelper::class, $refreshPageElements, 'Not an instance of RefreshPageElementsHelper');
    $response = $refreshPageElements->getResponse();
    $this->assertAjaxResponse($response);

    // Check if the returned response has the expected ajax commands.
    $ajax_commands = $response->getCommands();
    $actual_ajax_command_names = array_map(function ($i) {
      return $i['command'];
    }, $ajax_commands);

    foreach ($this->expectedAjaxCommandNamesUpdatePageElements as $ajax_command_name) {
      $this->assertTrue(in_array($ajax_command_name, $actual_ajax_command_names), "$ajax_command_name is not present");
    }
  }

}
