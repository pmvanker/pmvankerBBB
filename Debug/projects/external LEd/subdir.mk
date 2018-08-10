################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../projects/external\ LEd/led.c 

OBJS += \
./projects/external\ LEd/led.o 

C_DEPS += \
./projects/external\ LEd/led.d 


# Each subdirectory must supply rules for building sources it contributes
projects/external\ LEd/led.o: ../projects/external\ LEd/led.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabi-gcc -I/usr/arm-linux-gnueabi/include -I/usr/arm-linux-gnueabi/include/c++/5 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"projects/external LEd/led.d" -MT"projects/external\ LEd/led.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


