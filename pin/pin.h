/*
 * pin.h
 *
 *  Created on: Mar 29, 2021
 *      Author: Korisnik
 */

#ifndef PIN_H_
#define PIN_H_

#include <avr/io.h>


/// Makro za podesavanje visoke vrednosti signala na pinu
#define HIGH 1
/// Makro za podesavanje niske vrednosti signala na pinu
#define LOW 0
/// Makro za podesavanje izlaznog smera pina
#define OUTPUT 1
/// Makro za podesavanje ulaznog smera pina
#define INPUT 0
/// Makro za selektovanje porta B
#define PORT_B 0
/// Makro za selektovanje porta C
#define PORT_C 1
/// Makro za selektovanje porta D
#define PORT_D 2
/// Makro za selektovanje pina na koji je povezana dioda
#define DIODE_PIN 5
/// Makro za brzu periodu
#define FAST 800
/// Makro za sporu periodu
#define SLOW 1800
/// Makro za broj brzih treptaja
#define FAST_REPETITIONS 7
/// Makro za broj sporih treptaja
#define SLOW_REPETITIONS 3

/**
 * calculateHalfPeriod - Funkcija koja racuna polovinu periode treptanja
 * @param period - ulaz tipa unsigned long - Perioda promene vrednosti na
pinu
 * @return Vraca polovinu periode treptanja
 */

unsigned long calculateHalfPeriod(unsigned long period);
/**
 * pinSetValue - Funkcija koja postavlja vrednost na pinu
 *
 * @param port - ulaz tipa unsigned char - Port na kojem je pin ciju
vrednost potrebno postaviti

 * @param pin - ulaz tipa unsigned char - Pin ciju je vrednost potrebno
postaviti

 * @param value - ulaz tipa unsigned char - Vrednost koju je potrebno
postaviti na pin

 * @return Nema povratnu vrednost
 */
void pinSetValue(unsigned char port, unsigned char pin, unsigned char value);
/**
 * pinInit - Funkcija koja implementiran inicijalizaciju pina
 * @param port - ulaz tipa unsigned char - Port na kojem je pin koji je
potrebno inicijalizovati
 * @param pin - ulaz tipa unsigned char - Pin koji je potrebno
inicijalizovati
 * @param direction - ulaz tipa unsigned char - Smer prema kojem je potrebno
inicijalizovati pin
 * @return Nema povratnu vrednost
 */
void pinInit(unsigned char port, unsigned char pin, unsigned char direction);



#endif /* PIN_H_ */
