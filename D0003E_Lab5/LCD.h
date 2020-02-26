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
#include "Controller.h"
#include <stdint.h>




//The public functions.
void northStopLight(Controller* self, int cars);
void southStopLight(Controller* self, int cars);



//Remove when debugging is done.
void printAt(long num, int pos);





#endif /* _LCD_ */