/*
 * main.c
 *
 *  Created on: May 6, 2021
 *      Author: Korisnik
 */

#include "../usart/usart.h"
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <string.h>


int main ()

{
	usartInit(9600);

	char broj [50];
	uint8_t rez=0;

	while(1)
	{
		usartPutString_P(PSTR(""));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable());
		_delay_ms(50);

		uint8_t duzina = usartGetString(broj);


		sprintf( , "  : %d", );
		usartPutString();

	}

	return 0;
}
