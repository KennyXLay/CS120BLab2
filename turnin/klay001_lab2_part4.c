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
	DDRB = 0x00; PORTB = 0xFF; //setup as inputs.
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00; //Setup as an output.

	unsigned short tmpA = 0x00;
	unsigned short tmpB = 0x00;
	unsigned short tmpC = 0x00;
	unsigned short total = 0x00;

    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x0F;
	tmpB = PINB & 0x0F;
	tmpC = PINC & 0X0F;
	
	total = tmpA + tmpB + tmpC;
	if(total > 140){ //If the sum of A+B+C< 140
		PORTD = PORTD | 0x01;
	}
	if((tmpC - tmpA) < 80){ //If the difference between A and C is > 80 kg.
        	PORTD = PORTD | 0x02;
        }

	PORTD = (PORTD << 2) | total;
    }
    return 0;
}
