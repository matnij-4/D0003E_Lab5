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
#include "LCD.h"
#include <stdbool.h>



//Object
typedef struct{
	Object super;
	LCD* lcd;
	int queueSouth;
	int queueNorth;
	int carsOn;
	int carsPassed;
	bool northWasOn;
} Controller;



#define initController(lcd) {initObject(), lcd, 0, 0, 0, 0, false}

//Declarations of Functions.
void sendSignal(Controller* self, uint8_t sigdata);
void trafficLightController(Controller* self, int arg);
void bitParser(Controller* self, uint8_t bits);
void addToBridge(Controller* self, int add);




#endif /* _CONTROLLER_ */