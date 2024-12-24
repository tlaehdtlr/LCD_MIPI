################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/BSP/Src/font12.c \
../Application/User/BSP/Src/font16.c \
../Application/User/BSP/Src/font20.c \
../Application/User/BSP/Src/font24.c \
../Application/User/BSP/Src/font8.c \
../Application/User/BSP/Src/nt35510.c \
../Application/User/BSP/Src/otm8009a.c \
../Application/User/BSP/Src/stm32469i_discovery.c \
../Application/User/BSP/Src/stm32469i_discovery_lcd.c \
../Application/User/BSP/Src/stm32469i_discovery_sdram.c 

OBJS += \
./Application/User/BSP/Src/font12.o \
./Application/User/BSP/Src/font16.o \
./Application/User/BSP/Src/font20.o \
./Application/User/BSP/Src/font24.o \
./Application/User/BSP/Src/font8.o \
./Application/User/BSP/Src/nt35510.o \
./Application/User/BSP/Src/otm8009a.o \
./Application/User/BSP/Src/stm32469i_discovery.o \
./Application/User/BSP/Src/stm32469i_discovery_lcd.o \
./Application/User/BSP/Src/stm32469i_discovery_sdram.o 

C_DEPS += \
./Application/User/BSP/Src/font12.d \
./Application/User/BSP/Src/font16.d \
./Application/User/BSP/Src/font20.d \
./Application/User/BSP/Src/font24.d \
./Application/User/BSP/Src/font8.d \
./Application/User/BSP/Src/nt35510.d \
./Application/User/BSP/Src/otm8009a.d \
./Application/User/BSP/Src/stm32469i_discovery.d \
./Application/User/BSP/Src/stm32469i_discovery_lcd.d \
./Application/User/BSP/Src/stm32469i_discovery_sdram.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/BSP/Src/%.o Application/User/BSP/Src/%.su: ../Application/User/BSP/Src/%.c Application/User/BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../BSP/Inc -I../../FATFS/Target -I../../FATFS/App -I../../USB_HOST/App -I../../USB_HOST/Target -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FatFs/src -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-BSP-2f-Src

clean-Application-2f-User-2f-BSP-2f-Src:
	-$(RM) ./Application/User/BSP/Src/font12.d ./Application/User/BSP/Src/font12.o ./Application/User/BSP/Src/font12.su ./Application/User/BSP/Src/font16.d ./Application/User/BSP/Src/font16.o ./Application/User/BSP/Src/font16.su ./Application/User/BSP/Src/font20.d ./Application/User/BSP/Src/font20.o ./Application/User/BSP/Src/font20.su ./Application/User/BSP/Src/font24.d ./Application/User/BSP/Src/font24.o ./Application/User/BSP/Src/font24.su ./Application/User/BSP/Src/font8.d ./Application/User/BSP/Src/font8.o ./Application/User/BSP/Src/font8.su ./Application/User/BSP/Src/nt35510.d ./Application/User/BSP/Src/nt35510.o ./Application/User/BSP/Src/nt35510.su ./Application/User/BSP/Src/otm8009a.d ./Application/User/BSP/Src/otm8009a.o ./Application/User/BSP/Src/otm8009a.su ./Application/User/BSP/Src/stm32469i_discovery.d ./Application/User/BSP/Src/stm32469i_discovery.o ./Application/User/BSP/Src/stm32469i_discovery.su ./Application/User/BSP/Src/stm32469i_discovery_lcd.d ./Application/User/BSP/Src/stm32469i_discovery_lcd.o ./Application/User/BSP/Src/stm32469i_discovery_lcd.su ./Application/User/BSP/Src/stm32469i_discovery_sdram.d ./Application/User/BSP/Src/stm32469i_discovery_sdram.o ./Application/User/BSP/Src/stm32469i_discovery_sdram.su

.PHONY: clean-Application-2f-User-2f-BSP-2f-Src

