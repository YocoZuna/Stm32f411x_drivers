################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32f411x_gpio.c 

OBJS += \
./Drivers/Src/stm32f411x_gpio.o 

C_DEPS += \
./Drivers/Src/stm32f411x_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/Users/dawid/STM32CubeIDE/workspace_1.10.1/Stm32f411x_drivers/Stm32f411x/Drivers/Inc" -I"C:/Users/dawid/STM32CubeIDE/workspace_1.10.1/Stm32f411x_drivers/Stm32f411x/Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32f411x_gpio.d ./Drivers/Src/stm32f411x_gpio.o ./Drivers/Src/stm32f411x_gpio.su

.PHONY: clean-Drivers-2f-Src

