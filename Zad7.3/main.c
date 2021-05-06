/*
 * main.c
 *
 *  Created on: May 6, 2021
 *      Author: Korisnik
 */

#include "../usart/usart.h"
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <string.h>


int main ()

{
	usartInit(9600);
	char broj [50], suma [20], c ;
	int rez=0, a [50];
	uint8_t p=0;

	while(1)
	{
		rez=0;
		usartPutString_P(PSTR("\r \n"));
		usartPutString_P(PSTR("Unesite broj"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable());
		_delay_ms(50);

		do
		{
			p=0;
			c=usartGetChar();
			broj[p++]=c;
			broj[p]='\0';
			rez += atoi(broj);
		}
		while(c <= '9' && c >= '0');

			usartPutString_P(PSTR("\r \n"));
			sprintf(suma, "suma : %d", rez);
			usartPutString(suma);

	}

	return 0;
}
