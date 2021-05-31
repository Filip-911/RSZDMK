################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Zad\ 12.1\ -\ lift.lss \

FLASH_IMAGE += \
Zad\ 12.1\ -\ lift.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Zad\ 12.1\ -\ lift.elf secondary-outputs

# Tool invocations
Zad\ 12.1\ -\ lift.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Zad 12.1 - lift.map -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\timer0\Release" -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\PLS7\Release" -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\pin\Release" -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\usart\Release" -mmcu=atmega328p -o "Zad 12.1 - lift.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Zad\ 12.1\ -\ lift.lss: Zad\ 12.1\ -\ lift.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Zad 12.1 - lift.elf  >"Zad 12.1 - lift.lss"
	@echo 'Finished building: $@'
	@echo ' '

Zad\ 12.1\ -\ lift.hex: Zad\ 12.1\ -\ lift.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Zad 12.1 - lift.elf  "Zad 12.1 - lift.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Zad\ 12.1\ -\ lift.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Zad 12.1 - lift.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Zad\ 12.1\ -\ lift.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm328p -carduino -PCOM3 -Uflash:w:Zad 12.1 - lift.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "Zad 12.1 - lift.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
