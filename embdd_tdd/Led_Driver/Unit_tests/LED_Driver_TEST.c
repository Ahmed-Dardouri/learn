/************************ Includes ************************/

#include "LED_Driver.h"
#include "unity.h"
#include "unity_fixture.h"


/*********************** Test Group ***********************/

TEST_GROUP(LedDriver);

/******************** Global Variables ********************/

uint16_t virtualLeds = 0xFFFF;

/************************* Setup  *************************/

TEST_SETUP(LedDriver){
    virtualLeds = 0xFFFF;
    LED_Driver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver){

}

/************************* Tests  *************************/

TEST(LedDriver, LedsOffAfterCreate){
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
TEST(LedDriver, TurnOnLedOne){
    LED_Driver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}
TEST(LedDriver, TurnOffLedOne){
    LED_Driver_TurnOn(1);
    LED_Driver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}