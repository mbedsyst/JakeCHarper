################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f401retx.s 

C_SRCS += \
../Startup/system_stm32f4xx.c 

OBJS += \
./Startup/startup_stm32f401retx.o \
./Startup/system_stm32f4xx.o 

S_DEPS += \
./Startup/startup_stm32f401retx.d 

C_DEPS += \
./Startup/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Startup/%.o Startup/%.su Startup/%.cyclo: ../Startup/%.c Startup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401xE -c -I../Inc -I"C:/Users/zalma/OneDrive/Documents/mbedsyst_STM32/MusicalKeyboard/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/zalma/OneDrive/Documents/mbedsyst_STM32/MusicalKeyboard/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f401retx.d ./Startup/startup_stm32f401retx.o ./Startup/system_stm32f4xx.cyclo ./Startup/system_stm32f4xx.d ./Startup/system_stm32f4xx.o ./Startup/system_stm32f4xx.su

.PHONY: clean-Startup

