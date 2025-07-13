/************************ Includes ************************/

#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer){
    RUN_TEST_CASE(CircularBuffer, BufferEmptyAfterInit);
    RUN_TEST_CASE(CircularBuffer, BufferNotEmptyAfterPush);
    RUN_TEST_CASE(CircularBuffer, BufferEmptyyAfterOnePushAndOnePop);
    RUN_TEST_CASE(CircularBuffer, GetMaxSize);
    RUN_TEST_CASE(CircularBuffer, BufferSizeIsEqualToMaxAtFullSize);
    RUN_TEST_CASE(CircularBuffer, CantPushIfBufferFull);
    RUN_TEST_CASE(CircularBuffer, CantPopIfBufferEmpty);
    RUN_TEST_CASE(CircularBuffer, PopReturnsPushedByte);
    RUN_TEST_CASE(CircularBuffer, PopInFifo);
    RUN_TEST_CASE(CircularBuffer, BufferIndexWraps);
    
}