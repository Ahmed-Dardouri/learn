/************************ Includes ************************/

#include "Circular_Buffer.h"
#include <string.h>

/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

static uint8_t current_size = 0;
static uint8_t max_size = 0;
static uint8_t buffer[256];
static uint8_t head = 0;
static uint8_t tail = 0;


/******************* Routine Prototypes *******************/

static bool buffer_is_full(void);
static bool buffer_is_empty(void);
static void wrap_index(uint8_t index);

/************************ Routines ************************/

void Circular_Buffer_Init(uint8_t buf_size){
    current_size = 0;
    max_size = buf_size;
    memset(buffer, 0, sizeof(buffer));
    head = 0;
    tail = 0;
}

uint8_t Circular_Buffer_GetSize(void){
    return current_size;
}

uint8_t Circular_Buffer_GetMaxSize(void){
    return max_size;
}

void Circular_Buffer_Push(uint8_t byte){
    if(!buffer_is_full()){
        buffer[head] = byte;
        head++;
        wrap_index(head);
        current_size++;
    }
}

uint8_t Circular_Buffer_Pop(void){
    uint8_t popped_byte = 0x0;
    if(!buffer_is_empty()){
        popped_byte = buffer[tail];
        tail++;
        wrap_index(tail);
        current_size--;
    }
    return popped_byte;
}




static bool buffer_is_full(void){
    return (current_size == Circular_Buffer_GetMaxSize());
}

static bool buffer_is_empty(void){
    return (current_size == 0);
}

static void wrap_index(uint8_t index){
    if(index == Circular_Buffer_GetMaxSize()){
        index = 0;
    }
}