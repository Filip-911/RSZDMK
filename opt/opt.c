
int s = 0;

int racun (int a, int b, int c, int d)
{
	int i;
	for (i = 10; i ; i--)
	{
		s+=a;
		s+=b;
		s+=c;
		s+=d;
	}

	for (i = 10; i ; i--)
	{
		s+=a;
		s+=b;
		s+=c;
		s+=d;
	}
}

int main(void)
{

	int a = 1, b = 2, c = 3, d = 4;

	s = racun(a,b,c,d);

	s = racun(a,b,c,d);
	s = racun(a,b,c,d);
	s = racun(a,b,c,d);
	s = racun(a,b,c,d);
	s = racun(a,b,c,d);
	s = racun(a,b,c,d);
	s = racun(a,b,c,d);

	return 0;
}
