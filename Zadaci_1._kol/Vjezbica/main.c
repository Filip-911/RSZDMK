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

	char kime [20], password [20];
	uint8_t rez=0, duzina;
	const char ime [20] = "milos" , lozinka [20] = "milos1", ispis [50];
	char tacno = '1', tacno1 = '1';

	while(1)
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

		while( strcmp (kime, ime) );


			usartPutString_P(PSTR("Unesite lozinku : "));
			usartPutString_P(PSTR("\r \n"));

			duzina = usartGetString(password);

			for(uint8_t i = 0 ; i < duzina ; i++)
					{
						if(password[i] != lozinka[i])
							tacno1 = '0' ;
					}
			if (tacno1 != 0)
			{
				sprintf(ispis, "Dobrodosao %s", kime);
				usartPutString(ispis);
			}


			else
			{
				usartPutString_P(PSTR("logovanje neuspesno "));
				usartPutString_P(PSTR("\r \n"));
			}


	}

	return 0;
}
