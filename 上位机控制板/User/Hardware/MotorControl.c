#include "MotorControl.h"
#include "System/USART.h"
/*
 * ���1��Ӧ����2
 * ���2��Ӧ����8
 *
 * ���3��Ӧ����4
 * ���4��Ӧ����5
 *
 * */
unsigned char COM_FULL_SPEED[8]={0xa5,0x00,0x64,0x00,0x00,0x00,0x00,0x64};
unsigned char COM_FULL_SPEED_HALF[8]={0xa5,0x00,0x32,0x00,0x00,0x00,0x00,0x32};
unsigned char COM_LEFT_SPEED[8]={0xa5,0x0b,0x32,0x00,0x0a,0x00,0x00,0x00};  //����ת��
unsigned char COM_RIGHT_SPEED[8]={0xa5,0x0b,0x00,0x00,0x0a,0x00,0x00,0x00}; //����ת��
unsigned char COM_ANGLE_GET[8]={0xa5,0x0b,0x01,0x00,0x0a,0x00,0x00,0x00};   //�Ƕ�
unsigned char COM_SPEED_GET[8]={0xa5,0x0b,0x02,0x00,0x0a,0x00,0x00,0x00};   //�ٶ�
unsigned char COM_VOL_GET[8]={0xa5,0x0b,0x03,0x00,0x0a,0x00,0x00,0x00};     //��Դ��ѹ
unsigned char COM_ELE_GET[8]={0xa5,0x17,0x04,0x00,0x0a,0x00,0x00,0x00};     //�������
unsigned char COM_TEM_GET[8]={0xa5,0x17,0x05,0x00,0x0a,0x00,0x00,0x00};     //�¶�
unsigned char COM_POWER_GET[8]={0xa5,0x17,0x07,0x00,0x0a,0x00,0x00,0x00};   //���ʰٷֱ�
unsigned char COM_INFOR_GET[8]={0xa5,0x17,0x00,0x00,0x0a,0x00,0x00,0x00};   //�����Ϣѯ��ģ��

