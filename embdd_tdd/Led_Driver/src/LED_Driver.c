/************************ Includes ************************/

#include "LED_Driver.h"
#include "RuntimeError.h"
/************************ Defines  ************************/

#define LEDS_ALL_OFF        (uint16_t)0x0000
#define LEDS_ALL_ON         (uint16_t)0xFFFF

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

static uint16_t * leds_address;
static uint16_t leds_image;

/******************* Routine Prototypes *******************/

static uint16_t convertLedIndexToBitMask(uint8_t led_index);
static void update_hardware(void);

/************************ Routines ************************/

void LED_Driver_Create(uint16_t * led_reg){
    leds_address = led_reg;
    leds_image = LEDS_ALL_OFF;
    update_hardware();
}

void LED_Driver_TurnOn(uint8_t led_num){
    if(led_num <= 0 || led_num >= 17){
        return;
    }
    leds_image |= convertLedIndexToBitMask(led_num);
    update_hardware();
}

void LED_Driver_TurnOff(uint8_t led_num){
    if(led_num <= 0 || led_num >= 17){
        RUNTUME_ERROR("LED Driver: out-of-bounds LED", -1);
        return;
    }
    leds_image &= ~convertLedIndexToBitMask(led_num);
    update_hardware();
}

void LED_Driver_TurnAllOn(void){
    leds_image = 0xFFFF;
    update_hardware();
}



static uint16_t convertLedIndexToBitMask(uint8_t led_index){
    return (1 << (led_index - 1));
}

static void update_hardware(void){
    *leds_address = leds_image;
}