################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/I2CDevice.cpp \
../src/pmvMPU6050.cpp 

OBJS += \
./src/I2CDevice.o \
./src/pmvMPU6050.o 

CPP_DEPS += \
./src/I2CDevice.d \
./src/pmvMPU6050.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/usr/arm-linux-gnueabihf/include -I/usr/arm-linux-gnueabihf/include/c++/7.3.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


