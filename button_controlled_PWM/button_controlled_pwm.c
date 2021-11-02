#include <unistd.h>
#include <stdint.h>


//funkcija koja vraca stanje tastera na poziciji pos
char buttonState(FILE *fp, char *str, size_t num_of_bytes, char pos);

int main (int argc, char** argv)
{
FILE *fp, *fb;
float percentage = 0;
long int period = 20000L;
char tval0,tval1;
size_t num_of_bytes = 6;
char *str;
char sd = 1;

if(argc != 1)
{
	printf("Ovaj program nema argumente\n");
	return -1;
}

while (1)
{
	// Upali diode
	fp = fopen ("/dev/led", "w");
	if(fp == NULL)
	{
	printf("Problem pri otvaranju /dev/led\n");
	return -1;
	}
	fputs ("0x0f\n", fp);
	
	if( fclose (fp))
	{
		printf("Problem pri zatvaranju /dev/led\n");
		return -1;
	}
	usleep (percentage*period);
	// Ugasi diode
	fp = fopen ("/dev/led", "w");
	if(fp == NULL)
	{
		printf("Problem pri otvaranju /dev/led\n");
		return -1;
	}
	fputs ("0x00\n", fp);
	if( fclose (fp))
	{
		printf("Problem pri zatvaranju /dev/led\n");
		return -1;
	}
	usleep ((1-percentage)*period);
	
	// ako je pritisnut taster 0 umanji pwm
	if (buttonState(fb, str, num_of_bytes, 0))
	{
		if(sd == 1)
		{
			sd = 0;
			
			//Umanji pwm
			if(percentage > 0)
				percentage -= 0.1;
			else
				printf("Can't go lower than 0%");
		}
	}
	if(!buttonState(fp, str, num_of_bytes, 0))
		sd = 1;
	
	// ako je pritisnut taster 1 uvecaj pwm
	if (buttonState(fb, str, num_of_bytes, 1))
	{
		if(sd == 1)
		{
			sd = 0;
			
			//Povecaj pwm
			if(percentage < 1)
				percentage += 0.1;
			else
				printf("Can't go higher than 100%");
		
		}
	if(!buttonState(fp, str, num_of_bytes, 1))
		sd = 1;
	
	free (str);
	sleep (1);
}

char buttonState(FILE *fp, char *str, size_t num_of_bytes, char pos)
{
	fp = fopen ("/dev/button", "r");
	if(fp==NULL)
	{
		puts ("Problem pri otvaranju /dev/button");
		return -1;
	}
	char *str = (char *) malloc (num_of_bytes+1);
	getline (&str, &num_of_bytes, fp);
	
	if( fclose (fp))
	{
		puts("Problem pri zatvaranju /dev/button");
		return -1;
	}
	//Vrati vrijednost tastera na poziciji pos
	char state = str[pos+2] - 48;
	return state;
	
}
