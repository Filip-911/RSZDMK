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
rpj.lss \

FLASH_IMAGE += \
rpj.hex \

EEPROM_IMAGE += \
rpj.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: rpj.elf secondary-outputs

# Tool invocations
rpj.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,rpj.map -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\PLS7\Release" -L"C:\Users\Korisnik\Desktop\Filip\GitShieeeet\RSZDMK\usart\Release" -mmcu=atmega328p -o "rpj.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

rpj.lss: rpj.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S rpj.elf  >"rpj.lss"
	@echo 'Finished building: $@'
	@echo ' '

rpj.hex: rpj.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex rpj.elf  "rpj.hex"
	@echo 'Finished building: $@'
	@echo ' '

rpj.eep: rpj.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex rpj.elf  "rpj.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: rpj.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p rpj.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) rpj.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
