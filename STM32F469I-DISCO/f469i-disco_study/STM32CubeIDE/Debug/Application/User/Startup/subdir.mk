################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/User/Startup/startup_stm32f469nihx.s 

OBJS += \
./Application/User/Startup/startup_stm32f469nihx.o 

S_DEPS += \
./Application/User/Startup/startup_stm32f469nihx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Startup/%.o: ../Application/User/Startup/%.s Application/User/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/2023851/Projects/LCD_MIPI/STM32F469I-DISCO/f469i-disco_study/STM32CubeIDE/Application/User" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-User-2f-Startup

clean-Application-2f-User-2f-Startup:
	-$(RM) ./Application/User/Startup/startup_stm32f469nihx.d ./Application/User/Startup/startup_stm32f469nihx.o

.PHONY: clean-Application-2f-User-2f-Startup

