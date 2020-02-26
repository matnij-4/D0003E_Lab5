/*
 * Controller.h
 *
 * Created: 2020-02-26 17:15:21
 *  Author: Mattias
 */ 


#ifndef CONTROLLER_H_
#define CONTROLLER_H_


//Imports.
#include "avr/io.h"
#include "TinyTimber.h"



//Object
typedef struct{
	Object super;
	int queueSouth;
	int queueNorth;
} Controller;


void sendSignal(Controller* self, uint8_t sigdata);
void trafficLightController(Controller* self, int arg);




#endif /* CONTROLLER_H_ */