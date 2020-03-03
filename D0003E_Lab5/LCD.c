/*
 * LCD.c
 *
 * Created: 2020-02-26 16:55:03
 *  Author: Mattias
 */ 

//Includes.
#include "LCD.h"
#include "Controller.h"




//Will write the Char on the screen as position pos.
void writeChar(char ch, int pos)
{
	
	//The Address to the first position on the LCD.
	uint8_t *lcdaddr = (uint8_t *) 0xec;
	
	//Mask to get only the nibble of a value.
	uint8_t mask;
	
	//Nibbel the number that is sent to the LCD.
	uint8_t nibbleNumber = 0x0;
	
	
	//SCC Table with the numbers from 0 to 9.
	uint16_t sccTable[10] = {0x1551, 0x0110, 0x1e11, 0x1B11, 0x0B50, 0x1B41, 0x1F41, 0x0111, 0x1F51, 0x0B51};
	
	
	// Check if position is outside or not.
	if (pos < 0 || pos > 5) {
		return;
	}
	
	// The number to print.
	uint16_t number = 0x0;
	
	// Check if it is a 0 to 9.
	if (ch >= '0' || ch <= '9')
	{
		//Get the number out of the array.
		number = sccTable[ch - '0'];
	}
	
	
	//Point to the right position. Divide by 2 you can say.
	lcdaddr += pos >> 1;
	
	
	//Check if it is odd or even position.
	if (pos % 2 == 0)
	{
		mask = 0xf0;
	}
	else
	{
		mask = 0x0f;
	}
	
	
	//Will place out the nibbles on the right LCD address for the number.
	for (int i = 0; i < 4; i++ )
	{
		//Masking the smallest byte.
		nibbleNumber = number & 0xf;
		number = number >> 4;
		
		
		//Check position.
		if(pos % 2 != 0)
		{
			//Shift the nibble to the right pos.
			nibbleNumber = nibbleNumber << 4;
		}
		
		//Send the nibble.
		*lcdaddr = (*lcdaddr & mask) | nibbleNumber;
		
		lcdaddr += 5;
		
	}
	
}


//Prints number at position.
void printAt(long num, int pos) {
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}


//Print the red light at North.
void northStopLight(LCD* self, int cars){
	printAt(cars,4);
	
	
}


//Print the red light at South.
void southStopLight(LCD* self, int cars){
	printAt(cars, 0);
}

void carsOnBridge(LCD* self, int cars){
	printAt(cars, 2);
}

void printStopLight(LCD* self, int light){
	if(light == 0xa){
		LCDDR3 = 0x1;
		LCDDR18 = 0x1;
	}
	else if (light == 0x9){
		LCDDR3 = 0x0;
		LCDDR18 = 0x1;
	}
	else if(light == 0x6){
		LCDDR3 = 0x1;
		LCDDR18 = 0x0;
	}
}