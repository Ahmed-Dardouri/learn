#ifndef RUN_ALL_H
#define RUN_ALL_H

/************************ Includes ************************/

#include <stdbool.h>

/************************ Defines  ************************/

/*********************** Data Types ***********************/

typedef struct{
    bool inverted_logic;
} led_driver_test_params_t;


/******************** Global Variables ********************/

/******************* Routine Prototypes *******************/


void RunAllTests(void);
led_driver_test_params_t get_led_driver_test_params(void);

#endif /* RUN_ALL_H */