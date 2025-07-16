#ifndef LED_DRIVER_H
#define LED_DRIVER_H

/************************ Includes ************************/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

/******************* Routine Prototypes *******************/

void LED_Driver_Create(uint16_t * led_reg, bool inverted_logic);
bool LED_Driver_GetInvertedLogic(void);
void LED_Driver_TurnOn(uint8_t led_num);
void LED_Driver_TurnOff(uint8_t led_num);
void LED_Driver_TurnAllOn(void);
void LED_Driver_TurnAllOff(void);
bool LED_Driver_IsOn(uint8_t led_num);
bool LED_Driver_IsOff(uint8_t led_num);

#endif