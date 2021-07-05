/*
 * main.c
 *
 *  Created on: Jul 4, 2021
 *      Author: Korisnik
 */
#include <stdint.h>
#include <math.h>
#include "../usart/usart.h"
#include "../PLS7/PLS7.h"
#include <string.h>

#define ITERATIVE 0
#define FORMULA 1

int sumofGP(int a, int n, int r)
{
    int sum = (a * (1 - pow(r, n))) / (1- r);
    return sum;
}

int16_t SumGeo(int16_t first_element, int16_t ratio, int16_t n, int8_t mode)
{
	uint8_t state = 1, i ;
	uint8_t value = first_element;
	float sum = 0;

	if(mode == ITERATIVE)
	{
		switch(state)
		{
			case 1:
				i = 0;
				state++;
			break;

			case 2:
				if(i <n)
				{
					sum = sum + value;
					value = value * ratio;
				}
				else
					break;

			default:
			break;
		}
	}
	if(mode == FORMULA)
	{
		sum = sumofGP(first_element, n, ratio);
	}
	return sum;
}

int main(void)
{
	while(1)
	{
		int16_t iter = SumGeo(2,10,2,ITERATIVE);
		int16_t form = SumGeo(2,10,2,FORMULA);
		char ispis [50];
		sprintf(ispis, "iter : %d \n \r form : %d ", iter, form);
		usartPutString(ispis);
		return 0;
	}

	return 0;
}
