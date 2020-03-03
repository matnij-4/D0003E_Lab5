/*
 * Controller.c
 *
 * Created: 2020-02-26 17:15:11
 *  Author: Mattias
 */ 


#include "Controller.h"

#define REDRED 0xA
#define GREENRED 0x9
#define REDGREEN 0x6

int counter = 0;

//Logic for the Lights.
void trafficLightController(Controller* self, int arg){
	
	//No Cars.
	if((self->queueNorth == 0) && (self->queueSouth == 0)){
		ASYNC(self, sendSignal, REDRED);
		self->carsPassed = 0;
	}
	
	//Cars only North
	else if((self->queueNorth > 0) && (self->queueSouth == 0)){
		if(self->carsOn == 0){
			ASYNC(self, sendSignal, GREENRED);
			self->northWasOn = true;
		}
		else{
			//Mattias Fixa async calls.
			AFTER(SEC(5), self, sendSignal, GREENRED);
		}
		
	}
	
	//Cars only South.
	else if((self->queueNorth == 0) && (self->queueSouth > 0)){
		if(self->carsOn == 0){
			ASYNC(self, sendSignal, REDGREEN);
			self->northWasOn = false;
		}
		else{
			//Mattias Fixa async calls.
			AFTER(SEC(5), self, sendSignal, REDGREEN);
		}
		
	}
	
	
	//Do not starve South.
	else if(self->carsPassed > 4 &&  self->northWasOn){
		self->northWasOn = false;
		self->carsPassed = 0;
		ASYNC(self, sendSignal, REDRED);
		

		AFTER(SEC(5), self, sendSignal, REDGREEN);

		
	}
	
	//Do not starve North.
	else if(self->carsPassed > 4 && !(self->northWasOn)){
		self->northWasOn = true;
		self->carsPassed = 0;
		ASYNC(self, sendSignal, REDRED);
		
		
		AFTER(SEC(5), self, sendSignal, GREENRED);
	}
}


//Send signals to SYM.
void sendSignal(Controller* self, uint8_t sigdata){
	
	//Send to LCD.
	ASYNC(self, printStopLight, sigdata);
	
	//Send to Sym.
	UDR0 = sigdata;
}



void addToBridge(Controller* self, int add){
	
	//Add Car to the bridge.
	if(add == 1){
		SYNC(self->lcd, carsOnBridge, self->carsOn);
		AFTER(SEC(5), self, addToBridge, 0);
	}
	
	//Remove the Cars from bridge.
	else if(add == 0){
		self->carsOn--;
		SYNC(self->lcd, carsOnBridge, self->carsOn);
	}
	
	
}



//Pars the bits and reads them.
void bitParser(Controller* self, uint8_t bits){
	
	//Northbound Car Arrival.
	if((bits & 1 ) == 1){
		ASYNC(self, trafficLightController, 0);
		self->queueNorth++;
		
		//Update Stoplight.
		ASYNC(self->lcd, northStopLight, self->queueNorth);
	}
	
	//North car enters the bridge.
	else if(((bits >> 1) & 1) == 1){
		if(self->queueNorth > 0){
			self->queueNorth--;
			self->carsOn++;
			ASYNC(self, trafficLightController, 0);
			ASYNC(self, addToBridge, 1);
			ASYNC(self->lcd, northStopLight, self->queueNorth);
			
			//Adds car to passed.
			self->carsPassed++;
		}
		
	}
	
	//Southbound Car Arrival.
	else if(((bits >> 2) & 1) == 1){
		ASYNC(self, trafficLightController, 0);
		self->queueSouth++;
		
		//Update Stoplight.
		ASYNC(self->lcd, southStopLight, self->queueSouth);
	}
	
	//South car enters the bridge.
	else if(((bits >> 3) & 1) == 1){
		if(self->queueSouth > 0){
			self->queueSouth--;
			self->carsOn++;
			ASYNC(self, trafficLightController, 0);
			ASYNC(self, addToBridge, 1);
			ASYNC(self->lcd, southStopLight, self->queueSouth);
			
			//Adds car to passed.
			self->carsPassed++;
		}
		
	}
	
}








