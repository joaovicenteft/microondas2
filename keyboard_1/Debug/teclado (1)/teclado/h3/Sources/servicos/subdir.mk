################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../teclado\ (1)/teclado/h3/Sources/servicos/EditService.cpp \
../teclado\ (1)/teclado/h3/Sources/servicos/IncrementService.cpp 

OBJS += \
./teclado\ (1)/teclado/h3/Sources/servicos/EditService.o \
./teclado\ (1)/teclado/h3/Sources/servicos/IncrementService.o 

CPP_DEPS += \
./teclado\ (1)/teclado/h3/Sources/servicos/EditService.d \
./teclado\ (1)/teclado/h3/Sources/servicos/IncrementService.d 


# Each subdirectory must supply rules for building sources it contributes
teclado\ (1)/teclado/h3/Sources/servicos/EditService.o: ../teclado\ (1)/teclado/h3/Sources/servicos/EditService.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"teclado (1)/teclado/h3/Sources/servicos/EditService.d" -MT"teclado\ (1)/teclado/h3/Sources/servicos/EditService.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

teclado\ (1)/teclado/h3/Sources/servicos/IncrementService.o: ../teclado\ (1)/teclado/h3/Sources/servicos/IncrementService.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"teclado (1)/teclado/h3/Sources/servicos/IncrementService.d" -MT"teclado\ (1)/teclado/h3/Sources/servicos/IncrementService.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


