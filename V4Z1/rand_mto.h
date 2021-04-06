/*
 * rand_mto.h
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

#ifndef RAND_MTO_H_
#define RAND_MTO_H_

///Prom za LFSR
uint LFSR;

/**
 * - Opis: vrši inicijalizaciju početnog stanja generatora na osnovu parametra seed.
- Povratna vrednost: nema povratnu vrednost
 * @param seed
 */
void InitRand(unsigned int seed);
/**
 * - Opis: vrši generisanje 16-bitnog pseduoslučajnog broja.
- Povratna vrednost: generisana 16-bitna vrednost
 */
unsigned int Rand();
/**
 * - Opis: vrši generisanje 16-bitnog pseduoslučajnog broja iz intervala min-max.
- Povratna vrednost: generisana 16-bitna vrednost
 */
unsigned int RandRange(unsigned int min, unsigned int max);
/**
 * - Opis: vrši generisanje naredne vrednost MSB, na osnovu trenutnog stanja registra.
- Povratna vrednost: generisana vrednost MSB
 */
unsigned char GenerateNextBit(unsigned int current_state);
/**
 * - Opis: vrši generisanje novog stanja registra na osnovu trenutnog stanja registra i
nove vrednosti MSB.
- Povratna vrednost: generisano novo 16-bitno stanje registra
 */
unsigned int UpdateState(unsigned int state, unsigned char bit);



#endif /* RAND_MTO_H_ */
