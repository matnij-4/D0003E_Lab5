/*
 * D0003E_Lab5.c
 *
 * Created: 2020-02-26 16:53:53
 * Author : Mattias
 */ 

#include <avr/io.h>
#include "TinyTimber.h"
#include "LCD.h"


void lcdInit(){
	
	//Set Low power Waveform, no frame interrupt, no blanking. LCD Enable
	LCDCRA = (0 << LCDAB) | (1 << LCDEN);
	
	//drive time 300 microseconds, contrast control voltage 3.35 V.
	LCDCCR = (1 << LCDCC0) | (1 << LCDCC1) | (1 << LCDCC2) | (1 << LCDCC3);
	
	//external asynchronous clock source, 1/3 bias, 1/4 duty cycle, 25 segments.
	LCDCRB = (1 << LCDCS) | (1<< LCDMUX0) | (1<< LCDMUX1) | (1 <<LCDPM0) | (1 <<LCDPM1) | (1 <<LCDPM2);
	
	//prescaler setting N=16, clock divider setting D=8
	LCDFRR = (1 << LCDCD0) | (1 << LCDCD1) | (1 << LCDCD2);
	
}

void interruptsInit(){
	
	//Enable Interrupts
	EIMSK |= (1 << PCIE1) | (1 << PCIE0);
}


void signalInit(){
	
	
}




int main(void)
{
	//Set the init.
	lcdInit();
	interruptsInit();
	signalInit();
	
	
	

}

