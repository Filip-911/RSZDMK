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

	char broj [5], niz [10];
	uint8_t rez, zni [200] ;

	while(1)
	{
		usartPutString_P(PSTR("Unesite broj do 200 :"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable());
		_delay_ms(50);

		usartGetString(broj);
		rez = atoi(broj);

		for(uint8_t i=2 ; i <= rez ; i++)
		{
			zni[i] = i;
		}

		usartPutString_P(PSTR("Prosti brojevi :"));

		for(uint8_t i=2 ; i <= rez ; i++)
		{
			for(uint8_t j = i+1 ; j <= rez ; j++)
				{
				if( zni[i] == NULL) 	//provjerimo da li je broj vec izbacen, ako jeste preskacemo provjeru i idemo dalje
					break;

				if(zni[j] % i == 0) 	// ako je dijeljiv sa i izbacujemo ga
					zni[j] = NULL ;
				}
			if( zni[i]) 				// ako je razlicit od NULL tj ako je prezivio onda je prost
			{
				sprintf(niz , "%d, " , zni[i]);
				usartPutString(niz);
			}
		}
		usartPutString_P(PSTR("\r \n"));

	}

	return 0;
}
