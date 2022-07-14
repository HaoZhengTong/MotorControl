#ifndef __KEY_H__
#define __KEY_H__
#include "ch32v30x.h"
void Key_Init(void);								//按键的初始化
unsigned char GetKey1Status(void);//获取按键1的状态
unsigned char GetKey2Status(void);//获取按键2的状态
unsigned char GetKey3Status(void);//获取按键2的状态
unsigned char GetKey4Status(void);//获取按键2的状态
#endif
