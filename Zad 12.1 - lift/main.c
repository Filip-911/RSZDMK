
#include "../usart/usart.h"
#include "../timer0/timer0.h"
#include "../pin/pin.h"
#include "../PLS7/PLS7.h"

#define DOOR_OPEN	0x1F
#define DOOR_CLOSED	0x1E

#define LEDS_OFF 	0xaa
#define LEDS_ON 	0x00

void DoorOpen (int8_t floor)
{
	writeDisplay (floor, DOOR_OPEN);
}

void DoorClose (int8_t floor)
{
	writeDisplay (floor, DOOR_CLOSED);
}

uint8_t SwitchLow(void)
{
	return readSwitches() && 0x03;
}

typedef enum fsmStates {F1O, F1C, F2O, F2C, F3O, F3C, F4O, F4C, FM } fsmStates;

fsmStates FloorToState (uint8_t floor)
{
	switch (floor)
	{
		case 1:
			return 0;
		case 2:
			return 2;
		case 3:
			return 4;
		case 4:
			return 6;
	}
}

int main()
{
	PLS7init();
	timer0InteruptInit();
	usartInit(9600);
	int8_t  currentFloor=1, targetFloor=0, dozvola=1;
	fsmStates state = F1O ;


	while(1)
	{

		switch(state)
		{
		case F1O:

			while (buttonState(LEFT) && dozvola )
			{
				dozvola = 0;
				state++;
				DoorClose (currentFloor);;
				//LEDS_OFF ?

				if (!buttonState(LEFT))
					dozvola = 1;
			}
			break;

		case F1C:

			while (buttonState(RIGHT) && dozvola )
			{
				dozvola = 0;
				if (SwitchLow() == 1)
				{
					state--;
					//LEDS_ON
					DoorOpen (currentFloor);
				}
				else
				{
					targetFloor = SwitchLow();
					state = FM;
				}

				if (!buttonState(RIGHT))
					dozvola = 1;
			}
			break;

		case F2O:


			while (buttonState(LEFT) && dozvola )
			{
				dozvola = 0;
				state++;
				DoorClose (currentFloor);;
				//LEDS_OFF ?

				if (!buttonState(LEFT))
					dozvola = 1;
			}
			break;

		case F2C:

			while (buttonState(RIGHT) && dozvola )
			{
				dozvola = 0;
				if (SwitchLow() == 2)
				{
					state--;
					//LEDS_ON
					DoorOpen (currentFloor);
				}
				else
				{
					targetFloor = SwitchLow();
					state = FM;
				}

				if (!buttonState(RIGHT))
					dozvola = 1;
			}
			break;
		case F3O:

			while (buttonState(LEFT) && dozvola )
			{
				dozvola = 0;
				state++;
				DoorClose (currentFloor);;
				//LEDS_OFF ?

						if (!buttonState(LEFT))
							dozvola = 1;
			}
			break;

		case F3C:

			while (buttonState(RIGHT) && dozvola )
			{
				dozvola = 0;
				if (SwitchLow() == 3)
				{
					state--;
					//LEDS_ON
					DoorOpen (currentFloor);
				}
				else
				{
					targetFloor = SwitchLow();
					state = FM;
				}

				if (!buttonState(RIGHT))
					dozvola = 1;
			}
			break;
		case F4O:

			while (buttonState(LEFT) && dozvola )
			{
				dozvola = 0;
				state++;
				DoorClose (currentFloor);;
				//LEDS_OFF ?

						if (!buttonState(LEFT))
							dozvola = 1;
			}
			break;

		case F4C:

			while (buttonState(RIGHT) && dozvola )
			{
				dozvola = 0;
				if (SwitchLow() == 4)
				{
					state--;
					//LEDS_ON
					DoorOpen (currentFloor);
				}
				else
				{
					targetFloor = SwitchLow();
					state = FM;
				}

				if (!buttonState(RIGHT))
					dozvola = 1;
			}
			break;

		case FM:

			if (currentFloor < targetFloor)
			{
				currentFloor--;
				delay_1m();
			}
			else if (currentFloor > targetFloor)
			{
				currentFloor++;
				delay_1m();
			}
			if(currentFloor == targetFloor)
			{
				state = FloorToState(currentFloor);
			}
			break;
		}
	}

	return 0;
}
