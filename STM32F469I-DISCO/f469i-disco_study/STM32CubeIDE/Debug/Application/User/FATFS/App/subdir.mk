################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/2023851/Projects/LCD_MIPI/STM32F469I-DISCO/f469i-disco_study/FATFS/App/fatfs.c 

OBJS += \
./Application/User/FATFS/App/fatfs.o 

C_DEPS += \
./Application/User/FATFS/App/fatfs.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/FATFS/App/fatfs.o: C:/Users/2023851/Projects/LCD_MIPI/STM32F469I-DISCO/f469i-disco_study/FATFS/App/fatfs.c Application/User/FATFS/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../FATFS/Target -I../../FATFS/App -I../../USB_HOST/App -I../../USB_HOST/Target -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FatFs/src -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-FATFS-2f-App

clean-Application-2f-User-2f-FATFS-2f-App:
	-$(RM) ./Application/User/FATFS/App/fatfs.d ./Application/User/FATFS/App/fatfs.o ./Application/User/FATFS/App/fatfs.su

.PHONY: clean-Application-2f-User-2f-FATFS-2f-App

