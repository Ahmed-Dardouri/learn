/************************ Includes ************************/

#include "LED_Driver.h"

/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

static uint16_t * leds_address = NULL;

/******************* Routine Prototypes *******************/

/************************ Routines ************************/

void LED_Driver_Create(uint16_t * led_reg){
    leds_address = led_reg;
    *leds_address = 0;
}

void LED_Driver_TurnOn(uint8_t led_num){
    *leds_address = 1;
}

void LED_Driver_TurnOff(uint8_t led_num){
    *leds_address = 0;
}