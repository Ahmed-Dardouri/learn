/************************ Includes ************************/

#include "LED_Driver.h"
#include "unity.h"
#include "unity_fixture.h"
#include "RuntimeErrorStub.h"


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

TEST(LedDriver, TurnOnMultipleLeds){
    LED_Driver_TurnOn(8);
    LED_Driver_TurnOn(9);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed){
    LED_Driver_TurnAllOn();
    LED_Driver_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16(0xFEFF, virtualLeds);
}

TEST(LedDriver, TurnOnAll){
    LED_Driver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

TEST(LedDriver, LedMemIsNotReadable){
    LED_Driver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

TEST(LedDriver, UpperAndLowerBound){
    LED_Driver_TurnOn(1);
    LED_Driver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

TEST(LedDriver, OutOfBoundOnChangesNothing){
    LED_Driver_TurnOn(-1);
    LED_Driver_TurnOn(0);
    LED_Driver_TurnOn(17);
    LED_Driver_TurnOn(69);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtualLeds);
}

TEST(LedDriver, OutOfBoundOffChangesNothing){
    LED_Driver_TurnAllOn();
    LED_Driver_TurnOff(-1);
    LED_Driver_TurnOff(0);
    LED_Driver_TurnOff(17);
    LED_Driver_TurnOff(69);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

TEST(LedDriver, OutOfBoundOffProducesRuntimeError){
    LED_Driver_TurnOff(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
}