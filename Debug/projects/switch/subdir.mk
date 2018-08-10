################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../projects/switch/switch.c 

OBJS += \
./projects/switch/switch.o 

C_DEPS += \
./projects/switch/switch.d 


# Each subdirectory must supply rules for building sources it contributes
projects/switch/%.o: ../projects/switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabi-gcc -I/usr/arm-linux-gnueabi/include -I/usr/arm-linux-gnueabi/include/c++/5 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


