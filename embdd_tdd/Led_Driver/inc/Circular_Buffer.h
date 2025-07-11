#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

/************************ Includes ************************/

#include <stdint.h>

/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

/******************* Routine Prototypes *******************/

void Circular_Buffer_Init(uint16_t buf_size);
void Circular_Buffer_DeInit(void);
uint16_t Circular_Buffer_GetSize(void);

#endif /* CIRCULAR_BUFFER_H */