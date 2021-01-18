/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0XFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char garageSensor = 0x00;	
	unsigned char lightSensor = 0x00;
	unsigned char lightSwitch = 0x00;
    /* Insert your solution below */
    while (1) {
	garageSensor = PINA & 0x01;
	lightSensor = PINA & 0x02;

	if(garageSensor && !lightSensor){
		lightSwitch = 0x01;
	}
	else{
		lightSwitch = 0x00; 
	}
	PORTB = lightSwitch;
    }
    return 0;
}
