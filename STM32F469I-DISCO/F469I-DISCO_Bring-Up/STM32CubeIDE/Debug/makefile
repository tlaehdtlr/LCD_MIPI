################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/Startup/subdir.mk
-include Application/User/Core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := F469I-DISCO_Bring-Up
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F469I-DISCO_Bring-Up.elf \

MAP_FILES += \
F469I-DISCO_Bring-Up.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F469I-DISCO_Bring-Up.list \

OBJCOPY_HEX += \
F469I-DISCO_Bring-Up.hex \

OBJCOPY_BIN += \
F469I-DISCO_Bring-Up.bin \


# All Target
all: main-build

# Main-build Target
main-build: F469I-DISCO_Bring-Up.elf secondary-outputs

# Tool invocations
F469I-DISCO_Bring-Up.elf F469I-DISCO_Bring-Up.map: $(OBJS) $(USER_OBJS) C:\Users\2023851\Projects\Vieworks_SIM\LCD_MIPI\STM32F469I-DISCO\F469I-DISCO_Bring-Up\STM32CubeIDE\STM32F469NIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "F469I-DISCO_Bring-Up.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\2023851\Projects\Vieworks_SIM\LCD_MIPI\STM32F469I-DISCO\F469I-DISCO_Bring-Up\STM32CubeIDE\STM32F469NIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F469I-DISCO_Bring-Up.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F469I-DISCO_Bring-Up.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F469I-DISCO_Bring-Up.list"
	@echo 'Finished building: $@'
	@echo ' '

F469I-DISCO_Bring-Up.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "F469I-DISCO_Bring-Up.hex"
	@echo 'Finished building: $@'
	@echo ' '

F469I-DISCO_Bring-Up.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "F469I-DISCO_Bring-Up.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) F469I-DISCO_Bring-Up.bin F469I-DISCO_Bring-Up.elf F469I-DISCO_Bring-Up.hex F469I-DISCO_Bring-Up.list F469I-DISCO_Bring-Up.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
