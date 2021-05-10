
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

	uint8_t tmp, perioda = 0 ;
	unsigned char count;

	while(1)
	{
		while (getIntCount())
			;

		perioda++;

		tmp = perioda;

		if (perioda - tmp >= 3)  // ako su prosle 3 periode povecavamo faktor ispune
			incDuty();
	}

	return 0;
}
