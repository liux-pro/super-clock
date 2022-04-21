################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/hal_entry.cpp \
../src/ws2812.cpp 

OBJS += \
./src/hal_entry.o \
./src/ws2812.o 

CPP_DEPS += \
./src/hal_entry.d \
./src/ws2812.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM23 -D_RENESAS_RA_ -I"D:\ra\workspace\super_clock\src" -I"D:\ra\workspace\super_clock\ra\fsp\inc" -I"D:\ra\workspace\super_clock\ra\fsp\inc\api" -I"D:\ra\workspace\super_clock\ra\fsp\inc\instances" -I"D:\ra\workspace\super_clock\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"D:\ra\workspace\super_clock\ra_gen" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg\bsp" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg" -std=c++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


