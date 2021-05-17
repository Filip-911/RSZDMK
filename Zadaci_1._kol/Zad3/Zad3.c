/*
 * Serijski_demo.c
 *
 *  Created on: Apr 19, 2021
 *      Author: Korisnik
 */

#include "../usart/usart.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

typedef uint8_t unt;

int main() {
	usartInit(9600);
	char broj[16], hex[16];
	int intBroj;

	while (1) {
		usartPutString_P(PSTR("\r \n"));
		usartPutString_P(PSTR("Unesite decimalan broj:"));
		usartPutString_P(PSTR(" \r \n "));

		while (!usartAvailable())
			;
		_delay_ms(30);
		usartGetString(broj);
		intBroj = atoi(broj);

		sprintf(hex, "0x%x", intBroj);
		usartPutString(hex);
		usartPutString_P(PSTR(" \n \r "));

	}

	return 0;
}
