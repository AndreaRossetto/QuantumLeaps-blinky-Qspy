################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.c \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.c \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.c \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.c \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.c \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.c 

OBJS += \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.o \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.o \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.o \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.o \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.o \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.o 

C_DEPS += \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.d \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.d \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.d \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.d \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.d \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/%.o Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/%.su Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/%.cyclo: ../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/%.c Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32G431xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DQ_SPY -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/include -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/ports/arm-cm/qk/gnu/ -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/ports/arm-cm/qk/config -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-QuantumLeaps_RTEF_qpc-2f-src-2f-qs

clean-Middlewares-2f-Third_Party-2f-QuantumLeaps_RTEF_qpc-2f-src-2f-qs:
	-$(RM) ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs.su ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_64bit.su ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_fp.su ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qs_rx.su ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qstamp.su ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qs/qutest.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-QuantumLeaps_RTEF_qpc-2f-src-2f-qs

