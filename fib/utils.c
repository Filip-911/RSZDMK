/*
 * utils.c
 *
 *  Created on: May 10, 2021
 *      Author: Korisnik
 */
#include "utils.h"

volatile unsigned char desetka = 0; // broji blokove od 10us


void timer0InterruptInit () // generise prekid svakih 10us
{
	TCCR0A = 0x02;
	TCCR0B = 0x01;
	OCR0A = 159;
	TIMSK0 = 0x02;
	sei();
}

void pinInit (char port, char pin, char dir)
{
	switch (port)
	{
		case PORT_B:
			if(dir == OUTPUT)
				DDRB |=  1 << pin ;
			else
				DDRB &= ~(1 << pin);
		break;

		case PORT_C:
			if(dir == OUTPUT)
				DDRC |= 1 << pin ;
			else
				DDRC &= ~(1 << pin);
		break;

		case PORT_D:
			if(dir == OUTPUT)
				DDRD |= 1 << pin ;
			else
				DDRD &= ~(1 << pin);
		break;
	}
}

void pinSetValue(unsigned char port, unsigned char pin, unsigned char value)
{
	// Postavljanje vrednosti pina
	switch(port)
	{ case PORT_B:
		if (value == HIGH)
			PORTB |= 1 << pin;
		else
			PORTB &= ~(1 << pin);
		break;
	case PORT_C:
		if (value == HIGH)
			PORTC |= 1 << pin;
		else
			PORTC &= ~(1 << pin);
		break;
	case PORT_D:
		if (value == HIGH)
			PORTD |= 1 << pin;
		else
			PORTD &= ~(1 << pin);
		break;
	default:
		break;
	}
}

ISR (TIMER0_COMPA_vect)
{
	desetka++;

}
