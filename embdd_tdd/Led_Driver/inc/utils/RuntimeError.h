#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

/************************ Includes ************************/

/************************ Defines  ************************/
#define RUNTIME_ERROR_DEFAULT_PARAM         -1
#define RUNTUME_ERROR(description, parameter) \
    RuntimeError(description, parameter, __FILE__, __LINE__)

/*********************** Data Types ***********************/

/******************** Global Variables ********************/

/******************* Routine Prototypes *******************/

 
void RuntimeError(const char * message, int parameter, const char * file, int line);
#endif /* RUNTIME_ERROR_H */