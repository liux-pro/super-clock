################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_sce/ra2/SC324_endian.c \
../ra/fsp/src/r_sce/ra2/SC324_p03.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p04.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p05.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p06.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p07.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p08.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p20.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p21.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p22.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p23.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_p24.prc.c \
../ra/fsp/src/r_sce/ra2/SC324_utils.c \
../ra/fsp/src/r_sce/ra2/sc324_aes_private.c 

C_DEPS += \
./ra/fsp/src/r_sce/ra2/SC324_endian.d \
./ra/fsp/src/r_sce/ra2/SC324_p03.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p04.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p05.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p06.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p07.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p08.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p20.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p21.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p22.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p23.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_p24.prc.d \
./ra/fsp/src/r_sce/ra2/SC324_utils.d \
./ra/fsp/src/r_sce/ra2/sc324_aes_private.d 

OBJS += \
./ra/fsp/src/r_sce/ra2/SC324_endian.o \
./ra/fsp/src/r_sce/ra2/SC324_p03.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p04.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p05.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p06.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p07.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p08.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p20.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p21.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p22.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p23.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_p24.prc.o \
./ra/fsp/src/r_sce/ra2/SC324_utils.o \
./ra/fsp/src/r_sce/ra2/sc324_aes_private.o 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_sce/ra2/%.o: ../ra/fsp/src/r_sce/ra2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RA_CORE=CM23 -D_RENESAS_RA_ -I"D:\ra\workspace\super_clock\src" -I"D:\ra\workspace\super_clock\ra\fsp\inc" -I"D:\ra\workspace\super_clock\ra\fsp\inc\api" -I"D:\ra\workspace\super_clock\ra\fsp\inc\instances" -I"D:\ra\workspace\super_clock\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"D:\ra\workspace\super_clock\ra_gen" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg\bsp" -I"D:\ra\workspace\super_clock\ra_cfg\fsp_cfg" -I"D:\ra\workspace\super_clock\ra\fsp\src\rm_tinycrypt_port\inc" -I"D:\ra\workspace\super_clock\ra\intel\tinycrypt\lib\include" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce\ra2" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce\common" -I"D:\ra\workspace\super_clock\ra\fsp\src\r_sce" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


