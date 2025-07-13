#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

/************************ Includes ************************/

#include <stdint.h>
#include <stdbool.h>

/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

/******************* Routine Prototypes *******************/

void Circular_Buffer_Init(uint8_t buf_size);
uint8_t Circular_Buffer_GetSize(void);
uint8_t Circular_Buffer_GetMaxSize(void);
void Circular_Buffer_Push(uint8_t);
uint8_t Circular_Buffer_Pop(void);

#endif /* CIRCULAR_BUFFER_H */