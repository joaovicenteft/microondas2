################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/mkl_Systick/mkl_Systick.cpp 

OBJS += \
./Sources/mkl_Systick/mkl_Systick.o 

CPP_DEPS += \
./Sources/mkl_Systick/mkl_Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/mkl_Systick/%.o: ../Sources/mkl_Systick/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


