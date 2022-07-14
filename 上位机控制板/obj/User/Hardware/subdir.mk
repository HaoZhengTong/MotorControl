################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Hardware/KEY.c \
../User/Hardware/LED.c \
../User/Hardware/MotorControl.c 

OBJS += \
./User/Hardware/KEY.o \
./User/Hardware/LED.o \
./User/Hardware/MotorControl.o 

C_DEPS += \
./User/Hardware/KEY.d \
./User/Hardware/LED.d \
./User/Hardware/MotorControl.d 


# Each subdirectory must supply rules for building sources it contributes
User/Hardware/%.o: ../User/Hardware/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\COURAGE\Desktop\��λ�����������CH32��\Debug" -I"C:\Users\COURAGE\Desktop\��λ�����������CH32��\Core" -I"C:\Users\COURAGE\Desktop\��λ�����������CH32��\User" -I"C:\Users\COURAGE\Desktop\��λ�����������CH32��\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

