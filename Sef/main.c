


#include "../usart/usart.h"
#include "../timer0/timer0.h"
#include "../pin/pin.h"
#include <util/delay.h>

void blink(uint8_t times)
{
	for(uint8_t i = 0; i<times; i++)
	{
		pinSetValue(PORT_B, DIODE_PIN, HIGH);
		_delay_ms(500);
		pinSetValue(PORT_B, DIODE_PIN, LOW);
		_delay_ms(500);
	}
}

void invBlink(uint8_t times)
{
	for(uint8_t i = 0; i<times; i++)
	{
		pinSetValue(PORT_B, DIODE_PIN, LOW);
		_delay_ms(500);
		pinSetValue(PORT_B, DIODE_PIN, HIGH);
		_delay_ms(500);
	}
}

int main()
{
	enum stateType {LOCKED, NUM1, NUM2, UNLOCKED, BROKEN, REC1, REC2};
	enum stateType state = 0;
	usartInit(9600);
	pinInit(PORT_B, DIODE_PIN, OUTPUT);

	pinSetValue(PORT_B, 5, LOW);
	while(1)
	{
		while(usartAvailable() == 0);
		switch(state)
		{
		case LOCKED:
			if(usartGetChar() == '1')
			{
				state++;
				blink(1);
			}
			else
			{
				state = BROKEN;
				pinSetValue(PORT_B, DIODE_PIN, HIGH);
			}
		break;
		case NUM1:
			if(usartGetChar() == '2')
			{
				state++;
				blink(1);
			}
			else
			{
				state = BROKEN;
				pinSetValue(PORT_B, DIODE_PIN, HIGH);
			}
		break;
		case NUM2:
			if(usartGetChar() == '3')
			{
				state = UNLOCKED;
				blink(3);
			}
			else
			{
				state = BROKEN;
				pinSetValue(PORT_B, DIODE_PIN, HIGH);
			}
		break;
		case BROKEN:
			if(usartGetChar() == '7')
			{
				state++;
				invBlink(1);
			}
			else
			{
				state = BROKEN;
				invBlink(2);
			}
		break;
		case REC1:
			if(usartGetChar() == '8')
			{
				state++;
				invBlink(1);
			}
			else
			{
				state = BROKEN;
				invBlink(2);
			}
		break;
		case REC2:
			if(usartGetChar() == '9')
			{
				state = LOCKED;
				pinSetValue(PORT_B, DIODE_PIN, LOW);
			}
			else
			{
				state = BROKEN;
				invBlink(2);
			}
		break;
		}
	}
	return 0;
}
