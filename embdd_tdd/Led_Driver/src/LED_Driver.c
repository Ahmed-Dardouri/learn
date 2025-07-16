/************************ Includes ************************/

#include "LED_Driver.h"
#include "RuntimeError.h"

/************************ Defines  ************************/

#define LEDS_ALL_OFF        (uint16_t)0x0000
#define LEDS_ALL_ON         (uint16_t)0xFFFF

#define FIRST_LED           1
#define LAST_LED            16

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

static uint16_t * leds_address;
static uint16_t leds_image;
static bool _inverted_logic = false;
/******************* Routine Prototypes *******************/

static uint16_t convertLedIndexToBitMask(uint8_t led_index);
static void update_hardware(void);
static bool isLedOutOfBound(uint8_t led_num);
static void setLedImageBit(uint8_t led_num);
static void clearLedImageBit(uint8_t led_num);

/************************ Routines ************************/

void LED_Driver_Create(uint16_t * led_reg, bool inverted_logic){
    leds_address = led_reg;
    leds_image = LEDS_ALL_OFF;
    _inverted_logic = inverted_logic;
    update_hardware();
}

bool LED_Driver_GetInvertedLogic(void){
    return _inverted_logic;
}


void LED_Driver_TurnOn(uint8_t led_num){
    if(isLedOutOfBound(led_num)){
        RUNTUME_ERROR("LED Driver: out-of-bounds LED", RUNTIME_ERROR_DEFAULT_PARAM);
        return;
    }
    setLedImageBit(led_num);
    update_hardware();
}

void LED_Driver_TurnOff(uint8_t led_num){
    if(isLedOutOfBound(led_num)){
        RUNTUME_ERROR("LED Driver: out-of-bounds LED", RUNTIME_ERROR_DEFAULT_PARAM);
        return;
    }
    clearLedImageBit(led_num);
    update_hardware();
}

void LED_Driver_TurnAllOn(void){
    leds_image = LEDS_ALL_ON;
    update_hardware();
}

void LED_Driver_TurnAllOff(void){
    leds_image = LEDS_ALL_OFF;
    update_hardware();
}

bool LED_Driver_IsOn(uint8_t led_num){
    if(isLedOutOfBound(led_num)){
        return false;
    }
    return leds_image & convertLedIndexToBitMask(led_num);
}

bool LED_Driver_IsOff(uint8_t led_num){
    return !LED_Driver_IsOn(led_num);
}

static uint16_t convertLedIndexToBitMask(uint8_t led_index){
    return (1 << (led_index - 1));
}

static void update_hardware(void){
    if(_inverted_logic == true){
        *leds_address = (uint16_t)~leds_image;    
    }
    else{
        *leds_address = leds_image;
    }
}

static bool isLedOutOfBound(uint8_t led_num){
    bool led_out_of_bound = false;
    if(led_num < FIRST_LED || led_num > LAST_LED){
        led_out_of_bound = true;
    }
    return led_out_of_bound;
}

static void setLedImageBit(uint8_t led_num){
    leds_image |= convertLedIndexToBitMask(led_num);
}

static void clearLedImageBit(uint8_t led_num){
    leds_image &= ~convertLedIndexToBitMask(led_num);
}