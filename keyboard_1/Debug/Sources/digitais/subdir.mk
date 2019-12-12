################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/digitais/digitalFactory.cpp \
../Sources/digitais/registrador.cpp 

OBJS += \
./Sources/digitais/digitalFactory.o \
./Sources/digitais/registrador.o 

CPP_DEPS += \
./Sources/digitais/digitalFactory.d \
./Sources/digitais/registrador.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/digitais/%.o: ../Sources/digitais/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


