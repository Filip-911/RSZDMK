
/*
 * main.c
 *
 *  Created on: May 6, 2021
 *      Author: Korisnik
 */

#include "../usart/usart.h"
#include <stdio.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "utils.h"

int main ()

{
	usartInit(9600);

	char ispis [50];
	int16_t broj ;
	uint8_t rez=0;

	while(1)
	{
		usartPutString_P(PSTR("\r \n"));
		usartPutString_P(PSTR("Unesite niz iz kojeg cemo uzeti broj :"));

		while(!usartAvailable());
		_delay_ms(50);

		broj = usartParseInt();

		usartPutString_P(PSTR("\r \n"));
		sprintf( ispis , "Evo ga  : %d", broj );
		usartPutString(ispis);
		usartPutString_P(PSTR("\r \n"));

	}

	return 0;
}
