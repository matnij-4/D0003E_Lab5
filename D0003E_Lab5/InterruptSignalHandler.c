/*
 * InterruptSignalHandler.c
 *
 * Created: 2020-02-26 17:34:35
 *  Author: Mattias
 */ 

#include "InterruptSignalHandler.h"


void receivedUSART(InterruptSignalHandler* self){
	uint8_t bits = UDR0;
	ASYNC(self->controller, bitParser, bits);
}