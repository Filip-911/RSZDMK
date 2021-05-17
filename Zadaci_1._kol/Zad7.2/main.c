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


int main()
{
	usartInit(9600);
	char rijec [30], ispis [50] ;
	uint8_t c=0;


	while(1)
	{
		c=0;
		usartPutString_P(PSTR("Unesite rec"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable())
			;
		_delay_ms(20);

		uint8_t duzina=usartGetString(rijec);

		for(uint8_t i = 0; i < duzina ; i++)
		{
			if(rijec[i] == 'a' ||  rijec[i] == 'e' || rijec[i] == 'i' || rijec[i] == 'o' || rijec[i] == 'u' )
				c++;
		}
		sprintf(ispis, "Rijec ima %d samoglasnika", c);
		usartPutString_P(PSTR("\r \n"));
		usartPutString(ispis);

	}

	return 0;
}
