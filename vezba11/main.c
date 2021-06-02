

#include "../PLS7/PLS7.h"
#include <stdint.h>

//0 1 2 3 4 5 6 7 8 9
const unsigned char digits[]={ 0x05, 0xdd, 0x46, 0x54, 0x9c, 0x34, 0x24, 0x5d, 0x04, 0x14};



int main()
{
	PLS7init();

	int8_t disp=D1;
	int8_t cifra [5] = "00000";

	while (1)
	{
		writeDisplay(LEDS, readSwitches());

		if (buttonState(LEFT))
			disp--;

		if (buttonState(DOWN))
			writeDisplay (disp, digits[--cifra[disp]]);

		if (buttonState(RIGHT))
			disp++;

		if (buttonState(UP))
			writeDisplay (disp, digits[++cifra[disp]]);

		writeDisplay(disp, 0xFB);
	}
	return 0;
}
