/*
 * LCD.h
 *
 * Created: 2020-02-26 16:55:24
 *  Author: Mattias
 */ 


#ifndef _LCD_
#define _LCD_

//Imports.
#include <avr/io.h>
#include <stdbool.h>
#include "TinyTimber.h"
#include <stdint.h>


//Object.
typedef struct{
	Object super;
} LCD;



//Constructor
#define initLCD() {initObject()}


//The public functions.
void northStopLight(LCD* self, int cars);
void southStopLight(LCD* self, int cars);
void carsOnBridge(LCD* self, int cars);
void printStopLight(LCD* self, int cars);



//Remove when debugging is done.
void printAt(long num, int pos);





#endif /* _LCD_ */