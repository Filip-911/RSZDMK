/**
 * @file vjezba3.c
 * @brief Aplikacija koja implementira ogranicen broj treptanja diode
 * @author Ime Prezime
 * @date 14-03-2021
 * @version 1.0
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../pin_driver/pin.h"
#include "timer0.h"

/**
 * pinPulse - Funkcija koja implementiran podizanje i spustanje vrednosti na
pinu
 * odgovarajucom brzinom
 * @param port - ulaz tipa unsigned char - Port na kojem je potrebno
implementirati funkcionalnost
 * @param pin - ulaz tipa unsigned char - Pin na kojem je potrebno
implementirati funkcionalnost
 * @param period - ulaz tipa unsigned long - Perioda promene vrednosti na
pinu
 * @return Nema povratnu vrednost
 */
void pinPulse(unsigned char port, unsigned char pin, unsigned long period);

/**
 *
 * @param port - Koji od portova zelimo da aktiviramo
 * @param pin - Koji od pinova na tom portu ce pulsirati
 * @param period - Kolika je perioda pulsiranja
 * @param num_of_repetitions - Broj treptaja diode
 */
void pinPulsing(int port, int pin, unsigned long period, int num_of_repetitions);

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

/***********************************************************************/
void pinPulse(unsigned char port, unsigned char pin, unsigned long period)
{
	// Poluperioda u kojoj pin ima visoku vrednost
	pinSetValue(port, pin, HIGH);
	timer0DelayMs(calculateHalfPeriod(period));
	// Poluperioda u kojoj pin ima nisku vrednost
	pinSetValue(port, pin, LOW);
	timer0DelayMs(calculateHalfPeriod(period));
}

/********************************************************************/
void pinPulsing(int port, int pin, unsigned long period, int num_of_repetitions)
{
	for(unsigned char i = 0; i < num_of_repetitions; i++)
		pinPulse(PORT_B, DIODE_PIN, period);
}
