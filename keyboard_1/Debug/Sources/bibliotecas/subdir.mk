################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/bibliotecas/dsf_Delay_ocp.cpp \
../Sources/bibliotecas/dsf_TPM_ocp.cpp \
../Sources/bibliotecas/mkl_GPIO.cpp \
../Sources/bibliotecas/mkl_GPIOInterrupt.cpp \
../Sources/bibliotecas/mkl_GPIOPort.cpp \
../Sources/bibliotecas/mkl_Systick.cpp \
../Sources/bibliotecas/mkl_SystickPeriodicInterrupt.cpp 

OBJS += \
./Sources/bibliotecas/dsf_Delay_ocp.o \
./Sources/bibliotecas/dsf_TPM_ocp.o \
./Sources/bibliotecas/mkl_GPIO.o \
./Sources/bibliotecas/mkl_GPIOInterrupt.o \
./Sources/bibliotecas/mkl_GPIOPort.o \
./Sources/bibliotecas/mkl_Systick.o \
./Sources/bibliotecas/mkl_SystickPeriodicInterrupt.o 

CPP_DEPS += \
./Sources/bibliotecas/dsf_Delay_ocp.d \
./Sources/bibliotecas/dsf_TPM_ocp.d \
./Sources/bibliotecas/mkl_GPIO.d \
./Sources/bibliotecas/mkl_GPIOInterrupt.d \
./Sources/bibliotecas/mkl_GPIOPort.d \
./Sources/bibliotecas/mkl_Systick.d \
./Sources/bibliotecas/mkl_SystickPeriodicInterrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bibliotecas/%.o: ../Sources/bibliotecas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


