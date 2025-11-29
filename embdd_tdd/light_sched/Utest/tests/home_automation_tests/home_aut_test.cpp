
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

extern "C" {
#include "home_aut.h"
}


TEST_GROUP(HomeAut_TestGroup){ /* setup/teardown if needed */ };


TEST(HomeAut_TestGroup, basic_addition) {
    // Call a function from my_module.h and check results
    LONGS_EQUAL(42, add(40, 2));
}