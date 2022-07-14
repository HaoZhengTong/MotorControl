/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

/*
 *@Note
 ���ڴ�ӡ�������̣�
 USART1_Tx(PA9)��
 ��������ʾʹ�� USART1(PA9) ����ӡ���Կ������

*/
#include "debug.h"
#include "ch32v30x.h"
#include "ch32v30x_it.h"
#include "Hardware/LED.h"
#include "Hardware/IIC_OLED/IIC_OLED.h"
#include "Hardware/IIC_OLED/OLED_Font.h"
#include "Hardware/KEY.h"
#include "System/USART.h"
#include "Hardware/MotorControl.h"
void System_Init(void)
{
    NVIC_Configuration();                               //�жϷ���
    Delay_Init();                                       //��ʱ������ʼ��
    LEDInit();                                          //LED�˿ڳ�ʼ��
    OLED12864_Init();
    Key_Init();
    USART1_Configuration();
    USART2_Configuration();
    USART3_Configuration();
    USART4_Configuration();
    USART5_Configuration();
    USART6_Configuration();
    USART7_Configuration();
    USART8_Configuration();
}
unsigned short Motor1_Temp=31;//�¶ȱ���
unsigned short Motor2_Temp=32;
unsigned short Motor3_Temp=33;
unsigned short Motor4_Temp=34;

unsigned short Motor1_Current=0.51;//��������
unsigned short Motor2_Current=0.52;
unsigned short Motor3_Current=0.53;
unsigned short Motor4_Current=0.54;

unsigned char Motor1_Mode=1;//ģʽ
unsigned char Motor2_Mode=2;
unsigned char Motor3_Mode=3;
unsigned char Motor4_Mode=4;

unsigned char Motor1_Power=51;//����
unsigned char Motor2_Power=52;
unsigned char Motor3_Power=53;
unsigned char Motor4_Power=54;

extern unsigned char UsartData6;
unsigned int Xdata=500,Ydata=500;               //���ڴ洢ҡ������ ȡֵ��Χ0~1000 �м�ֵ500

extern unsigned short Get_Motor1_Data;
extern unsigned short Get_Motor2_Data;
extern unsigned short Get_Motor3_Data;
extern unsigned short Get_Motor4_Data;

extern unsigned int DataTest;
unsigned char Usart2_buf[4];                        //��������
int main(void)
{
    unsigned char i=0;
    System_Init();
    OLED12864_DisStr(0,0,0,"X:");//��һ��
    OLED12864_DisStr(40,0,0,"Y:");
    OLED12864_DisStr(0,8,0,"M1:");//�ڶ���
    OLED12864_DisStr(72,8,0,"T:");
    OLED12864_DisStr(0,16,0,"M2:");//������
    OLED12864_DisStr(72,16,0,"T:");
    OLED12864_DisStr(0,24,0,"M3:");//������
    OLED12864_DisStr(72,24,0,"T:");
    OLED12864_DisStr(0,32,0,"M4:");//������
    OLED12864_DisStr(72,32,0,"T:");

    OLED12864_DisStr(0,48,0,"M1:");//������
    OLED12864_DisStr(64,48,0,"M2:");
    OLED12864_DisStr(0,56,0,"M3:");//�ڰ���
    OLED12864_DisStr(64,56,0,"M4:");
//    MotorSpeedINIT();
//    Delayxms(1000);
//    MotorSpeedHigh();
//    Delayxms(1000);
//    MotorSpeedLow();
//    Delayxms(1000);
//    MotorTurnLeft();
//    Delayxms(1000);
//    MotorTurnRight();
//    Delayxms(1000);
//    MotorFullSpeed();
//    Delayxms(1000);
//    MotorSTOP();
//    Delayxms(1000);

//    MotorFullSpeedHalf();


//    MotorSpeedHigh();
//    Delayxms(100);
//    MotorSpeedHigh();
//    Delayxms(100);
//    MotorSpeedHigh();
//    Delayxms(100);
//    MotorSpeedHigh();
//    Delayxms(100);
//    MotorSpeedHigh();
//    Delayxms(100);
    while(1)
    {
        OLED12864_Format1(10,0,0,Xdata);                            //ʮ������ʾ����
        OLED12864_Format1(50,0,0,Ydata);                            //ʮ������ʾ����

        OLED12864_Format4(18,8,0,Motor1_Current);                    //�ڶ�����ʾ����
        OLED12864_Format3(84,8,0,Motor1_Temp);                       //�¶�

        OLED12864_Format4(18,16,0,Motor2_Current);                    //��������ʾ����
        OLED12864_Format3(84,16,0,Motor2_Temp);                       //�¶�

        OLED12864_Format4(18,24,0,Motor3_Current);                    //��������ʾ����
        OLED12864_Format3(84,24,0,Motor3_Temp);                       //�¶�

        OLED12864_Format4(18,32,0,Motor4_Current);                    //��������ʾ����
        OLED12864_Format3(84,32,0,Motor4_Temp);                       //�¶�

        OLED12864_Format3(24,48,0,Motor1_Mode);                       //��������ʾģʽ
        OLED12864_Format6(40,48,0,Motor1_Power);                       //�ٶ�

        OLED12864_Format3(84,48,0,Motor2_Mode);
        OLED12864_Format6(104,48,0,Motor2_Power);

        OLED12864_Format3(24,56,0,Motor3_Mode);                         //�ڰ�����ʾģʽ
        OLED12864_Format6(40,56,0,Motor3_Power);                        //�ٶ�

        OLED12864_Format3(84,56,0,Motor4_Mode);
        OLED12864_Format6(104,56,0,Motor4_Power);

        OLED12864_Format1(90,0,0,i);
        i++;
        //Delayxms(1000);
        MotorTempGet();
        Delayxms(100);
        Motor1_Temp=Get_Motor1_Data;
        Motor2_Temp=Get_Motor2_Data;
        Motor3_Temp=Get_Motor3_Data;
        Motor4_Temp=Get_Motor4_Data;
        MotorCurrentGet();
        Delayxms(100);
        Motor1_Current=(unsigned int)((float)Get_Motor1_Data*17);
        Motor2_Current=(unsigned int)((float)Get_Motor2_Data*17);
        Motor3_Current=(unsigned int)((float)Get_Motor3_Data*34);
        Motor4_Current=(unsigned int)((float)Get_Motor4_Data*34);
        MotorPowerGet();
        Delayxms(100);
        Motor1_Power=Get_Motor1_Data;
        Motor2_Power=Get_Motor2_Data;
        Motor3_Power=Get_Motor3_Data;
        Motor4_Power=Get_Motor4_Data;
//        USARTx_SendByte(USART1,i);
//        USARTx_SendByte(USART2,i);
//        USARTx_SendByte(USART3,i);
//        USARTx_SendByte(UART4,i);
//        USARTx_SendByte(UART5,i);
//        USARTx_SendByte(UART6,i);
//        USARTx_SendByte(UART7,i);
//        USARTx_SendByte(UART8,i);
    }
}

