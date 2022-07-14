################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/System/USART.c 

OBJS += \
./User/System/USART.o 

C_DEPS += \
./User/System/USART.d 


# Each subdirectory must supply rules for building sources it contributes
User/System/%.o: ../User/System/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\COURAGE\Desktop\上位机控制软件（CH32）\Debug" -I"C:\Users\COURAGE\Desktop\上位机控制软件（CH32）\Core" -I"C:\Users\COURAGE\Desktop\上位机控制软件（CH32）\User" -I"C:\Users\COURAGE\Desktop\上位机控制软件（CH32）\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

