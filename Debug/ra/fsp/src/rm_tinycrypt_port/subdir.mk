################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port.c \
../ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_aes_decrypt.c \
../ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_aes_encrypt.c \
../ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_cbc_mode.c \
../ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_ctr_mode.c 

C_DEPS += \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port.d \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_aes_decrypt.d \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_aes_encrypt.d \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_cbc_mode.d \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_ctr_mode.d 

OBJS += \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port.o \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_aes_decrypt.o \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_aes_encrypt.o \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_cbc_mode.o \
./ra/fsp/src/rm_tinycrypt_port/rm_tinycrypt_port_ctr_mode.o 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/rm_tinycrypt_port/%.o: ../ra/fsp/src/rm_tinycrypt_port/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM23 -D_RENESAS_RA_ -I"D:\ra\workspace\super_clock\src" -I"D:\ra\workspace\super_clock\ra\fsp\inc" -I"D:\ra\workspace\super_clock\ra\fsp\inc\api" -I"D:\ra\workspace\super_clock\ra\fsp\inc\instances" -I"D:\ra\workspace\super_clock\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"D:\ra\workspace\super_clock\ra_gen" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg\bsp" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg" -I"D:\ra\workspace\super_clock\ra\fsp\src\rm_tinycrypt_port\inc" -I"D:\ra\workspace\super_clock\ra\intel\tinycrypt\lib\include" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce\ra2" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce\common" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '

