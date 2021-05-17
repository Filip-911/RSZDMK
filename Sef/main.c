/*
 * main.c
 *
 *  Created on: May 17, 2021
 *      Author: Korisnik
 */

#include <stdint.h>
#include "../usart/usart.h"
#include "../timer0/timer0.h"
#include "../pin/pin.h"

int main()
{
	pinInit(PORT_B, 5, OUTPUT);
	timer0InteruptInit();
	usartInit(115200);
	int8_t c;

	enum state_t {LOCKED, NUM1, NUM2, UNLOCKED, BROKEN};
	enum state_t state = LOCKED;

	pinSetValue(PORT_B, 5, LOW);

	while(1)
	{
		while(usartAvailable() == 0);
		c = usartGetChar();

		switch(state)
		{
			case LOCKED:
				if (c == '1')
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);
					state = NUM1;
				}
				else
				{
					pinSetValue(PORT_B, 5, HIGH);
					state = BROKEN;
				} break;
			case NUM1:
				if (c == '2')
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);
					state = NUM2;
				}
				else
				{
					pinSetValue(PORT_B, 5, HIGH);
					state = BROKEN;
				} break;
			case NUM2:
				if (c == '3')
				{
					for(int i = 0; i < 3; i++)
					{
						pinSetValue(PORT_B, 5, HIGH);
						timer0DelayMs(1000);
						pinSetValue(PORT_B, 5, LOW);
						timer0DelayMs(1000);
					}
					state = UNLOCKED;
				}
				else
				{
					pinSetValue(PORT_B, 5, HIGH);
					state = BROKEN;
				} break;
			case UNLOCKED:
				break;
			case BROKEN:
				break;
		}
	}

	return 0;
}
