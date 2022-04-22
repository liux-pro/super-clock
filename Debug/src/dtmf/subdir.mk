################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dtmf/goertzel-dtmf.c \
../src/dtmf/goertzel.c 

C_DEPS += \
./src/dtmf/goertzel-dtmf.d \
./src/dtmf/goertzel.d 

OBJS += \
./src/dtmf/goertzel-dtmf.o \
./src/dtmf/goertzel.o 


# Each subdirectory must supply rules for building sources it contributes
src/dtmf/%.o: ../src/dtmf/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM23 -D_RENESAS_RA_ -I"D:\ra\workspace\super_clock\src" -I"D:\ra\workspace\super_clock\ra\fsp\inc" -I"D:\ra\workspace\super_clock\ra\fsp\inc\api" -I"D:\ra\workspace\super_clock\ra\fsp\inc\instances" -I"D:\ra\workspace\super_clock\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"D:\ra\workspace\super_clock\ra_gen" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg\bsp" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '

