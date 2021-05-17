/*
 * fibonacci.h
 *
 *  Created on: May 7, 2021
 *      Author: Korisnik
 */
#include "../usart/usart.h"
#include <stdio.h>
#include <avr/io.h>


#ifndef FIBONACCI_H_
#define FIBONACCI_H_

/**
 * Opis: Funkcija koja implementira iterativni algoritam za računanje n-tog člana
 * Fibonačijevog niza.
 * Povratna vrednost: Vrednost n-tog člana Fibonačijevog niza.
 */
int32_t FibonacciIter(int number);

/**
 * Opis: Funkcija koja implementira rekurzivni algoritam za računanje n-tog člana
 * Fibonačijevog niza.
 * Povratna vrednost: Vrednost n-tog člana Fibonačijevog niza.
 */
int32_t FibonacciRecursive(int number);


#endif /* FIBONACCI_H_ */
