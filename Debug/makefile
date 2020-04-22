################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
emidi.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
emidi.list \

OBJCOPY_BIN += \
emidi.bin \


# All Target
all: emidi.elf secondary-outputs

# Tool invocations
emidi.elf: $(OBJS) $(USER_OBJS) /home/muaddib/STM32CubeIDE/workspace_1.3.0/emidi/STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "emidi.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/muaddib/STM32CubeIDE/workspace_1.3.0/emidi/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="emidi.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

emidi.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "emidi.list"
	@echo 'Finished building: $@'
	@echo ' '

emidi.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "emidi.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
