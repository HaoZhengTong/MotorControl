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
*名    称:NVIC_Configration(void)
*功    能:中断分组函数，包含TIM1~4和USART1
*入口参数:无
*出口参数:无
*说    明:无
*调用方法:无
********************************************************************/
void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器1优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;          //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器2优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;             //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器3优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;             //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器4优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;             //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器5优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;             //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器6优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;             //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器7优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;             //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //定时器8优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_IRQn;          //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 8;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;           //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 9;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;           //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 10;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;            //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 11;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;            //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 12;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = UART6_IRQn;            //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 13;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;          //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 14;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);             //串口优先级分分组
    NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;            //指定的IRQ中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级别
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 18;          //响应优先级别
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);

}
/*******************************************************************************
名称：void USART1_IRQHandler(void)
功能：串口1的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/

unsigned char Usart1Data=0;
void USART1_IRQHandler(void)          //USART1接收中断函数
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(USART1,USART_IT_RXNE);      //清除中断标
        Usart1Data = USART_ReceiveData(USART1);             //读取串口1接收到的数据
        //USART_SendData(USART1,Usart1Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
}

/*******************************************************************************
名称：void USART2_IRQHandler(void)
功能：串口2的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/
unsigned char UsartData2=0;
extern unsigned short Motor1_Temp;                          //电机1温度数据
unsigned short Get_Motor1_Data=0;
unsigned char Usart2_buf[4]={0};                        //缓存数据
unsigned char Usart2_Index=0;                                  //数组索引
unsigned char Usart2_Status=0;                                 //中间变量

unsigned int DataTest=0;
void USART2_IRQHandler(void)          //USART2接收中断函数
{
    unsigned short temp=0;
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(USART2,USART_IT_RXNE);      //清除中断标
        UsartData2 = USART_ReceiveData(USART2);             //读取串口1接收到的数据
        //USART_SendData(USART2,Usart2Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(USART2,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
    switch(Usart2_Status)//获取温度数据
    {
        case 0:
            if(UsartData2==0xa5)
            {
                Usart2_Status=1;
                Usart2_buf[Usart2_Index]=UsartData2;//将握手信号0xa5存入
                Usart2_Index=1;

            }
        break;
        case 1:
            Usart2_buf[Usart2_Index]=UsartData2;//存储第一个温度数据
            Usart2_Index=2;
            Usart2_Status=2;
        break;
        case 2:
            Usart2_buf[Usart2_Index]=UsartData2;//存储第一个温度数据
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
                Get_Motor1_Data=Usart2_buf[1];                  //存入温度高位
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];   //获得温度数据
                temp=Get_Motor1_Data<<8;
                Get_Motor1_Data=temp+Usart2_buf[2];   //获得温度数据
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
名称：void USART3_IRQHandler(void)
功能：串口3的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/

 unsigned char Usart3Data=0;
void USART3_IRQHandler(void)          //USART3接收中断函数
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(USART3,USART_IT_RXNE);      //清除中断标
        Usart3Data = USART_ReceiveData(USART3);             //读取串口1接收到的数据
        //USART_SendData(USART3,Usart3Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
}

/*******************************************************************************
名称：void UART4_IRQHandler(void)
功能：串口4的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/
unsigned char UsartData4=0;
unsigned short Get_Motor3_Data=0;
unsigned char Usart4_buf[4]={0};                                //缓存数据
unsigned char Usart4_Index=0;                                  //数组索引
unsigned char Usart4_Status=0;                                 //中间变量
void UART4_IRQHandler(void)          //UART4接收中断函数
{
    unsigned short temp=0;
    if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(UART4,USART_IT_RXNE);      //清除中断标
        UsartData4 = USART_ReceiveData(UART4);             //读取串口1接收到的数据
        //USART_SendData(UART8,Usart8Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(UART8,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
    switch(Usart4_Status)//获取温度数据
    {
        case 0:
            if(UsartData4==0xa5)
            {
                Usart4_Status=1;
                Usart4_buf[Usart4_Index]=UsartData4;//将握手信号0xa5存入
                Usart4_Index=1;
            }
        break;
        case 1:
            Usart4_buf[Usart4_Index]=UsartData4;//存储第一个温度数据
            Usart4_Index=2;
            Usart4_Status=2;
        break;
        case 2:
            Usart4_buf[Usart4_Index]=UsartData4;//存储第一个温度数据
            Usart4_Index=3;
            Usart4_Status=3;
        break;
        case 3:
            if((Usart4_buf[1]^Usart4_buf[2]) == UsartData4)
            {
                Usart4_buf[Usart4_Index]=UsartData4;
                Usart4_Index=0;
                Usart4_Status=0;
                Get_Motor3_Data=Usart4_buf[1];                  //存入温度高位
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];   //获得温度数据
                temp=Get_Motor3_Data<<8;
                Get_Motor3_Data=temp+Usart4_buf[2];   //获得温度数据
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
名称：void UART5_IRQHandler(void)
功能：串口5的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/
unsigned char UsartData5=0;
unsigned short Get_Motor4_Data=0;
unsigned char Usart5_buf[4]={0};                                //缓存数据
unsigned char Usart5_Index=0;                                  //数组索引
unsigned char Usart5_Status=0;                                 //中间变量
void UART5_IRQHandler(void)          //UART5接收中断函数
{
    unsigned short temp=0;
    if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(UART5,USART_IT_RXNE);      //清除中断标
        UsartData5 = USART_ReceiveData(UART5);             //读取串口1接收到的数据
        //USART_SendData(UART8,Usart8Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(UART8,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
    switch(Usart5_Status)//获取温度数据
    {
        case 0:
            if(UsartData5==0xa5)
            {
                Usart5_Status=1;
                Usart5_buf[Usart5_Index]=UsartData5;//将握手信号0xa5存入
                Usart5_Index=1;
            }
        break;
        case 1:
            Usart5_buf[Usart5_Index]=UsartData5;//存储第一个温度数据
            Usart5_Index=2;
            Usart5_Status=2;
        break;
        case 2:
            Usart5_buf[Usart5_Index]=UsartData5;//存储第一个温度数据
            Usart5_Index=3;
            Usart5_Status=3;
        break;
        case 3:
            if((Usart5_buf[1]^Usart5_buf[2]) == UsartData5)
            {
                Usart5_buf[Usart5_Index]=UsartData5;
                Usart5_Index=0;
                Usart5_Status=0;
                Get_Motor4_Data=Usart5_buf[1];                  //存入温度高位
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];     //获得温度数据
                temp=Get_Motor4_Data<<8;
                Get_Motor4_Data=temp+Usart5_buf[2];             //获得温度数据
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
名称：void UART6_IRQHandler(void)
功能：串口6的中断服务函数
入口参数：无
出口参数：无
说明：无
格式：X10Y1000E

XY的最小值都为10 最大值为1000
***********************************************************************************/
unsigned char UsartData6=0;
extern unsigned int Xdata,Ydata;                //用于存储摇杆数据
unsigned char TempBuff[11]={0};                 //数据缓存
unsigned char Index=0;                          //数组索引
unsigned char Status=0;                         //中间变量
//unsigned char UsartData6_2=0;
unsigned short Get_SPEAK_Data=0;
unsigned char Usart6_buf[6]={0};                                //缓存数据
unsigned char Usart6_Index=0;                                  //数组索引
unsigned char Usart6_Status=0;                                 //中间变量
void UART6_IRQHandler(void)                     //UART6接收中断函数
{
    LED1Reverse();
    if(USART_GetITStatus(UART6, USART_IT_RXNE) != RESET)   //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(UART6,USART_IT_RXNE);      //清除中断标
        UsartData6 = USART_ReceiveData(UART6);             //读取串口1接收到的数据
//        //USART_SendData(UART6,UsartData6);                  //将接收到的数据发送
//        //while(USART_GetFlagStatus(UART6,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
//    switch(Status)
//    {
//        case 0:
//            if(UsartData6=='X') Status=1;
//        break;
//        case 1:
//            TempBuff[Index]=UsartData6;//存储X后的第一个字符 Index=0;
//            Index=1;
//            Status=2;
//        break;
//        case 2:
//            TempBuff[Index]=UsartData6;//存储X后的第二个字符 Index=1;
//            Index=2;
//            Status=3;
//        break;
//        case 3:
//            if(UsartData6=='Y') //判断X后的第3个字符是不是Y
//            {
//                if(Index==2)
//                Xdata=(TempBuff[0]-'0')*10+TempBuff[1]-'0';//计算x的数值
//                Index=4;
//                Status=6;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//如果不是则继续将字符存入到缓存 Index=2;
//                Index=3;
//                Status=4;
//            }
//        break;
//        case 4:
//            if(UsartData6=='Y') //判断X后的第4个字符是不是Y
//            {
//                if(Index==3)
//                Xdata=(TempBuff[0]-'0')*100+(TempBuff[1]-'0')*10+TempBuff[2]-'0';
//                Index=4;
//                Status=6;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//如果不是则继续将字符存入到缓存 Index=2;
//                Index=4;
//                Status=5;
//            }
//        break;
//
//        case 5:
//            if(UsartData6=='Y') //判断X后的第5个字符是不是Y
//            {
//                if(Index==4)
//                Xdata=(TempBuff[0]-'0')*1000+(TempBuff[1]-'0')*100+(TempBuff[2]-'0')*10+TempBuff[3]-'0';
//                Status=6;
//            }
//        break;
//        case 6:
//            TempBuff[Index]=UsartData6;//存储Y后的第一个字符 Index=4;
//            Index=5;
//            Status=7;
//        break;
//        case 7:
//            TempBuff[Index]=UsartData6;//存储Y后的第2个字符 Index=5;
//            Index=6;
//            Status=8;
//        break;
//
//        case 8:
//            if(UsartData6=='E') //判断Y后的第3个字符是不是E
//            {
//                if(Index==6)
//                Ydata=(TempBuff[4]-'0')*10+TempBuff[5]-'0';//计算y的数值
//                Index=0;
//                Status=0;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//如果不是则继续将字符存入到缓存 Index=2;
//                Index=7;
//                Status=9;
//            }
//        break;
//        case 9:
//            if(UsartData6=='E') //判断Y后的第4个字符是不是E
//            {
//                if(Index==7)
//                Ydata=(TempBuff[4]-'0')*100+(TempBuff[5]-'0')*10+TempBuff[6]-'0';//计算y的数值
//                Index=0;
//                Status=0;
//            }
//            else
//            {
//                TempBuff[Index]=UsartData6;//如果不是则继续将字符存入到缓存 Index=2;
//                Index=8;
//                Status=10;
//            }
//        break;
//        case 10:
//            if(UsartData6=='E') //判断Y后的第5个字符是不是E
//            {
//                if(Index==8)
//                Ydata=(TempBuff[4]-'0')*1000+(TempBuff[5]-'0')*100+(TempBuff[6]-'0')*10+TempBuff[7]-'0';//计算y的数值
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
//    switch(Usart6_Status)//获取温度数据
//    {
//        case 0:
////            if(UsartData6_2=="AA")
////            {
//                Usart6_Status=1;
//                Usart6_buf[Usart6_Index]=UsartData6_2;//将握手信号0xa5存入
//                Usart6_Index=1;
////            }
//        break;
//        case 1:
////            if(UsartData6_2=="BB")
////            {
//                Usart6_buf[Usart6_Index]=UsartData6_2;//存储第一个温度数据
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
名称：void UART7_IRQHandler(void)
功能：串口7的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/

unsigned char Usart7Data=0;
void UART7_IRQHandler(void)          //UART7接收中断函数
{
    if(USART_GetITStatus(UART7, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(UART7,USART_IT_RXNE);      //清除中断标
        Usart7Data = USART_ReceiveData(UART7);             //读取串口1接收到的数据
        //USART_SendData(UART7,Usart7Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(UART7,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
}

/*******************************************************************************
名称：void UART8_IRQHandler(void)
功能：串口4的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/
unsigned char UsartData8=0;
unsigned short Get_Motor2_Data=0;
unsigned char Usart8_buf[4]={0};                                //缓存数据
unsigned char Usart8_Index=0;                                  //数组索引
unsigned char Usart8_Status=0;                                 //中间变量
void UART8_IRQHandler(void)          //UART4接收中断函数
{

    unsigned short temp=0;
    if(USART_GetITStatus(UART8, USART_IT_RXNE) != RESET)             //判断中断来源是否为接收中断
    {
        USART_ClearITPendingBit(UART8,USART_IT_RXNE);      //清除中断标
        UsartData8 = USART_ReceiveData(UART8);             //读取串口1接收到的数据
        //USART_SendData(UART8,Usart8Data);                  //将接收到的数据发送
        //while(USART_GetFlagStatus(UART8,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }
    switch(Usart8_Status)//获取温度数据
    {
        case 0:
            if(UsartData8==0xa5)
            {
                Usart8_Status=1;
                Usart8_buf[Usart8_Index]=UsartData8;//将握手信号0xa5存入
                Usart8_Index=1;
            }
        break;
        case 1:
            Usart8_buf[Usart8_Index]=UsartData8;//存储第一个温度数据
            Usart8_Index=2;
            Usart8_Status=2;
        break;
        case 2:
            Usart8_buf[Usart8_Index]=UsartData8;//存储第一个温度数据
            Usart8_Index=3;
            Usart8_Status=3;
        break;
        case 3:
            if((Usart8_buf[1]^Usart8_buf[2]) == UsartData8)
            {
                Usart8_buf[Usart8_Index]=UsartData8;
                Usart8_Index=0;
                Usart8_Status=0;
                Get_Motor2_Data=Usart8_buf[1];                  //存入温度高位
                //Motor1_Temp=Motor1_Temp<<8+Usart2_buf[2];   //获得温度数据
                temp=Get_Motor2_Data<<8;
                Get_Motor2_Data=temp+Usart8_buf[2];   //获得温度数据
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


