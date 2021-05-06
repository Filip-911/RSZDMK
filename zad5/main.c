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

 void operation (char op, int b1, int b2);

int main()
{
	usartInit(9600);
	char op, broj1[15] , broj2[15], prob[50];
	int ibroj1, ibroj2;

	while(1)
	{

		usartPutString_P(PSTR("Unesite brojni izraz :"));
		usartPutString_P(PSTR("\r \n"));

		while(!usartAvailable())
			;

		_delay_ms(20);

		char c;
		unt p=0;

				broj1[p++]=usartGetChar();

				while (broj1[p] <= '9' && broj1[p] >= '0')
				{
					broj1[p++]=usartGetChar();
				}

				broj1[p]='\0';


		ibroj1 = atoi(broj1);

		sprintf(prob, "broj1 : %d", ibroj1);
		usartPutString(prob);

		op = usartGetChar();
		usartPutString_P(PSTR("\r \n"));

		sprintf(prob, "op : %c", op);

		usartPutString(prob);

		p =0;

		do
		{
			c=usartGetChar();
			broj2[p++]=c;
		}
		while( c >= '9' && c <= '0');

		broj2[p]='\0';


		ibroj2 = atoi(broj2);
		usartPutString_P(PSTR("\r \n"));

		sprintf(prob, "broj2 : %d", ibroj2);
		usartPutString(prob);

		operation(op, ibroj1, ibroj2);

		usartPutString_P(PSTR("\r \n"));


	}

	return 0;
}
void operation (char op, int b1, int b2)
{
	char rezs[50];
	double rez;

	switch (op)
			{
			case '*':
				rez = (double)b1*(double)b2;
				break;
			case '/':
				rez = (double)b1/(double)b2;
				break;
			case '+':
				rez = (double)b1+(double)b2;
				break;
			case '-':
				rez = (double)b1-(double)b2;
				break;
			}

		sprintf(rezs, "Rezultat : %lf ", rez);
		usartPutString(rezs);
}
