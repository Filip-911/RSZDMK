/*
 * fibonacci.c
 *
 *  Created on: May 7, 2021
 *      Author: Korisnik
 */

#include "fibonacci.h"

 int32_t FibonacciIter (int number)
{
	 int32_t prvi=0, drugi=1, c=1;
	 int32_t sledeci= prvi+drugi;
	 while(c != number )
	 {
		 sledeci=prvi+drugi;
		 prvi=drugi;
		 drugi=sledeci;
		 c++;
	 }
	 return sledeci;
}
 int32_t FibonacciRecursive(int number)
 {
	 if(number == 0)
	 {
	       return 0;

	 }
	 else if(number == 1)
	 {
	       return 1;
	 }
	 else
	 {
	       return (FibonacciRecursive(number-1) + FibonacciRecursive(number-2));
	 }


 }

