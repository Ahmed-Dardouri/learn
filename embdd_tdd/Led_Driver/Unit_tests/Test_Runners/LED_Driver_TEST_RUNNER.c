/************************ Includes ************************/

#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver){
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnOnLedOne);
    RUN_TEST_CASE(LedDriver, TurnOffLedOne);
    RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
    RUN_TEST_CASE(LedDriver, TurnOffMultipleLeds);
    RUN_TEST_CASE(LedDriver, TurnOnAll);
    RUN_TEST_CASE(LedDriver, TurnOffAll);
    RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(LedDriver, LedMemIsNotReadable);
    RUN_TEST_CASE(LedDriver, UpperAndLowerBound);
    RUN_TEST_CASE(LedDriver, OutOfBoundOnChangesNothing);
    RUN_TEST_CASE(LedDriver, OutOfBoundOffChangesNothing);
    RUN_TEST_CASE(LedDriver, OutOfBoundOffProducesRuntimeError);
    RUN_TEST_CASE(LedDriver, OutOfBoundOnProducesRuntimeError);
    RUN_TEST_CASE(LedDriver, IgnoredToDo);
    RUN_TEST_CASE(LedDriver, IsOn);
    RUN_TEST_CASE(LedDriver, IsOff);
    RUN_TEST_CASE(LedDriver, OutOfBoundLedsALwaysOff);
}