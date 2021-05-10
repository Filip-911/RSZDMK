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

void odaberi (char c, char r [20]);
void slovo (char r [20]);
void makni_razmake(char r [20]);
void ukloni_duplikate(char r[20]);

int main ()

{
	usartInit(9600);

	char string [50], c;

	while(1)
	{
		usartPutString_P(PSTR("\r \n"));
		usartPutString_P(PSTR("Unesite string : "));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable());
		_delay_ms(50);

		usartGetString(string);
		usartPutString(string);
		usartPutString_P(PSTR("\r \n"));

		usartPutString_P(PSTR("Izaberite opciju za modifikaciju unetog stringa: \r \n "));
		usartPutString_P(PSTR("1. Slovo koje se najvise ponavlja? \r \n"));
		usartPutString_P(PSTR("2. Ukloni sve ‘ ’ karaktere. \r \n "));
		usartPutString_P(PSTR("3. Ukloni sve duplikate karaktera. \r \n"));

		while(!usartAvailable());
		_delay_ms(50);

		c = usartGetChar();

		odaberi(c, string);



	}

	return 0;
}

void odaberi(char c, char r [20])
{
	switch (c)
	{
			case '1' :
				slovo(r);
				break;
			case '2' :
				makni_razmake(r);
				break;
	}

}

void slovo(char r [20])
{
	uint8_t niz [20], counter, max, slovo;
	char ispis [30];

	for(uint8_t i =0 ; ; i++) 			//uzmem jedno slovo
		{
			if(r[i] == NULL)				// ako je dosao do kraja gotova provjera
				break;

			counter=0;							// brojac konkretnog slova da bude na nuli

			for(uint8_t j =i+1 ; ; j++) 		//provjerava sva sledeca slova
					{
						if(r[j] == NULL)				// dok ne dodje do kraja
							break;

						if (r[i] - r[j] == 0 )
							niz[i] = ++counter;		 // povecava brojac ako se desilo poklapanje

					}

		}
		max=niz[0];
		slovo=0;
		for(uint8_t i=0 ; ; i++) 	//trazimo najveci broj u nizu
		{
			if(r[i] == NULL)				// ako je dosao do kraja gotova provjera
				break;

			if(niz[i] > max)		 //ako je naisao na neko slovo sa vise ponavljanja onda je to max
			{
				max=niz[i];
				slovo=i;		// zapamti poziciju na kojoj se nalazi najvise ponavljanja
			}
		}

		sprintf(ispis, "Najvise ponavljanja ima slovo : %c", r[slovo]);
		usartPutString(ispis);
}

void makni_razmake(char r [20])
{
	char ispis [20], novistr [20];
	uint8_t c=0, i=0;

	while (r[c] != '\0')
	{
		if(r[c] != ' ')
		{
			novistr[i] = r[c];
			i++;
		}
			c++;
	}

	novistr[i] = '\0';
	sprintf(ispis, "String bez razmaka : %s", novistr);
			usartPutString(ispis);

}

void ukloni_duplikate(char r[20])
{



}
