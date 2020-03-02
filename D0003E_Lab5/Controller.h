/*
 * Controller.h
 *
 * Created: 2020-02-26 17:15:21
 *  Author: Mattias
 */ 


#ifndef _CONTROLLER_
#define _CONTROLLER_


//Imports.
#include "avr/io.h"
#include "TinyTimber.h"
#include <stdint.h>



//Object
typedef struct{
	Object super;
	int queueSouth;
	int queueNorth;
} Controller;


//Declarations of Functions.
void sendSignal(Controller* self, uint8_t sigdata);
void trafficLightController(Controller* self, int arg);
void bitParser(Controller* self, uint8_t bits);




#endif /* _CONTROLLER_ */