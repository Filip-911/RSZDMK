/*
 * Serijski_demo.c
 *
 *  Created on: Apr 19, 2021
 *      Author: Korisnik
 */

#include "../usart/usart.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
typedef uint8_t unt;

char kejs (unt ost);

int main()
{
	usartInit(9600);
	char ost, *broj, hex [5];

	while(1)
	{
		usartPutString_P(PSTR("\r \n"));
		usartPutString_P(PSTR("Unesite decimalan broj:"));

		while(!usartAvailable());

		_delay_ms(100);
		usartGetString(broj);

		for(unt i=0 ; i < 5; i++)
		{
			ost = (*broj) % 16;
			if(ost > 9)
				hex[4-i]=kejs(ost);
			else
				hex[4-i]=ost;

			*broj= (*broj) / 16;
		}
		hex[5]='\0';

		usartPutString_P(PSTR("\r \n"));
		usartPutString_P(PSTR("Unijeli ste vrijednost : 0x"));
		usartPutString(hex);
	}

	return 0;
}

char kejs (unt ost)
{
	switch (ost)
	{
		case 10:
			return 'A';
			break;

		case 11:
			return 'B';
			break;

		case 12:
			return 'C';
			break;

		case 13:
			return 'D';
			break;

		case 14:
			return 'E';
			break;

		case 15:
			return 'F';
			break;
	}
}
