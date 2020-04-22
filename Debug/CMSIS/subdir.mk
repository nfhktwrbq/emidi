################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_stm32f4xx.c 

OBJS += \
./CMSIS/system_stm32f4xx.o 

C_DEPS += \
./CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/system_stm32f4xx.o: ../CMSIS/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"/home/muaddib/STM32CubeIDE/workspace_1.3.0/emidi/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

