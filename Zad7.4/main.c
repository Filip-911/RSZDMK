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

	char rijec [50], niz [50];
	uint8_t rez = 0;
	char sort = '1', a, b;

	while(1)
	{
		usartPutString_P(PSTR("Unesite rijec :"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable());
		_delay_ms(50);

		uint8_t duzina = usartGetString(rijec);

		for(uint8_t i=0 ; i < duzina ; i++)
		{
			a=rijec[i];
			b=rijec[i+1];

			if( a > b )
				sort = '0';

		}

		sprintf( niz , "Rijec : %s", rijec );
		usartPutString(niz);
		if(sort)
			usartPutString_P(PSTR(" jeste sortirana"));
		else
			usartPutString_P(PSTR(" nije sortirana"));

		usartPutString_P(PSTR("\r \n"));
	}

	return 0;
}
