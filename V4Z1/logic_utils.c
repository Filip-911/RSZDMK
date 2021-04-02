/*
 * logic_utils.h
 *
 *  Created on: Mar 29, 2021
 *      Author: Korisnik
 */

#include "logic_utils.h"

unsigned int SetBit(unsigned int reg, unsigned char bit_num)
{
	return reg |= (1 << bit_num);
}

unsigned int ClearBit(unsigned int reg, unsigned char bit_num)
{
	return reg &= ~(1 << bit_num);
}

unsigned int ToggleBit(unsigned int reg, unsigned char bit_num)
{
	return reg ^= (1 << bit_num);
}

unsigned int CheckBit(unsigned int reg, unsigned char bit_num)
{
	reg &= (1 << bit_num);
	if(reg)
		return 1;
	else
		return 0;
}

unsigned char BitmaskSet(unsigned char reg, unsigned char mask)
{
	return reg |= mask;
}

unsigned char BitmaskClear(unsigned char reg, unsigned char mask)
{
	return reg &= ~mask;
}

unsigned int Not(unsigned int input)
{
	return ~input;
}

unsigned int And(unsigned int input1, unsigned int input2)
{
	return input1 & input2;
}

unsigned int Or(unsigned int input1, unsigned int input2)
{
	return input1 | input2;
}

unsigned int Xor(unsigned int input1, unsigned int input2)
{
	return input1 ^ input2;
}

unsigned int ShiftLeft(unsigned int input, unsigned int num_of_shifts)
{
	return input <<= num_of_shifts;
}

unsigned int ShiftRight(unsigned int input, unsigned int num_of_shifts)
{
	return input >>= num_of_shifts;
}
