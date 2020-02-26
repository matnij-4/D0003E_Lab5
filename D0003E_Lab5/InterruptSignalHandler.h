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


//Object
typedef struct{
	Object super;
	Controller *controller;
} InterruptSignalHandler;



//
void receiver(InterruptSignalHandler* self);





#endif /* _INTERRUPTSIGNALHANDLER_ */