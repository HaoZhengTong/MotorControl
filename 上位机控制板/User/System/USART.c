#include "USART.h"
/********************************************************************
*名    称:void USART1_Configuration(void)
*功    能:USART1配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PA9  RX:PA10

*调用方法:无
********************************************************************/
extern void USART1_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;                         //配置PA9
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                         //配置PA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_Init(GPIOA, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                            //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(USART1, ENABLE);                                              //串口外设使能
    USART_ClearFlag(USART1,USART_FLAG_TC);                                //清除发送使能标志位
}
/********************************************************************
*名    称:void USART2_Configuration(void)
*功    能:USART2配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
			  1端口重映射
*出口参数:无
*说    明:	未映射TX:PA2  RX:PA3

*调用方法:无
********************************************************************/
extern void USART2_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;							//配置PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 				//设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 				//配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure); 							//初始化GPIO为高速推免输出模式
			
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;						    //配置PA3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 			//设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 				//配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure); 							//初始化GPIO为高速推免输出模式

	USART_InitStructure.USART_BaudRate = 115200; 								//波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; 			//数据位8
	USART_InitStructure.USART_StopBits = USART_StopBits_1; 					//停止位1
	USART_InitStructure.USART_Parity = USART_Parity_No;						//无校验
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;  										//无硬件流控制
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;			//使能接收和发送
	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE,ENABLE);							//接收中断标志使能
	USART_Cmd(USART2, ENABLE);												//串口外设使能
	USART_ClearFlag(USART2,USART_FLAG_TC);								//清除发送使能标志位
}
/********************************************************************
*名    称:void USART3_Configuration(void)
*功    能:USART3配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PB10  RX:PB11

*调用方法:无
********************************************************************/
extern void USART3_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                         //配置PB10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;                         //配置PB11
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                              //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(USART3, &USART_InitStructure);
    USART_ITConfig(USART3, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(USART3, ENABLE);                                              //串口外设使能
    USART_ClearFlag(USART3,USART_FLAG_TC);                                //清除发送使能标志位
}
/********************************************************************
*名    称:void USART4_Configuration(void)
*功    能:USART4配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PC10  RX:PC11

*调用方法:无
********************************************************************/
extern void USART4_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                         //配置PC10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;                         //配置PC11
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                              //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(UART4, &USART_InitStructure);
    USART_ITConfig(UART4, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(UART4, ENABLE);                                              //串口外设使能
    USART_ClearFlag(UART4,USART_FLAG_TC);                                //清除发送使能标志位
}
/********************************************************************
*名    称:void USART5_Configuration(void)
*功    能:USART5配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PC12  RX:PD2

*调用方法:无
********************************************************************/
extern void USART5_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;                         //配置PC12
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;                         //配置PD2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOD, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                              //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(UART5, &USART_InitStructure);
    USART_ITConfig(UART5, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(UART5, ENABLE);                                              //串口外设使能
    USART_ClearFlag(UART6,USART_FLAG_TC);                                //清除发送使能标志位
}
/********************************************************************
*名    称:void USART6_Configuration(void)
*功    能:USART6配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PC0  RX:PC1

*调用方法:无
********************************************************************/
extern void USART6_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART6, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;                         //配置PC0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;                         //配置PC1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                              //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(UART6, &USART_InitStructure);
    USART_ITConfig(UART6, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(UART6, ENABLE);                                              //串口外设使能
    USART_ClearFlag(UART6,USART_FLAG_TC);                                //清除发送使能标志位
}
/********************************************************************
*名    称:void USART7_Configuration(void)
*功    能:USART7配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PC2  RX:PC3

*调用方法:无
********************************************************************/
extern void USART7_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;                         //配置PC2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;                         //配置PC3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                              //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(UART7, &USART_InitStructure);
    USART_ITConfig(UART7, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(UART7, ENABLE);                                              //串口外设使能
    USART_ClearFlag(UART7,USART_FLAG_TC);                                //清除发送使能标志位
}
/********************************************************************
*名    称:void USART8_Configuration(void)
*功    能:USART8配置函数 对应的IO初始化
*入口参数:State：0端口未重映射
              1端口重映射
*出口参数:无
*说    明:    未映射TX:PC4  RX:PC5

*调用方法:无
********************************************************************/
extern void USART8_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART8, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;                         //配置PC4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                 //设置GPIO的模式为复用推挽模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;                         //配置PC5
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //设置GPIO的模式为浮空输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;               //配置 I/O 口的速度为：50MHz，还可选：GPIO_Speed_2MHz，GPIO_Speed_10MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);                          //初始化GPIO为高速推免输出模式

    USART_InitStructure.USART_BaudRate = 115200;                              //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;             //数据位8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                  //停止位1
    USART_InitStructure.USART_Parity = USART_Parity_No;                     //无校验
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;                                         //无硬件流控制
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;         //使能接收和发送
    USART_Init(UART8, &USART_InitStructure);
    USART_ITConfig(UART8, USART_IT_RXNE,ENABLE);                         //接收中断标志使能
    USART_Cmd(UART8, ENABLE);                                              //串口外设使能
    USART_ClearFlag(UART8,USART_FLAG_TC);                                //清除发送使能标志位
}

void USARTx_SendLenByte(USART_TypeDef *USARTx,unsigned char *buf,unsigned char len)
{
    unsigned char i;
    for(i=0;i<len;i++)
    {
        USART_SendData(USARTx, *(buf+i));
        while(USART_GetFlagStatus(USARTx,USART_FLAG_TC) == RESET);//等待数据的发送完成
    }

}

void USARTx_SendByte(USART_TypeDef *USARTx,unsigned char buf)
{
    USART_SendData(USARTx, buf);
    while(USART_GetFlagStatus(USARTx,USART_FLAG_TC) == RESET);//等待数据的发送完成
}














