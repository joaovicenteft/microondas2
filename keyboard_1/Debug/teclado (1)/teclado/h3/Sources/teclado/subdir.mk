################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../teclado\ (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.cpp 

OBJS += \
./teclado\ (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.o 

CPP_DEPS += \
./teclado\ (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.d 


# Each subdirectory must supply rules for building sources it contributes
teclado\ (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.o: ../teclado\ (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"teclado (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.d" -MT"teclado\ (1)/teclado/h3/Sources/teclado/mkl_KeyboardParallelPort.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


