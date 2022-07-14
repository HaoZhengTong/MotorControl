#ifndef __USART_H__
#define __USART_H__
#include "ch32v30x.h"
#define NoRemap 0
#define Remap 	1
void USART1_Configuration(void);
void USART2_Configuration(void);
void USART3_Configuration(void);
void USART4_Configuration(void);
void USART5_Configuration(void);
void USART6_Configuration(void);
void USART7_Configuration(void);
void USART8_Configuration(void);
void USARTx_SendLenByte(USART_TypeDef *USARTx,unsigned char *buf,unsigned char len);
void USARTx_SendByte(USART_TypeDef *USARTx,unsigned char buf);
#endif
