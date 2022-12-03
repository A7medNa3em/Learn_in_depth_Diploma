################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KeyPad_DRIVER/KeyPad.c \
../HAL/KeyPad_DRIVER/keypad_cfg.c 

OBJS += \
./HAL/KeyPad_DRIVER/KeyPad.o \
./HAL/KeyPad_DRIVER/keypad_cfg.o 

C_DEPS += \
./HAL/KeyPad_DRIVER/KeyPad.d \
./HAL/KeyPad_DRIVER/keypad_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KeyPad_DRIVER/KeyPad.o: ../HAL/KeyPad_DRIVER/KeyPad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/KeyPad_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/LCD_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/MCAL_STM32F103C6/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KeyPad_DRIVER/KeyPad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/KeyPad_DRIVER/keypad_cfg.o: ../HAL/KeyPad_DRIVER/keypad_cfg.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/KeyPad_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/LCD_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/MCAL_STM32F103C6/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KeyPad_DRIVER/keypad_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

