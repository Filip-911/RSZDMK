/*
 * main.c
 *
 *  Created on: May 7, 2021
 *      Author: Korisnik
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../vjezba4/timer0.h"



int main()
{
	timer0InteruptInit();

	while(1)
	{
		timer0InteruptInit();

	}


	return 0;


}
