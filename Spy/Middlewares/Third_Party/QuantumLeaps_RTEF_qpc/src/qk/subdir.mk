################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.c 

OBJS += \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.o 

C_DEPS += \
./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/%.o Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/%.su Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/%.cyclo: ../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/%.c Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32G431xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DQ_SPY -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/include -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/ports/arm-cm/qk/gnu/ -I../Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/ports/arm-cm/qk/config -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-QuantumLeaps_RTEF_qpc-2f-src-2f-qk

clean-Middlewares-2f-Third_Party-2f-QuantumLeaps_RTEF_qpc-2f-src-2f-qk:
	-$(RM) ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.cyclo ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.d ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.o ./Middlewares/Third_Party/QuantumLeaps_RTEF_qpc/src/qk/qk.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-QuantumLeaps_RTEF_qpc-2f-src-2f-qk