void MotorInit(void)
{
    USART2_Configuration();
    USART4_Configuration();
    USART5_Configuration();
    USART8_Configuration();
}
void MotorFullSpeed(void)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        USARTx_SendByte(USART2,COM_FULL_SPEED[i]);
        USARTx_SendByte(UART4,COM_FULL_SPEED[i]);
        USARTx_SendByte(UART5,COM_FULL_SPEED[i]);
        USARTx_SendByte(UART8,COM_FULL_SPEED[i]);
        Delayxms(10);
    }
}
void MotorFullSpeedHalf(void)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        USARTx_SendByte(USART2,COM_FULL_SPEED_HALF[i]);
        USARTx_SendByte(UART4,COM_FULL_SPEED_HALF[i]);
        USARTx_SendByte(UART5,COM_FULL_SPEED_HALF[i]);
        USARTx_SendByte(UART8,COM_FULL_SPEED_HALF[i]);
        Delayxms(10);
    }
}
void MotorSpeedINIT(void)
{
    unsigned char i;
    COM_LEFT_SPEED[7]=COM_LEFT_SPEED[6]^COM_LEFT_SPEED[5]^COM_LEFT_SPEED[4]^COM_LEFT_SPEED[3]^COM_LEFT_SPEED[2]^COM_LEFT_SPEED[1];
    COM_RIGHT_SPEED[2]=~COM_LEFT_SPEED[2]+1;
    COM_RIGHT_SPEED[7]=COM_RIGHT_SPEED[6]^COM_RIGHT_SPEED[5]^COM_RIGHT_SPEED[4]^COM_RIGHT_SPEED[3]^COM_RIGHT_SPEED[2]^COM_RIGHT_SPEED[1];
    for(i=0;i<8;i++)
    {
        USARTx_SendByte(USART2,COM_LEFT_SPEED[i]);
        USARTx_SendByte(UART4,COM_RIGHT_SPEED[i]);
        USARTx_SendByte(UART5,COM_RIGHT_SPEED[i]);
        USARTx_SendByte(UART8,COM_LEFT_SPEED[i]);
        Delayxms(10);
    }
}
void MotorSpeedSET(void)
{
    unsigned char i;
    COM_LEFT_SPEED[7]=COM_LEFT_SPEED[6]^COM_LEFT_SPEED[5]^COM_LEFT_SPEED[4]^COM_LEFT_SPEED[3]^COM_LEFT_SPEED[2]^COM_LEFT_SPEED[1];
    COM_RIGHT_SPEED[7]=COM_RIGHT_SPEED[6]^COM_RIGHT_SPEED[5]^COM_RIGHT_SPEED[4]^COM_RIGHT_SPEED[3]^COM_RIGHT_SPEED[2]^COM_RIGHT_SPEED[1];
    for(i=0;i<8;i++)
    {
        USARTx_SendByte(USART2,COM_LEFT_SPEED[i]);
        USARTx_SendByte(UART4,COM_RIGHT_SPEED[i]);
        USARTx_SendByte(UART5,COM_RIGHT_SPEED[i]);
        USARTx_SendByte(UART8,COM_LEFT_SPEED[i]);
        Delayxms(10);

    }
}
void MotorSpeedHigh(void)
{
    COM_LEFT_SPEED[2]+=10;
    COM_RIGHT_SPEED[2]=~COM_LEFT_SPEED[2]+1;
    MotorSpeedSET();
//    COM_LEFT_SPEED[2]-=10;
//    COM_RIGHT_SPEED[2]=~COM_RIGHT_SPEED[2]+1;
}
void MotorSpeedLow(void)
{
    COM_LEFT_SPEED[2]-=10;
    COM_RIGHT_SPEED[2]=~COM_LEFT_SPEED[2]+1;
    MotorSpeedSET();
//    COM_LEFT_SPEED[2]+=10;
//    COM_RIGHT_SPEED[2]=~COM_RIGHT_SPEED[2]+1;
}
void MotorTurnLeft(void)
{
    COM_RIGHT_SPEED[2]=COM_LEFT_SPEED[2]+10;
    COM_RIGHT_SPEED[2]=~COM_RIGHT_SPEED[2]+1;
    COM_LEFT_SPEED[2]-=10;
    MotorSpeedSET();
    COM_LEFT_SPEED[2]+=10;
    COM_RIGHT_SPEED[2]=~COM_RIGHT_SPEED[2]+1;
}
void MotorTurnRight(void)
{
    COM_RIGHT_SPEED[2]=COM_LEFT_SPEED[2]-10;
    COM_RIGHT_SPEED[2]=~COM_RIGHT_SPEED[2]+1;
    COM_LEFT_SPEED[2]+=10;
    MotorSpeedSET();
    COM_LEFT_SPEED[2]-=10;
    COM_RIGHT_SPEED[2]=~COM_RIGHT_SPEED[2]+1;
}
void MotorSTOP(void)
{
    unsigned char i;
    COM_RIGHT_SPEED[2]=0x01;
    COM_LEFT_SPEED[2]=0x01;
    COM_LEFT_SPEED[7]=COM_LEFT_SPEED[6]^COM_LEFT_SPEED[5]^COM_LEFT_SPEED[4]^COM_LEFT_SPEED[3]^COM_LEFT_SPEED[2]^COM_LEFT_SPEED[1];
    COM_RIGHT_SPEED[7]=COM_RIGHT_SPEED[6]^COM_RIGHT_SPEED[5]^COM_RIGHT_SPEED[4]^COM_RIGHT_SPEED[3]^COM_RIGHT_SPEED[2]^COM_RIGHT_SPEED[1];
    for(i=0;i<8;i++)
    {
        USARTx_SendByte(USART2,COM_RIGHT_SPEED[i]);
        USARTx_SendByte(UART4,COM_LEFT_SPEED[i]);
        USARTx_SendByte(UART5,COM_LEFT_SPEED[i]);
        USARTx_SendByte(UART8,COM_RIGHT_SPEED[i]);
        Delayxms(10);
    }
}
void MotorAngleGet(void)
{
    unsigned char i;
    COM_INFOR_GET[2]=0x01;
    COM_INFOR_GET[7]=COM_INFOR_GET[6]^COM_INFOR_GET[5]^COM_INFOR_GET[4]^COM_INFOR_GET[3]^COM_INFOR_GET[2]^COM_INFOR_GET[1];
    for(i=0;i<8;i++)
    {
        if(1<7)
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
            Delayxms(10);
        }
        else
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            //���շ�����Ϣ
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);

            USARTx_SendByte(UART5,COM_INFOR_GET[i]);

            USARTx_SendByte(UART8,COM_INFOR_GET[i]);

        }
    }
}
void MotorSpeedGet(void)
{
    unsigned char i;
    COM_INFOR_GET[2]=0x02;
    COM_INFOR_GET[7]=COM_INFOR_GET[6]^COM_INFOR_GET[5]^COM_INFOR_GET[4]^COM_INFOR_GET[3]^COM_INFOR_GET[2]^COM_INFOR_GET[1];
    for(i=0;i<8;i++)
    {
        if(1<7)
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
            Delayxms(10);
        }
        else
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            //���շ�����Ϣ
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);

            USARTx_SendByte(UART5,COM_INFOR_GET[i]);

            USARTx_SendByte(UART8,COM_INFOR_GET[i]);

        }
    }
}
void MotorVoltageGet(void)
{
    unsigned char i;
    COM_INFOR_GET[2]=0x03;
    COM_INFOR_GET[7]=COM_INFOR_GET[6]^COM_INFOR_GET[5]^COM_INFOR_GET[4]^COM_INFOR_GET[3]^COM_INFOR_GET[2]^COM_INFOR_GET[1];
    for(i=0;i<8;i++)
    {
        if(1<7)
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
            Delayxms(10);
        }
        else
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            //���շ�����Ϣ
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);

            USARTx_SendByte(UART5,COM_INFOR_GET[i]);

            USARTx_SendByte(UART8,COM_INFOR_GET[i]);

        }
    }
}
void MotorCurrentGet(void)
{
    unsigned char i;
    COM_INFOR_GET[2]=0x04;
    COM_INFOR_GET[7]=COM_INFOR_GET[6]^COM_INFOR_GET[5]^COM_INFOR_GET[4]^COM_INFOR_GET[3]^COM_INFOR_GET[2]^COM_INFOR_GET[1];
    for(i=0;i<8;i++)
    {
//        if(1<7)
//        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
            Delayxms(10);
//        }
//        else
//        {
//            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
//            //���շ�����Ϣ
//            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
//
//            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
//
//            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
//
//        }
    }
}
void MotorTempGet(void)
{
    unsigned char i;
    COM_INFOR_GET[2]=0x05;
    COM_INFOR_GET[7]=COM_INFOR_GET[6]^COM_INFOR_GET[5]^COM_INFOR_GET[4]^COM_INFOR_GET[3]^COM_INFOR_GET[2]^COM_INFOR_GET[1];
    for(i=0;i<8;i++)
    {
        //if(1<7)
        //{
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
            Delayxms(10);
        //}
//        else
//        {
//            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
//            //���շ�����Ϣ
//            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
//
//            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
//
//            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
//
//        }
    }
}
void MotorPowerGet(void)
{
    unsigned char i;
    COM_INFOR_GET[2]=0x07;
    COM_INFOR_GET[7]=COM_INFOR_GET[6]^COM_INFOR_GET[5]^COM_INFOR_GET[4]^COM_INFOR_GET[3]^COM_INFOR_GET[2]^COM_INFOR_GET[1];
    for(i=0;i<8;i++)
    {
        if(1<7)
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);
            USARTx_SendByte(UART5,COM_INFOR_GET[i]);
            USARTx_SendByte(UART8,COM_INFOR_GET[i]);
            Delayxms(10);
        }
        else
        {
            USARTx_SendByte(USART2,COM_INFOR_GET[i]);
            //���շ�����Ϣ
            USARTx_SendByte(UART4,COM_INFOR_GET[i]);

            USARTx_SendByte(UART5,COM_INFOR_GET[i]);

            USARTx_SendByte(UART8,COM_INFOR_GET[i]);

        }
    }
}
void MotorInformationGet(void)
{
    MotorAngleGet();
    MotorSpeedGet();
    MotorVoltageGet();
    MotorCurrentGet();
    MotorTempGet();
    MotorPowerGet();
}
