/*
 * D0003E_Lab5.c
 *
 * Created: 2020-02-26 16:53:53
 * Author : Mattias
 */ 

#include <avr/io.h>
#include "TinyTimber.h"
#include "LCD.h"


#define BAUD 9600
#define FOSC 8000000UL

//Formula from the documentation.
#define MYUBRR (((FOSC / (BAUD * 16UL))) - 1)




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
	
	//Interrupt request
	EIFR = 0xC0;
	
	//Cause an interrupt
	EIMSK = 0xC0;
	
}


void USARTInit(){
		
		//
		UBRR0H = MYUBRR >> 8;
		UBRR0L = MYUBRR;
		
		//Activate the pin but only on receive.
		UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
		
		//
		UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	
	
}




int main(void)
{
	//Set the inits.
	lcdInit();
	interruptsInit();
	USARTInit();
	
	
	

}

