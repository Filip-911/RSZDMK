
/*
 * adc_utils.h
 *
 *  Created on: Mar 29, 2021
 *      Author: Korisnik
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#include "logic_utils.h"
#include "adc_utils.h"

void InitADC(unsigned char reference, unsigned char division_factor)
{
	ADMUX=0;
	ADCSRA=0;
	ADC=0;
	ADCL=0;
	ADCH=0;
	ClearBit(ADMUX, 5);
	if(reference == 1)
		SetBit(ADMUX,6);
	if(division_factor==9)
		BitmaskSet(ADCSRA, 0x07);
}

unsigned int ReadADC(unsigned char channel)
{
	ADC=0;
	uint res;
	for(uchar i=7;i>=0;i--)
	{
		if(CheckBit(ADCL,i))	//provjeri pozicije 7-0 u ADCL
			SetBit(ADC, i);		//setuj pozicije 7-0 u ADC
		if(i>5)
		{
			if(CheckBit(ADCH,i+8))	//provjeri pozicije 15 i 14 u ADCH
				SetBit(ADC, i+2); 	//setuj pozicije 9 i 8 u ADC
		}
	}

	return res = res*ADC/1023;
}

void SetVref(unsigned char reference)
{
	if(reference == 1)
			SetBit(ADMUX,0);
}

void SetPrescaler(unsigned char division_factor)
{
	if(division_factor==9)
			BitmaskSet(ADCSRA, 0x07);
}


void SetEnable(unsigned char enable)
{
	if(enable)
		SetBit(ADCSRA,7);
}


void SetChannel(unsigned char channel)
{
	if(channel == 0)
		BitmaskSet(ADCSRA,0);
	if(channel == 1)
		SetBit(ADCSRA, 0);
	if(channel == 2)
		SetBit(ADCSRA, 1);
	if(channel == 3)
		BitmaskSet(ADCSRA,0x03);
	if(channel == 4)
		SetBit(ADCSRA, 2);
	if(channel == 5)
		BitmaskSet(ADCSRA,0x05);
}

void RunConversion()
{
	SetBit(ADCSRA, 6);
	while(0);
	ClearBit(ADCSRA, 6);
}
/*
 * pitanja: Koliko dugo cekam da se zavrsi konverzija, da li ja radim konverziju ?
 * Cemu sluze setvref i setpresc
 * Da li reference i division factor pisemo sve vrijednosti
 * single conversion mod ?
 * Da li su kanali razlicite prom u koje ubacujemo rezultat ?
 */
