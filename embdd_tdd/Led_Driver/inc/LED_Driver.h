#ifndef LED_DRIVER_H
#define LED_DRIVER_H

/************************ Includes ************************/

#include <stdint.h>
#include <stddef.h>
/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

/******************* Routine Prototypes *******************/

void LED_Driver_Create(uint16_t * led_reg);
void LED_Driver_TurnOn(uint8_t led_num);
void LED_Driver_TurnOff(uint8_t led_num);

#endif