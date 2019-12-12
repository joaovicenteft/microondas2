################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/dispositivos/decoder.cpp \
../Sources/dispositivos/displaySegments.cpp \
../Sources/dispositivos/led.cpp \
../Sources/dispositivos/switch.cpp 

OBJS += \
./Sources/dispositivos/decoder.o \
./Sources/dispositivos/displaySegments.o \
./Sources/dispositivos/led.o \
./Sources/dispositivos/switch.o 

CPP_DEPS += \
./Sources/dispositivos/decoder.d \
./Sources/dispositivos/displaySegments.d \
./Sources/dispositivos/led.d \
./Sources/dispositivos/switch.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/dispositivos/%.o: ../Sources/dispositivos/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


