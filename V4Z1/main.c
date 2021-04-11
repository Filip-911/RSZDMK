/*
 * main.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Korisnik
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#include "pin.h"
#include "timer0.h"
#include "logic_utils.h"
#include "adc_utils.h"
#include "rand_mto.h"

int main()
{

	InitADC(1,9);
	SetEnable(1);

	SetChannel(2);

	uint brojTreptaja = RandRange(4,8);

	// Inicijalizacija
	timer0InteruptInit();
	pinInit(PORT_B, DIODE_PIN, OUTPUT);

	pinPulsing(PORT_B, DIODE_PIN, FAST, brojTreptaja);
	while (1)
	{
		RunConversion();
		uint rez = ReadADC(2);
		InitRand(rez);
	}

return 0;
}

