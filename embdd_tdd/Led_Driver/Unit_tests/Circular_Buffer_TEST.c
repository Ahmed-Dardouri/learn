/************************ Includes ************************/

#include "Circular_Buffer.h"
#include "unity.h"
#include "unity_fixture.h"


/*********************** Test Group ***********************/

TEST_GROUP(CircularBuffer);

/******************** Global Variables ********************/

/************************* Setup  *************************/

TEST_SETUP(CircularBuffer){
    Circular_Buffer_Init(10);
}

TEST_TEAR_DOWN(CircularBuffer){
    Circular_Buffer_DeInit();

}

/************************* Tests  *************************/

TEST(CircularBuffer, BufferEmptyAfterInit){
    uint16_t buf_size = 50000;
    buf_size = Circular_Buffer_GetSize();
    TEST_ASSERT_EQUAL_UINT16(0, buf_size);
}
