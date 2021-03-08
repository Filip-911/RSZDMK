#include <stdio.h>
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

	printf("Result: %d \n", c);

   return 0;
}