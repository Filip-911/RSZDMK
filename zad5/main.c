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

double operation (char op, int b1, int b2);

int main()
{
	usartInit(9600);
	char op, broj1[15] , broj2[15], rezs[50];
	int ibroj1, ibroj2;
	double rez=0;

	while(1)
	{

		usartPutString_P(PSTR("Unesite brojni izraz :"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable())
			;

		_delay_ms(20);

		unt p=0;

		broj1[p++]=usartGetChar();

		while (broj1[p] <= '9' && broj1[p] >= '0')
		{
			broj1[p++]=usartGetChar();
		}

		broj1[p]='\0';
		ibroj1 = atoi(broj1);

		op = usartGetChar();

		p =0;

		broj2[p++]=usartGetChar();

		while (broj2[p] <= '9' && broj2[p] >= '0')
		{
			broj2[p++]=usartGetChar();
		}
		broj2[p]='\0';

		ibroj2 = atoi(broj2);

		rez = operation(op, ibroj1, ibroj2);

		sprintf(rezs, "Rezultat : %lf ", rez);

		usartPutString(rezs);
		usartPutString_P(PSTR("\r \n"));
	}

	return 0;
}
double operation (char op, int b1, int b2)
{
	switch(op)
			{
			case '*':
				return b1*b2;
			case '/':
				return (double)b1/b2;
			case '+':
				return b1+b2;
			case '-':
				return b1-b2;
			}
}
