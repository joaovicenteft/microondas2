################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../teclado\ (1)/teclado/h3/Sources/digitais/digitalFactory.cpp \
../teclado\ (1)/teclado/h3/Sources/digitais/registrador.cpp 

OBJS += \
./teclado\ (1)/teclado/h3/Sources/digitais/digitalFactory.o \
./teclado\ (1)/teclado/h3/Sources/digitais/registrador.o 

CPP_DEPS += \
./teclado\ (1)/teclado/h3/Sources/digitais/digitalFactory.d \
./teclado\ (1)/teclado/h3/Sources/digitais/registrador.d 


# Each subdirectory must supply rules for building sources it contributes
teclado\ (1)/teclado/h3/Sources/digitais/digitalFactory.o: ../teclado\ (1)/teclado/h3/Sources/digitais/digitalFactory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"teclado (1)/teclado/h3/Sources/digitais/digitalFactory.d" -MT"teclado\ (1)/teclado/h3/Sources/digitais/digitalFactory.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

teclado\ (1)/teclado/h3/Sources/digitais/registrador.o: ../teclado\ (1)/teclado/h3/Sources/digitais/registrador.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"teclado (1)/teclado/h3/Sources/digitais/registrador.d" -MT"teclado\ (1)/teclado/h3/Sources/digitais/registrador.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


