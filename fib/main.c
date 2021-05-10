
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
	uint8_t value, duty_cycle, tmp;
	unsigned char i=0, perioda = 0 ;

	while(1)
	{
		while(desetka)
			;
		perioda++;

		tmp = perioda;

		if (perioda - tmp >= 3)  // ako su prosle 3 periode povecavamo faktor ispune
			i++;

		duty_cycle = i/255;

		value = AMPLITUDA * duty_cycle;

		pinSetValue(PORT_D, 5, value);

	}

	return 0;
}
