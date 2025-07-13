/************************ Includes ************************/

#include "RuntimeErrorStub.h"
#include "RuntimeError.h"
/************************ Defines  ************************/

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

static const char * message = "no error";
static int parameter = -1;
static const char * file = 0;
static int line = -1;

/******************* Routine Prototypes *******************/

/************************ Routines ************************/

void RuntimeErrorStub_Reset(void){
    message = "no error";
    parameter = -1;
}

const char * RuntimeErrorStub_GetLastError(void){
    return message;

}

int RuntimeErrorStub_GetLastParameter(void){
    return parameter;
}

void RuntimeError(const char * m, int p, const char * f, int l){
    message = m;
    parameter = p;
    file = f;
    line = l; 
}

