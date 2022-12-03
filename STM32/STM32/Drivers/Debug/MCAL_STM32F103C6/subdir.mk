################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_STM32F103C6/EXTI.c \
../MCAL_STM32F103C6/GPIO.c \
../MCAL_STM32F103C6/GPIO_cfg.c 

OBJS += \
./MCAL_STM32F103C6/EXTI.o \
./MCAL_STM32F103C6/GPIO.o \
./MCAL_STM32F103C6/GPIO_cfg.o 

C_DEPS += \
./MCAL_STM32F103C6/EXTI.d \
./MCAL_STM32F103C6/GPIO.d \
./MCAL_STM32F103C6/GPIO_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_STM32F103C6/EXTI.o: ../MCAL_STM32F103C6/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/KeyPad_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/LCD_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/MCAL_STM32F103C6/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL_STM32F103C6/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL_STM32F103C6/GPIO.o: ../MCAL_STM32F103C6/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/KeyPad_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/LCD_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/MCAL_STM32F103C6/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL_STM32F103C6/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL_STM32F103C6/GPIO_cfg.o: ../MCAL_STM32F103C6/GPIO_cfg.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/KeyPad_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/HAL/LCD_DRIVER/includes" -I"F:/Learn_in_Depth Course/Diploma_Repo/STM32/STM32/Drivers/MCAL_STM32F103C6/includes" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL_STM32F103C6/GPIO_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

