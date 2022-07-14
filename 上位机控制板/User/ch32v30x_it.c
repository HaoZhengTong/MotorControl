/********************************** (C) COPYRIGHT *******************************
* File Name          : ch32v30x_it.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main Interrupt Service Routines.
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/
#include "ch32v30x_it.h"
#include "Hardware/LED.h"
#include "Hardware/MotorControl.h"

/********************************************************************
*��    ��:NVIC_Configration(void)
*��    ��:�жϷ��麯��������TIM1~4��USART1
*��ڲ���:��
*���ڲ���:��
*˵    ��:��
*���÷���:��
********************************************************************/
void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��1���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;          //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��2���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;             //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��3���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;             //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��4���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;             //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��5���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;             //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��6���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;             //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��7���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;             //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //��ʱ��8���ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_IRQn;          //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 8;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;           //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 9;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;           //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 10;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;            //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 11;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;            //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 12;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = UART6_IRQn;            //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 13;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;          //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 14;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //�������ȼ��ַ���
    NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;            //ָ����IRQ�ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 18;          //��Ӧ���ȼ���
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);

}
/*******************************************************************************
���ƣ�void USART1_IRQHandler(void)
���ܣ�����1���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/

unsigned char Usart1Data=0;
void USART1_IRQHandler(void)          //USART1�����жϺ���
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(USART1,USART_IT_RXNE);      //����жϱ�
        Usart1Data = USART_ReceiveData(USART1);             //��ȡ����1���յ�������
        //USART_SendData(USART1,Usart1Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
}

/*******************************************************************************
���ƣ�void USART2_IRQHandler(void)
���ܣ�����2���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/
unsigned char UsartData2=0;
extern unsigned short Motor1_Temp;                          //���1�¶�����
unsigned short Get_Motor1_Data=0;
unsigned char Usart2_buf[4]={0};                        //��������
unsigned char Usart2_Index=0;                                  //��������
unsigned char Usart2_Status=0;                                 //�м����

unsigned int DataTest=0;
void USART2_IRQHandler(void)          //USART2�����жϺ���
{
    unsigned short temp=0;
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(USART2,USART_IT_RXNE);      //����жϱ�
        UsartData2 = USART_ReceiveData(USART2);             //��ȡ����1���յ�������
        //USART_SendData(USART2,Usart2Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(USART2,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
    switch(Usart2_Status)//��ȡ�¶�����
    {
        case 0:
            if(UsartData2==0xa5)
            {
                Usart2_Status=1;
                Usart2_buf[Usart2_Index]=UsartData2;//�������ź�0xa5����
                Usart2_Index=1;

            }
        break;
        case 1:
            Usart2_buf[Usart2_Index]=UsartData2;//�洢��һ���¶�����
            Usart2_Index=2;
            Usart2_Status=2;
        break;
        case 2:
            Usart2_buf[Usart2_Index]=UsartData2;//�洢��һ���¶�����
            Usart2_Index=3;
            Usart2_Status=3;

        break;
        case 3:
            if((Usart2_buf[1]^Usart2_buf[2]) == UsartData2)
            {
                Usart2_buf[Usart2_Index]=UsartData2;
                Usart2_Index=0;
                Usart2_Status=0;
                Get_Motor1_Data=0;
                Get_Motor1_Data=Usart2_buf[1];                  //�����¶ȸ�λ
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];   //����¶�����
                temp=Get_Motor1_Data<<8;
                Get_Motor1_Data=temp+Usart2_buf[2];   //����¶�����
                DataTest=Usart2_buf[3];
//                Usart2_buf[0]=0;
//                Usart2_buf[1]=0;
//                Usart2_buf[2]=0;
//                Usart2_buf[3]=0;
            }
            else
            {
//                Usart2_buf[0]=0;
//                Usart2_buf[1]=0;
//                Usart2_buf[2]=0;
//                Usart2_buf[3]=0;
                Usart2_Index=0;
                Usart2_Status=0;
                Get_Motor1_Data=0;
            }
        break;
        default:break;
    }
}

/*******************************************************************************
���ƣ�void USART3_IRQHandler(void)
���ܣ�����3���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/

 unsigned char Usart3Data=0;
void USART3_IRQHandler(void)          //USART3�����жϺ���
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(USART3,USART_IT_RXNE);      //����жϱ�
        Usart3Data = USART_ReceiveData(USART3);             //��ȡ����1���յ�������
        //USART_SendData(USART3,Usart3Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
}

/*******************************************************************************
���ƣ�void UART4_IRQHandler(void)
���ܣ�����4���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/
unsigned char UsartData4=0;
unsigned short Get_Motor3_Data=0;
unsigned char Usart4_buf[4]={0};                                //��������
unsigned char Usart4_Index=0;                                  //��������
unsigned char Usart4_Status=0;                                 //�м����
void UART4_IRQHandler(void)          //UART4�����жϺ���
{
    unsigned short temp=0;
    if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(UART4,USART_IT_RXNE);      //����жϱ�
        UsartData4 = USART_ReceiveData(UART4);             //��ȡ����1���յ�������
        //USART_SendData(UART8,Usart8Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(UART8,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
    switch(Usart4_Status)//��ȡ�¶�����
    {
        case 0:
            if(UsartData4==0xa5)
            {
                Usart4_Status=1;
                Usart4_buf[Usart4_Index]=UsartData4;//�������ź�0xa5����
                Usart4_Index=1;
            }
        break;
        case 1:
            Usart4_buf[Usart4_Index]=UsartData4;//�洢��һ���¶�����
            Usart4_Index=2;
            Usart4_Status=2;
        break;
        case 2:
            Usart4_buf[Usart4_Index]=UsartData4;//�洢��һ���¶�����
            Usart4_Index=3;
            Usart4_Status=3;
        break;
        case 3:
            if((Usart4_buf[1]^Usart4_buf[2]) == UsartData4)
            {
                Usart4_buf[Usart4_Index]=UsartData4;
                Usart4_Index=0;
                Usart4_Status=0;
                Get_Motor3_Data=Usart4_buf[1];                  //�����¶ȸ�λ
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];   //����¶�����
                temp=Get_Motor3_Data<<8;
                Get_Motor3_Data=temp+Usart4_buf[2];   //����¶�����
                Usart4_buf[0]=0;
                Usart4_buf[1]=0;
                Usart4_buf[2]=0;
                Usart4_buf[3]=0;
            }
            else
            {
                Usart4_buf[0]=0;
                Usart4_buf[1]=0;
                Usart4_buf[2]=0;
                Usart4_buf[3]=0;
                Usart4_Index=0;
                Usart4_Status=0;
                Get_Motor3_Data=0;
            }
        break;
        default:break;
    }
}

/*******************************************************************************
���ƣ�void UART5_IRQHandler(void)
���ܣ�����5���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/
unsigned char UsartData5=0;
unsigned short Get_Motor4_Data=0;
unsigned char Usart5_buf[4]={0};                                //��������
unsigned char Usart5_Index=0;                                  //��������
unsigned char Usart5_Status=0;                                 //�м����
void UART5_IRQHandler(void)          //UART5�����жϺ���
{
    unsigned short temp=0;
    if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(UART5,USART_IT_RXNE);      //����жϱ�
        UsartData5 = USART_ReceiveData(UART5);             //��ȡ����1���յ�������
        //USART_SendData(UART8,Usart8Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(UART8,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
    switch(Usart5_Status)//��ȡ�¶�����
    {
        case 0:
            if(UsartData5==0xa5)
            {
                Usart5_Status=1;
                Usart5_buf[Usart5_Index]=UsartData5;//�������ź�0xa5����
                Usart5_Index=1;
            }
        break;
        case 1:
            Usart5_buf[Usart5_Index]=UsartData5;//�洢��һ���¶�����
            Usart5_Index=2;
            Usart5_Status=2;
        break;
        case 2:
            Usart5_buf[Usart5_Index]=UsartData5;//�洢��һ���¶�����
            Usart5_Index=3;
            Usart5_Status=3;
        break;
        case 3:
            if((Usart5_buf[1]^Usart5_buf[2]) == UsartData5)
            {
                Usart5_buf[Usart5_Index]=UsartData5;
                Usart5_Index=0;
                Usart5_Status=0;
                Get_Motor4_Data=Usart5_buf[1];                  //�����¶ȸ�λ
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];     //����¶�����
                temp=Get_Motor4_Data<<8;
                Get_Motor4_Data=temp+Usart5_buf[2];             //����¶�����
                Usart5_buf[0]=0;
                Usart5_buf[1]=0;
                Usart5_buf[2]=0;
                Usart5_buf[3]=0;
            }
            else
            {
                Usart5_buf[0]=0;
                Usart5_buf[1]=0;
                Usart5_buf[2]=0;
                Usart5_buf[3]=0;
                Usart5_Index=0;
                Usart5_Status=0;
                Get_Motor4_Data=0;
            }
        break;
        default:break;
    }
}

/*******************************************************************************
���ƣ�void UART6_IRQHandler(void)
���ܣ�����6���жϷ�����
��ڲ�������
���ڲ�������
˵������
��ʽ��X10Y1000E

XY����Сֵ��Ϊ10 ���ֵΪ1000
***********************************************************************************/
unsigned char UsartData6=0;
extern unsigned int Xdata,Ydata;                //���ڴ洢ҡ������
unsigned char TempBuff[11]={0};                 //���ݻ���
unsigned char Index=0;                          //��������
unsigned char Status=0;                         //�м����
//unsigned char UsartData6_2=0;
unsigned short Get_SPEAK_Data=0;
unsigned char Usart6_buf[6]={0};                                //��������
unsigned char Usart6_Index=0;                                  //��������
unsigned char Usart6_Status=0;                                 //�м����
void UART6_IRQHandler(void)                     //UART6�����жϺ���
{
    LED1Reverse();
    if(USART_GetITStatus(UART6, USART_IT_RXNE) != RESET)   //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(UART6,USART_IT_RXNE);      //����жϱ�
        UsartData6 = USART_ReceiveData(UART6);             //��ȡ����1���յ�������
//        //USART_SendData(UART6,UsartData6);                  //�����յ������ݷ���
//        //while(USART_GetFlagStatus(UART6,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
//    switch(Status)
//    {
//        case 0:
//            if(UsartData6=='X') Status=1;
//        break;
//        case 1:
//            TempBuff[Index]=UsartData6;//�洢X��ĵ�һ���ַ� Index=0;
//            Index=1;
//            Status=2;
//        break;
//        case 2:
//            TempBuff[Index]=UsartData6;//�洢X��ĵڶ����ַ� Index=1;
//            Index=2;
//            Status=3;
//        break;
//        case 3:
//            if(UsartData6=='Y') //�ж�X��ĵ�3���ַ��ǲ���Y
//            {
//                if(Index==2)
//                Xdata=(TempBuff[0]-'0')*10+TempBuff[1]-'0';//����x����ֵ
//                Index=4;
//                Status=6;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//���������������ַ����뵽���� Index=2;
//                Index=3;
//                Status=4;
//            }
//        break;
//        case 4:
//            if(UsartData6=='Y') //�ж�X��ĵ�4���ַ��ǲ���Y
//            {
//                if(Index==3)
//                Xdata=(TempBuff[0]-'0')*100+(TempBuff[1]-'0')*10+TempBuff[2]-'0';
//                Index=4;
//                Status=6;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//���������������ַ����뵽���� Index=2;
//                Index=4;
//                Status=5;
//            }
//        break;
//
//        case 5:
//            if(UsartData6=='Y') //�ж�X��ĵ�5���ַ��ǲ���Y
//            {
//                if(Index==4)
//                Xdata=(TempBuff[0]-'0')*1000+(TempBuff[1]-'0')*100+(TempBuff[2]-'0')*10+TempBuff[3]-'0';
//                Status=6;
//            }
//        break;
//        case 6:
//            TempBuff[Index]=UsartData6;//�洢Y��ĵ�һ���ַ� Index=4;
//            Index=5;
//            Status=7;
//        break;
//        case 7:
//            TempBuff[Index]=UsartData6;//�洢Y��ĵ�2���ַ� Index=5;
//            Index=6;
//            Status=8;
//        break;
//
//        case 8:
//            if(UsartData6=='E') //�ж�Y��ĵ�3���ַ��ǲ���E
//            {
//                if(Index==6)
//                Ydata=(TempBuff[4]-'0')*10+TempBuff[5]-'0';//����y����ֵ
//                Index=0;
//                Status=0;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//���������������ַ����뵽���� Index=2;
//                Index=7;
//                Status=9;
//            }
//        break;
//        case 9:
//            if(UsartData6=='E') //�ж�Y��ĵ�4���ַ��ǲ���E
//            {
//                if(Index==7)
//                Ydata=(TempBuff[4]-'0')*100+(TempBuff[5]-'0')*10+TempBuff[6]-'0';//����y����ֵ
//                Index=0;
//                Status=0;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//���������������ַ����뵽���� Index=2;
//                Index=8;
//                Status=10;
//            }
//        break;
//        case 10:
//            if(UsartData6=='E') //�ж�Y��ĵ�5���ַ��ǲ���E
//            {
//                if(Index==8)
//                Ydata=(TempBuff[4]-'0')*1000+(TempBuff[5]-'0')*100+(TempBuff[6]-'0')*10+TempBuff[7]-'0';//����y����ֵ
//                Index=0;
//                Status=0;
//            }
//        break;
//        default:break;
//        }
    for(Usart6_Status=0;Usart6_Status<6;Usart6_Status++)
        {
            Usart6_buf[Usart6_Status]=UsartData6;
        }
        if(Usart6_buf[4]==1)
        {
            MotorSpeedINIT();
        }
//    switch(Usart6_Status)//��ȡ�¶�����
//    {
//        case 0:
////            if(UsartData6_2=="AA")
////            {
//                Usart6_Status=1;
//                Usart6_buf[Usart6_Index]=UsartData6_2;//�������ź�0xa5����
//                Usart6_Index=1;
////            }
//        break;
//        case 1:
////            if(UsartData6_2=="BB")
////            {
//                Usart6_buf[Usart6_Index]=UsartData6_2;//�洢��һ���¶�����
//                Usart6_Index=2;
//                Usart6_Status=2;
////            }
//        break;
//        case 2:
//            if(UsartData6_2==1)
//            {
//                MotorSpeedINIT();
//            }
//            else if(UsartData6_2==2)
//            {
//                MotorSpeedINIT();
//            }
//            else if(UsartData6_2==3)
//           {
//                MotorSpeedHigh();
//           }
//            else if(UsartData6_2==4)
//           {
//                MotorSpeedLow();
//           }
//            else if(UsartData6_2==5)
//           {
//                MotorTurnLeft();
//           }
//            else if(UsartData6_2==6)
//           {
//                MotorTurnRight();
//           }
//            else if(UsartData6_2==7)
//           {
//                MotorSTOP();
//           }
//        break;
//        default:break;
}
/*******************************************************************************
���ƣ�void UART7_IRQHandler(void)
���ܣ�����7���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/

unsigned char Usart7Data=0;
void UART7_IRQHandler(void)          //UART7�����жϺ���
{
    if(USART_GetITStatus(UART7, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(UART7,USART_IT_RXNE);      //����жϱ�
        Usart7Data = USART_ReceiveData(UART7);             //��ȡ����1���յ�������
        //USART_SendData(UART7,Usart7Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(UART7,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
}

/*******************************************************************************
���ƣ�void UART8_IRQHandler(void)
���ܣ�����4���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/
unsigned char UsartData8=0;
unsigned short Get_Motor2_Data=0;
unsigned char Usart8_buf[4]={0};                                //��������
unsigned char Usart8_Index=0;                                  //��������
unsigned char Usart8_Status=0;                                 //�м����
void UART8_IRQHandler(void)          //UART4�����жϺ���
{

    unsigned short temp=0;
    if(USART_GetITStatus(UART8, USART_IT_RXNE) != RESET)             //�ж��ж���Դ�Ƿ�Ϊ�����ж�
    {
        USART_ClearITPendingBit(UART8,USART_IT_RXNE);      //����жϱ�
        UsartData8 = USART_ReceiveData(UART8);             //��ȡ����1���յ�������
        //USART_SendData(UART8,Usart8Data);                  //�����յ������ݷ���
        //while(USART_GetFlagStatus(UART8,USART_FLAG_TC) == RESET);//�ȴ����ݵķ������
    }
    switch(Usart8_Status)//��ȡ�¶�����
    {
        case 0:
            if(UsartData8==0xa5)
            {
                Usart8_Status=1;
                Usart8_buf[Usart8_Index]=UsartData8;//�������ź�0xa5����
                Usart8_Index=1;
            }
        break;
        case 1:
            Usart8_buf[Usart8_Index]=UsartData8;//�洢��һ���¶�����
            Usart8_Index=2;
            Usart8_Status=2;
        break;
        case 2:
            Usart8_buf[Usart8_Index]=UsartData8;//�洢��һ���¶�����
            Usart8_Index=3;
            Usart8_Status=3;
        break;
        case 3:
            if((Usart8_buf[1]^Usart8_buf[2]) == UsartData8)
            {
                Usart8_buf[Usart8_Index]=UsartData8;
                Usart8_Index=0;
                Usart8_Status=0;
                Get_Motor2_Data=Usart8_buf[1];                  //�����¶ȸ�λ
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];   //����¶�����
                temp=Get_Motor2_Data<<8;
                Get_Motor2_Data=temp+Usart8_buf[2];   //����¶�����
                Usart8_buf[0]=0;
                Usart8_buf[1]=0;
                Usart8_buf[2]=0;
                Usart8_buf[3]=0;
            }
            else
            {
                Usart8_buf[0]=0;
                Usart8_buf[1]=0;
                Usart8_buf[2]=0;
                Usart8_buf[3]=0;
                Usart8_Index=0;
                Usart8_Status=0;
                Get_Motor2_Data=0;
            }
        break;
        default:break;
    }
}




















































void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      NMI_Handler
 *
 * @brief   This function handles NMI exception.
 *
 * @return  none
 */
void NMI_Handler(void)
{
}

/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   This function handles Hard Fault exception.
 *
 * @return  none
 */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}


