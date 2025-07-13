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

}

/************************* Tests  *************************/

TEST(CircularBuffer, BufferEmptyAfterInit){
    TEST_ASSERT_EQUAL_UINT16(0, Circular_Buffer_GetSize());
}

TEST(CircularBuffer, BufferNotEmptyAfterPush){
    Circular_Buffer_Push(15);
    TEST_ASSERT_EQUAL_UINT16(1, Circular_Buffer_GetSize());
}

TEST(CircularBuffer, BufferEmptyyAfterOnePushAndOnePop){
    Circular_Buffer_Push(15);
    (void)Circular_Buffer_Pop();
    TEST_ASSERT_EQUAL_UINT16(0, Circular_Buffer_GetSize());
}

TEST(CircularBuffer, GetMaxSize){
    Circular_Buffer_Init(50);
    TEST_ASSERT_EQUAL_UINT16(50, Circular_Buffer_GetMaxSize());
}

TEST(CircularBuffer, BufferSizeIsEqualToMaxAtFullSize){
     Circular_Buffer_Init(17);
    while(Circular_Buffer_GetSize () < Circular_Buffer_GetMaxSize()){
        Circular_Buffer_Push(0x15);
    }
    TEST_ASSERT_EQUAL_UINT16(Circular_Buffer_GetMaxSize(), Circular_Buffer_GetSize());
}

TEST(CircularBuffer, CantPushIfBufferFull){
    Circular_Buffer_Init(5);
    while(Circular_Buffer_GetSize () < Circular_Buffer_GetMaxSize()){
        Circular_Buffer_Push(0x15);
    }
    Circular_Buffer_Push(0x15);
    TEST_ASSERT_EQUAL_UINT16(Circular_Buffer_GetMaxSize(), Circular_Buffer_GetSize());
}

TEST(CircularBuffer, CantPopIfBufferEmpty){
    Circular_Buffer_Init(5);
    (void)Circular_Buffer_Pop();
    TEST_ASSERT_EQUAL_UINT16(0, Circular_Buffer_GetSize());
}

TEST(CircularBuffer, PopReturnsPushedByte){
    uint8_t byte_to_push = 0x15;
    Circular_Buffer_Init(5);
    Circular_Buffer_Push(byte_to_push);
    
    TEST_ASSERT_EQUAL_UINT16(byte_to_push, Circular_Buffer_Pop());
}

TEST(CircularBuffer, PopInFifo){
    uint8_t byte_to_push = 0x15;
    Circular_Buffer_Init(5);
    for( uint8_t i = 0; i < Circular_Buffer_GetMaxSize(); i++){
        Circular_Buffer_Push(byte_to_push + i);    
    }
    for( uint8_t i = 0; i < Circular_Buffer_GetMaxSize(); i++){
        TEST_ASSERT_EQUAL_UINT16(byte_to_push + i, Circular_Buffer_Pop());
    }
}
TEST(CircularBuffer, BufferIndexWraps){
    uint8_t byte_to_push = 0x15;
    Circular_Buffer_Init(5);
    Circular_Buffer_Push(byte_to_push);
    Circular_Buffer_Pop();
    for(uint8_t lap = 0; lap < 3; lap++){
        for( uint8_t i = 0; i < Circular_Buffer_GetMaxSize(); i++){
            Circular_Buffer_Push(byte_to_push + i);    
        }
        for( uint8_t i = 0; i < Circular_Buffer_GetMaxSize(); i++){
            TEST_ASSERT_EQUAL_UINT16(byte_to_push + i, Circular_Buffer_Pop());
        }
    }
}