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
	char ime1[20],ime[20], pw[20], dobro[50];
	char prob= "Charlie", loz= 'asdf';

	while (1)
	{

		do
		{
			usartPutString_P(PSTR("Unesite korisnicko ime : "));
			usartPutString_P(PSTR("\r \n"));

			while (!usartAvailable())
				;
			_delay_ms(20);
			usartGetString(ime);
		}

		while(!strcmp(prob, ime1));

		usartPutString_P(PSTR("Sifra : "));


		while (!usartAvailable())
			;
		_delay_ms(20);
		usartGetString(pw);

		if(!strcmp("asdf",pw))
		{
			sprintf(dobro, "Dobrodosao %s", ime);
			usartPutString_P(PSTR("\r \n"));
			usartPutString(dobro);
		}
		else
			usartPutString_P(PSTR("Logovanje neuspesno"));
		usartPutString_P(PSTR("\r \n"));
	}

	return 0;
}

