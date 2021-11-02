main.hex:	main.elf
	avr-objcopy -O ihex main.elf main.hex
main.elf:	main.o
	avr-gcc -mmcu=atmega328p main.o -o main.elf -lm
main.o:	main.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c 
program:	main.hex
	avrdude -c arduino -p ATMEGA328P -P COM3 -b 115200 -U flash:w:main.hex
clean:
	rm *.o *.elf *.hex