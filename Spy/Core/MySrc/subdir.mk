################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/MySrc/QSpy.c \
../Core/MySrc/blinky.c \
../Core/MySrc/bsp.c 

OBJS += \
./Core/MySrc/QSpy.o \
./Core/MySrc/blinky.o \
./Core/MySrc/bsp.o 

C_DEPS += \
./Core/MySrc/QSpy.d \
./Core/MySrc/blinky.d \
./Core/MySrc/bsp.d 


# Each subdirectory must supply rules for building sources it contributes
Core/MySrc/%.o Core/MySrc/%.su Core/MySrc/%.cyclo: ../Core/MySrc/%.c Core/MySrc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32G431xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DQ_SPY -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/include -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/ports/arm-cm/qk/gnu/ -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/ports/arm-cm/qk/config -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-MySrc

clean-Core-2f-MySrc:
	-$(RM) ./Core/MySrc/QSpy.cyclo ./Core/MySrc/QSpy.d ./Core/MySrc/QSpy.o ./Core/MySrc/QSpy.su ./Core/MySrc/blinky.cyclo ./Core/MySrc/blinky.d ./Core/MySrc/blinky.o ./Core/MySrc/blinky.su ./Core/MySrc/bsp.cyclo ./Core/MySrc/bsp.d ./Core/MySrc/bsp.o ./Core/MySrc/bsp.su

.PHONY: clean-Core-2f-MySrc

