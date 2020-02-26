/*
 * LCD.h
 *
 * Created: 2020-02-26 16:55:24
 *  Author: Mattias
 */ 


#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>
#include <stdbool.h>
#include "TinyTimber.h"
#include "Controller.h"
#include <stdint.h>





void northStopLight(Controller* self, int arg);
void southStopLight(Controller* self, int arg);






#endif /* LCD_H_ */