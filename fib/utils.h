
#ifndef UTILS_H_
#define UTILS_H_


#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "util/delay.h"
///makro za ..
#define OUTPUT 1
#define INPUT 0
///
#define PORT_B 0
#define PORT_C 1
#define PORT_D 2

/// Makro za podesavanje visoke vrednosti signala na pinu
#define HIGH 1
/// Makro za podesavanje niske vrednosti signala na pinu
#define LOW 0

/**
 * Funkcija za inicijalizaciju tamjera da generise prekid svakih 10us
 *
 */
void timer0InterruptInit ();

/**
 * Funkcija za inicijalizaciju pina na datom portu u datom smjeru
 *
 * @param port Port na kojem se inicijalizuje pin
 * @param pin Broj pina na portu
 * @param dir Smjer pina ( 1 za izlaz, 0 za ulaz)
 */
void pinInit(char port, char pin, char dir);
/**
 *  Funkcija kjoa ..
 * @param port port koji se selektuje za promjernu stanja
 * @param pin
 * @param value
 */
void pinSetValue ( unsigned char port, unsigned char pin, unsigned char value );

unsigned char getIntCount();


#endif /* UTILS_H_ */
