################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.c 

S_UPPER_SRCS += \
../teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.S 

OBJS += \
./teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.o \
./teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.o 

C_DEPS += \
./teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.d 

S_UPPER_DEPS += \
./teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.d 


# Each subdirectory must supply rules for building sources it contributes
teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.o: ../teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"teclado (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.d" -MT"teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/startup_MKL25Z4.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.o: ../teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"teclado (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.d" -MT"teclado\ (1)/teclado/h3/Project_Settings/Startup_Code/system_MKL25Z4.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


