/*
 * Controller.c
 *
 * Created: 2020-02-26 17:15:11
 *  Author: Mattias
 */ 


#include "Controller.h"



void trafficLightController(Controller* self, int arg){
	
}



void sendSignal(Controller* self, uint8_t sigdata){
	
}



void bitParser(Controller* self, uint8_t bits){
	
	//Northbound Car Arrival.
	if((bits & 1 ) == 1){
		ASYNC(self, trafficLightController, 0);
		self->queueNorth++;
	}
	
	//North car enters the bridge.
	else if(((bits >> 1) & 1) == 1){
		if(self->queueNorth > 0){
			self->queueNorth--;
			ASYNC(self, trafficLightController, 0);
		}
		
	}
	
	//Southbound Car Arrival.
	else if(((bits >> 2) & 1) == 1){
		ASYNC(self, trafficLightController, 0);
		self->queueSouth++;
	}
	
	//South car enters the bridge.
	else if(((bits >> 3) & 1) == 1){
		if(self->queueSouth > 0){
			self->queueSouth--;
			ASYNC(self, trafficLightController, 0);
		}
		
	}
	
}








