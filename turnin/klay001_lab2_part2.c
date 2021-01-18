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
	DDRB = 0xFF; PORTC = 0x00;
	

	unsigned char cntAvail = 0x00;
	unsigned char tmpA = 0x00;

    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x0F;
	cntAvail = 0x04;


	for(char i = 0; i < 4; ++i){
		if((tmpA % 2 == 1)){
			cntAvail--;
		}
		tmpA = tmpA >> 1; 
	}
	PORTC = cntAvail;

    }
    return 0;
}
