#include "unity_fixture.h"
#include "run_all.h"

led_driver_test_params_t led_driver_test_params;

void RunAllTests(void){
  led_driver_test_params.inverted_logic = false;
  RUN_TEST_GROUP(LedDriver);
  led_driver_test_params.inverted_logic = true;
  RUN_TEST_GROUP(LedDriver);
  RUN_TEST_GROUP(CircularBuffer);
}

led_driver_test_params_t get_led_driver_test_params(void){
  return led_driver_test_params;
}