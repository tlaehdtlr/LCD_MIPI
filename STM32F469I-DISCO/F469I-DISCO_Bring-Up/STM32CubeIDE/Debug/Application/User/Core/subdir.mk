################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/cli.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/dma2d.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/dsihost.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/fmc.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/ft6x06.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/gpio.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/i2c.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/lcd_control.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/ltdc.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/main.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/nt35510.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/stm32f4xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/touch_screen.c \
C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/usart.c 

OBJS += \
./Application/User/Core/cli.o \
./Application/User/Core/dma2d.o \
./Application/User/Core/dsihost.o \
./Application/User/Core/fmc.o \
./Application/User/Core/ft6x06.o \
./Application/User/Core/gpio.o \
./Application/User/Core/i2c.o \
./Application/User/Core/lcd_control.o \
./Application/User/Core/ltdc.o \
./Application/User/Core/main.o \
./Application/User/Core/nt35510.o \
./Application/User/Core/stm32f4xx_hal_msp.o \
./Application/User/Core/stm32f4xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o \
./Application/User/Core/touch_screen.o \
./Application/User/Core/usart.o 

C_DEPS += \
./Application/User/Core/cli.d \
./Application/User/Core/dma2d.d \
./Application/User/Core/dsihost.d \
./Application/User/Core/fmc.d \
./Application/User/Core/ft6x06.d \
./Application/User/Core/gpio.d \
./Application/User/Core/i2c.d \
./Application/User/Core/lcd_control.d \
./Application/User/Core/ltdc.d \
./Application/User/Core/main.d \
./Application/User/Core/nt35510.d \
./Application/User/Core/stm32f4xx_hal_msp.d \
./Application/User/Core/stm32f4xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d \
./Application/User/Core/touch_screen.d \
./Application/User/Core/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/cli.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/cli.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/dma2d.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/dma2d.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/dsihost.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/dsihost.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/fmc.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/fmc.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/ft6x06.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/ft6x06.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/gpio.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/gpio.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/i2c.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/i2c.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/lcd_control.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/lcd_control.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/ltdc.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/ltdc.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/nt35510.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/nt35510.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_msp.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/stm32f4xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_it.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/stm32f4xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/%.o Application/User/Core/%.su: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/touch_screen.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/touch_screen.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/usart.o: C:/Users/2023851/Projects/Vieworks_SIM/LCD_MIPI/STM32F469I-DISCO/F469I-DISCO_Bring-Up/Core/Src/usart.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/cli.d ./Application/User/Core/cli.o ./Application/User/Core/cli.su ./Application/User/Core/dma2d.d ./Application/User/Core/dma2d.o ./Application/User/Core/dma2d.su ./Application/User/Core/dsihost.d ./Application/User/Core/dsihost.o ./Application/User/Core/dsihost.su ./Application/User/Core/fmc.d ./Application/User/Core/fmc.o ./Application/User/Core/fmc.su ./Application/User/Core/ft6x06.d ./Application/User/Core/ft6x06.o ./Application/User/Core/ft6x06.su ./Application/User/Core/gpio.d ./Application/User/Core/gpio.o ./Application/User/Core/gpio.su ./Application/User/Core/i2c.d ./Application/User/Core/i2c.o ./Application/User/Core/i2c.su ./Application/User/Core/lcd_control.d ./Application/User/Core/lcd_control.o ./Application/User/Core/lcd_control.su ./Application/User/Core/ltdc.d ./Application/User/Core/ltdc.o ./Application/User/Core/ltdc.su ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/main.su ./Application/User/Core/nt35510.d ./Application/User/Core/nt35510.o ./Application/User/Core/nt35510.su ./Application/User/Core/stm32f4xx_hal_msp.d ./Application/User/Core/stm32f4xx_hal_msp.o ./Application/User/Core/stm32f4xx_hal_msp.su ./Application/User/Core/stm32f4xx_it.d ./Application/User/Core/stm32f4xx_it.o ./Application/User/Core/stm32f4xx_it.su ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/syscalls.su ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/sysmem.su ./Application/User/Core/touch_screen.d ./Application/User/Core/touch_screen.o ./Application/User/Core/touch_screen.su ./Application/User/Core/usart.d ./Application/User/Core/usart.o ./Application/User/Core/usart.su

.PHONY: clean-Application-2f-User-2f-Core

