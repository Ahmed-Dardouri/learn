
#include <CppUTest/TestHarness.h>

extern "C" {
    
#include "home_aut.h"

}


TEST_GROUP(LightScheduler){ /* setup/teardown if needed */ };


TEST(LightScheduler, NoChangeToLightsDuringInit) {
    // Call a function from my_module.h and check results
    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}



