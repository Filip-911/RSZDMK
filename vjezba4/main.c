/**
 * @file vjezba3.c
 * @brief Aplikacija koja implementira ogranicen broj treptanja diode
 * @author Ime Prezime
 * @date 14-03-2021
 * @version 1.0
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pin.h"

int main()
{
	unsigned long period = 1000; // Period jednog treptaja
	unsigned char repetitions = 5; // Broj treptaja
	// Inicijalizacija
	pinInit(PORT_B, DIODE_PIN, OUTPUT);
	timer0InteruptInit();
	// Glavna petlja
	while (1)
	{
		pinPulsing(PORT_B, DIODE_PIN, FAST, FAST_REPETITIONS);
		pinPulsing(PORT_B, DIODE_PIN, SLOW, SLOW_REPETITIONS);

	}
	return 0;
}
