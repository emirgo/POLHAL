################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/syscalls.c \
../src/system_stm32f1xx.c 

CPP_SRCS += \
../src/POLHAL.cpp \
../src/main.cpp 

OBJS += \
./src/POLHAL.o \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f1xx.o 

C_DEPS += \
./src/syscalls.d \
./src/system_stm32f1xx.d 

CPP_DEPS += \
./src/POLHAL.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -I"/home/heurisitk/dev/POLHAL/HAL_Driver/Inc/Legacy" -I"/home/heurisitk/dev/POLHAL/inc" -I"/home/heurisitk/dev/POLHAL/CMSIS/device" -I"/home/heurisitk/dev/POLHAL/CMSIS/core" -I"/home/heurisitk/dev/POLHAL/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -I"/home/heurisitk/dev/POLHAL/HAL_Driver/Inc/Legacy" -I"/home/heurisitk/dev/POLHAL/inc" -I"/home/heurisitk/dev/POLHAL/CMSIS/device" -I"/home/heurisitk/dev/POLHAL/CMSIS/core" -I"/home/heurisitk/dev/POLHAL/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


