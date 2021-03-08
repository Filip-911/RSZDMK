#include <stdio.h>

void printResult(int c)
{
	printf("Result: %d, c")
}
int Calculation (int a, int b)
{
	if(a>b)
		c=a-b;
	else
		c=b-a;
}
int main() 
{
	int a=5;
	int b=4;
	int c;
	
	c= Calculation(a,b);


	printResult(c);

	printf("Result: %d \n", c);

   return 0;
}