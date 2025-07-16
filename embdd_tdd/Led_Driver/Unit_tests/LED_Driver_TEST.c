/************************ Includes ************************/

#include "LED_Driver.h"
#include "unity.h"
#include "unity_fixture.h"
#include "RuntimeErrorStub.h"
#include "run_all.h"

/*********************** Test Group ***********************/

TEST_GROUP(LedDriver);

/******************** Global Variables ********************/

static uint16_t virtualLeds = 0xFFFF;
led_driver_test_params_t params;


/*************** Helper Routine Prototypes ****************/

static uint16_t FlipNumBasedOnSettings(uint16_t num);
static void GetTestParams(void);


/************************* Setup  *************************/

TEST_SETUP(LedDriver){
    virtualLeds = 0xFFFF;
    GetTestParams();
    RuntimeErrorStub_Reset();
    LED_Driver_Create(&virtualLeds, params.inverted_logic);
}

TEST_TEAR_DOWN(LedDriver){

}

/******************** Helper Routines *********************/

static uint16_t FlipNumBasedOnSettings(uint16_t num){
    if(LED_Driver_GetInvertedLogic()){
        return (uint16_t)(~num);
    }
    return num;
}

static void GetTestParams(void){
    params = get_led_driver_test_params();
}

/************************* Tests  *************************/

TEST(LedDriver, InvertedLogicSetCorrectly){
    char msg[64];
    snprintf(msg, sizeof(msg), "inverted logic: %d", params.inverted_logic);
    TEST_MESSAGE(msg);
    TEST_ASSERT_EQUAL(params.inverted_logic, LED_Driver_GetInvertedLogic());
}


TEST(LedDriver, LedsOffAfterCreate){
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0), virtualLeds);
}
TEST(LedDriver, TurnOnLedOne){
    LED_Driver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(1), virtualLeds);
}
TEST(LedDriver, TurnOffLedOne){
    LED_Driver_TurnOn(1);
    LED_Driver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0), virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds){
    LED_Driver_TurnOn(8);
    LED_Driver_TurnOn(9);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0x180), virtualLeds);
}

TEST(LedDriver, TurnOffMultipleLeds){
    LED_Driver_TurnAllOn();
    LED_Driver_TurnOff(9);
    LED_Driver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings((~0x180)&0xffff), virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed){
    LED_Driver_TurnAllOn();
    LED_Driver_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0xFEFF), virtualLeds);
}

TEST(LedDriver, TurnOnAll){
    LED_Driver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0xFFFF), virtualLeds);
}

TEST(LedDriver, TurnOffAll){
    LED_Driver_TurnAllOn();
    LED_Driver_TurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0),virtualLeds);
}

TEST(LedDriver, LedMemIsNotReadable){
    LED_Driver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0x80), virtualLeds);
}

TEST(LedDriver, UpperAndLowerBound){
    LED_Driver_TurnOn(1);
    LED_Driver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0x8001), virtualLeds);
}

TEST(LedDriver, OutOfBoundOnChangesNothing){
    LED_Driver_TurnOn(-1);
    LED_Driver_TurnOn(0);
    LED_Driver_TurnOn(17);
    LED_Driver_TurnOn(69);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0x0), virtualLeds);
}

TEST(LedDriver, OutOfBoundOffChangesNothing){
    LED_Driver_TurnAllOn();
    LED_Driver_TurnOff(-1);
    LED_Driver_TurnOff(0);
    LED_Driver_TurnOff(17);
    LED_Driver_TurnOff(69);
    TEST_ASSERT_EQUAL_HEX16(FlipNumBasedOnSettings(0xFFFF), virtualLeds);
}

TEST(LedDriver, OutOfBoundOffProducesRuntimeError){
    LED_Driver_TurnOff(17);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
}

TEST(LedDriver, OutOfBoundOnProducesRuntimeError){
    LED_Driver_TurnOn(0);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
}

IGNORE_TEST(LedDriver, IgnoredToDo){
    /* TODO: smg */
}

TEST(LedDriver, IsOn){
    TEST_ASSERT_FALSE(LED_Driver_IsOn(10));
    LED_Driver_TurnOn(10);
    TEST_ASSERT_TRUE(LED_Driver_IsOn(10));
}

TEST(LedDriver, IsOff){
    TEST_ASSERT_TRUE(LED_Driver_IsOff(5));
    LED_Driver_TurnOn(5);
    TEST_ASSERT_FALSE(LED_Driver_IsOff(5));
}

TEST(LedDriver, OutOfBoundLedsALwaysOff){
    TEST_ASSERT_TRUE(LED_Driver_IsOff(0));
    TEST_ASSERT_TRUE(LED_Driver_IsOff(17));
    TEST_ASSERT_FALSE(LED_Driver_IsOn(0));
    TEST_ASSERT_FALSE(LED_Driver_IsOn(17));
}
