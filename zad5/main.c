/*
 * main.c
 *
 *  Created on: Apr 27, 2021
 *      Author: Korisnik
 */

#include <avr/io.h>
#include <stdio.h>
#include "../usart/usart.h"
#include <util/delay.h>
#include <avr/pgmspace.h>

typedef uint8_t unt;
double operation (char op, char b1,char b2);

int main()
{
	usartInit(9600);
	char op, broj1[15] , broj2[15];
	double rez=0;

	while(1)
	{

		usartPutString_P(PSTR("Unesite brojni izraz :"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable())
			;

		unt len=usartAvailable();
				_delay_ms(100);

		unt p=0;

		broj1[p++]=usartGetChar();

		while (broj1[p] <= '9' && broj1[p] >= '0')
		{
			broj1[p++]=usartGetChar();
		}

		broj1[p]='0';

		op = usartGetChar();

		p =0;

		broj2[p++]=usartGetChar();
		while (broj2[p] <= '9' && broj2[p] >= '0')
				{
					broj2[p++]=usartGetChar();
				}

		broj2[p]='0';

		rez = operation(op, broj1, broj2);

		usartPutString_P(PSTR("Rezultat :"));
		printf("%lf", rez);
		usartPutString_P(PSTR("\r \n"));
	}

	return 0;
}
double operation (char op, char b1,char b2)
{
	switch(op)
			{
			case '*':
				return b1*b2;
			case '/':
				return b1/b2;
			case '+':
				return b1+b2;
			case '-':
				return b1-b2;
			}
}
