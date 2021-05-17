/*
 * adc_utils.h
 *
 *  Created on: Mar 29, 2021
 *      Author: Korisnik
 */

#ifndef ADC_UTILS_H_
#define ADC_UTILS_H_

typedef unsigned int uint;
typedef unsigned char uchar;

/**
 *
- Opis: vrši inicijalizaciju AD konvertora na osnovu prosleđenih parametara
(referentni napon i faktor skaliranja).
- Povratna vrednost: nema povratnu vrednost
 */
void InitADC(unsigned char reference, unsigned char division_factor);
/**
 * Opis: vrši inicijalizaciju AD konvertora na osnovu prosleđenih parametara
(referentni napon i faktor skaliranja).
- Povratna vrednost: očitana vrednost sa izlaza AD konvertora
 */
unsigned int ReadADC(unsigned char channel);
/**
 * ;
- Opis: vrši postavljanje referentnog napona (u okviru ADMUX registra) na osnovu
parametra reference.
- Povratna vrednost: nema povratnu vrednost
●
 */
void SetVref(unsigned char reference);
/**
 * ;
- Opis: vrši postavljanje faktora skaliranja (u okviru ADCSRA registra) na osnovu
parametra division_factor.
- Povratna vrednost: nema povratnu vrednost
●
 */
void SetPrescaler(unsigned char division_factor);
/**
 * - Opis: vrši postavljanje dozvole rada AD konvertora (u okviru ADCSRA registra) na
osnovu parametra enable.
- Povratna vrednost: nema povratnu vrednost
●
 */
void SetEnable(unsigned char enable);
/**
 * - Opis: vrši izbor analognog ulaznog kanala AD konvertora (u okviru ADMUX
registra) na osnovu parametra channel.
- Povratna vrednost: nema povratnu vrednost
 */
void SetChannel(unsigned char channel);
/**
 *
- Opis: implementira izvršavanje AD konverzije, odnosno njeno pokretanje i čekanje
na njen završetak.
- Povratna vrednost: nema povratnu vrednost
 */
void RunConversion();

#endif /* ADC_UTILS_H_ */
