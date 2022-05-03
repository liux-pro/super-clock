################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/intel/tinycrypt/lib/source/ccm_mode.c \
../ra/intel/tinycrypt/lib/source/cmac_mode.c \
../ra/intel/tinycrypt/lib/source/ctr_prng.c \
../ra/intel/tinycrypt/lib/source/ecc.c \
../ra/intel/tinycrypt/lib/source/ecc_dh.c \
../ra/intel/tinycrypt/lib/source/ecc_dsa.c \
../ra/intel/tinycrypt/lib/source/ecc_platform_specific.c \
../ra/intel/tinycrypt/lib/source/hmac.c \
../ra/intel/tinycrypt/lib/source/hmac_prng.c \
../ra/intel/tinycrypt/lib/source/sha256.c \
../ra/intel/tinycrypt/lib/source/utils.c 

C_DEPS += \
./ra/intel/tinycrypt/lib/source/ccm_mode.d \
./ra/intel/tinycrypt/lib/source/cmac_mode.d \
./ra/intel/tinycrypt/lib/source/ctr_prng.d \
./ra/intel/tinycrypt/lib/source/ecc.d \
./ra/intel/tinycrypt/lib/source/ecc_dh.d \
./ra/intel/tinycrypt/lib/source/ecc_dsa.d \
./ra/intel/tinycrypt/lib/source/ecc_platform_specific.d \
./ra/intel/tinycrypt/lib/source/hmac.d \
./ra/intel/tinycrypt/lib/source/hmac_prng.d \
./ra/intel/tinycrypt/lib/source/sha256.d \
./ra/intel/tinycrypt/lib/source/utils.d 

OBJS += \
./ra/intel/tinycrypt/lib/source/ccm_mode.o \
./ra/intel/tinycrypt/lib/source/cmac_mode.o \
./ra/intel/tinycrypt/lib/source/ctr_prng.o \
./ra/intel/tinycrypt/lib/source/ecc.o \
./ra/intel/tinycrypt/lib/source/ecc_dh.o \
./ra/intel/tinycrypt/lib/source/ecc_dsa.o \
./ra/intel/tinycrypt/lib/source/ecc_platform_specific.o \
./ra/intel/tinycrypt/lib/source/hmac.o \
./ra/intel/tinycrypt/lib/source/hmac_prng.o \
./ra/intel/tinycrypt/lib/source/sha256.o \
./ra/intel/tinycrypt/lib/source/utils.o 


# Each subdirectory must supply rules for building sources it contributes
ra/intel/tinycrypt/lib/source/%.o: ../ra/intel/tinycrypt/lib/source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM23 -D_RENESAS_RA_ -I"D:\ra\workspace\super_clock\src" -I"D:\ra\workspace\super_clock\ra\fsp\inc" -I"D:\ra\workspace\super_clock\ra\fsp\inc\api" -I"D:\ra\workspace\super_clock\ra\fsp\inc\instances" -I"D:\ra\workspace\super_clock\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"D:\ra\workspace\super_clock\ra_gen" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg\bsp" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg" -I"D:\ra\workspace\super_clock\ra\fsp\src\rm_tinycrypt_port\inc" -I"D:\ra\workspace\super_clock\ra\intel\tinycrypt\lib\include" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce\ra2" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce\common" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


