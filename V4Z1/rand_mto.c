/*
 * rand_mto.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Korisnik
 */

#include "rand_mto.h"


void InitRand(unsigned int seed)
{
	LFSR = seed;
}

unsigned int Rand()
{
	uchar msb = GenerateNextBit(LFSR);
	UpdateState(LFSR,msb);
	return LFSR;
}

unsigned int RandRange(unsigned int min, unsigned int max)
{
	uint rand = Rand();

	if(rand < min)
		rand = min;
	else
		if(rand > max)
			rand=max;
	return rand;
}

unsigned char GenerateNextBit(unsigned int current_state)
{
	if(Xor(Xor(Xor(CheckBit(LFSR, 0), CheckBit(LFSR, 2)),CheckBit(LFSR, 3)),CheckBit(LFSR, 5))) //ako je novi msb razlicit od nule
		SetBit(LFSR,15);
	else
		ClearBit(LFSR, 15);

	return CheckBit(LFSR, 15);
}
/**
 * - Opis: vrši generisanje novog stanja registra na osnovu trenutnog stanja registra i
nove vrednosti MSB.
- Povratna vrednost: generisano novo 16-bitno stanje registra
 */
unsigned int UpdateState(unsigned int state, unsigned char bit)
{
	uint new = (state >> 1);

	if(bit)
		SetBit(new, 15);
	else
		ClearBit(new, 15);

	return new;
}
