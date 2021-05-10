
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
#include "utils.h"

int main ()
{
	usartInit(9600);
	timer0InterruptInit();
	pinInit( PORT_D, 5, OUTPUT);

	uint8_t tmp, duty=0, perioda = 0 ;
	unsigned char count;

	while(1)
	{
		while (getIntCount())
			;

		perioda++;

		tmp = perioda;

		if (perioda - tmp >= 3)  // ako su prosle 3 periode povecavamo faktor ispune
			duty++;

		count = getIntCount();

		if (count <= duty)
			pinSetValue(PORT_B, 5, 0);
		else
			pinSetValue(PORT_B, 5, 1);
	}

	return 0;
}
