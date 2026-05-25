################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/IrSensor.c \
../Src/LED.c \
../Src/button.c \
../Src/main.c \
../Src/motor.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/IrSensor.o \
./Src/LED.o \
./Src/button.o \
./Src/main.o \
./Src/motor.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/IrSensor.d \
./Src/LED.d \
./Src/button.d \
./Src/main.d \
./Src/motor.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/IrSensor.cyclo ./Src/IrSensor.d ./Src/IrSensor.o ./Src/IrSensor.su ./Src/LED.cyclo ./Src/LED.d ./Src/LED.o ./Src/LED.su ./Src/button.cyclo ./Src/button.d ./Src/button.o ./Src/button.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/motor.cyclo ./Src/motor.d ./Src/motor.o ./Src/motor.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

