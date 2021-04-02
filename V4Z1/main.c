/*
 * main.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Korisnik
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc_utils.h"
#include "logic_utils.h"

main()
{
	InitADC(1,9);
	//single conversion ?
	SetEnable(1);

	SetChannel(3);
	RunConversion();
	ReadADC(3);


return 0;
}

