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
Zad7.10.lss \

FLASH_IMAGE += \
Zad7.10.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Zad7.10.elf secondary-outputs

# Tool invocations
Zad7.10.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Zad7.10.map -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\usart\Release" -mmcu=atmega328p -o "Zad7.10.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Zad7.10.lss: Zad7.10.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Zad7.10.elf  >"Zad7.10.lss"
	@echo 'Finished building: $@'
	@echo ' '

Zad7.10.hex: Zad7.10.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Zad7.10.elf  "Zad7.10.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Zad7.10.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Zad7.10.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Zad7.10.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm328p -carduino -PCOM3 -Uflash:w:Zad7.10.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Zad7.10.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
