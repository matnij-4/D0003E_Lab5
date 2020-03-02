/*
 * InterruptSignalHandler.h
 *
 * Created: 2020-02-26 17:34:27
 *  Author: Mattias
 */ 


#ifndef _INTERRUPTSIGNALHANDLER_
#define _INTERRUPTSIGNALHANDLER_

//Imports.
#include "TinyTimber.h"
#include "Controller.h"
#include "avr/io.h"
#include <stdint.h>


//Object
typedef struct{
	Object super;
	Controller *controller;
} InterruptSignalHandler;


//Init
#define initInterruptSignalHandler(controller) {initObject(), controller};


//
void receiver(InterruptSignalHandler* self);





#endif /* _INTERRUPTSIGNALHANDLER_ */