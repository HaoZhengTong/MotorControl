#include "Key.h"
#include "debug.h"
/*
Key1=PB14;
Key2=PB13;
Key3=PB15;
Key4=PB12;

*/
#define KEY1_PIN        GPIO_Pin_14
#define KEY1_GPIO       GPIOB
#define KEY1_GPIO_CLK	RCC_APB2Periph_GPIOB

#define KEY2_PIN        GPIO_Pin_13
#define KEY2_GPIO       GPIOB
#define KEY2_GPIO_CLK	RCC_APB2Periph_GPIOB

#define KEY3_PIN        GPIO_Pin_15
#define KEY3_GPIO       GPIOB
#define KEY3_GPIO_CLK   RCC_APB2Periph_GPIOB

#define KEY4_PIN        GPIO_Pin_12
#define KEY4_GPIO       GPIOB
#define KEY4_GPIO_CLK   RCC_APB2Periph_GPIOB

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;						//定义GPIO结构体
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);				//开启GPIO模块的时钟
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);
    RCC_APB2PeriphClockCmd(KEY3_GPIO_CLK,ENABLE);                //开启GPIO模块的时钟
    RCC_APB2PeriphClockCmd(KEY4_GPIO_CLK,ENABLE);

	GPIO_InitStructure.GPIO_Pin = KEY1_PIN; 					// 配置使用的GPIO管脚号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 				// 设置GPIO的模式为输入模式
	GPIO_Init(KEY1_GPIO, &GPIO_InitStructure); 					// 初始化GPIO为上拉输入模式

	GPIO_InitStructure.GPIO_Pin = KEY2_PIN; 					// 配置使用的GPIO管脚号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 				// 设置GPIO的模式为输入模式
	GPIO_Init(KEY2_GPIO, &GPIO_InitStructure); 					// 初始化GPIO为上拉输入模式
	
    GPIO_InitStructure.GPIO_Pin = KEY3_PIN;                     // 配置使用的GPIO管脚号
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // 设置GPIO的模式为输入模式
    GPIO_Init(KEY3_GPIO, &GPIO_InitStructure);                  // 初始化GPIO为上拉输入模式

    GPIO_InitStructure.GPIO_Pin = KEY4_PIN;                     // 配置使用的GPIO管脚号
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // 设置GPIO的模式为输入模式
    GPIO_Init(KEY4_GPIO, &GPIO_InitStructure);                  // 初始化GPIO为上拉输入模式

			
}
unsigned char GetKey1Status(void)								//获取按键1的状态
{
		return GPIO_ReadInputDataBit(KEY1_GPIO, KEY1_PIN);
}
unsigned char GetKey2Status(void)								//获取按键2的状态
{
		return GPIO_ReadInputDataBit(KEY2_GPIO, KEY2_PIN);
}
unsigned char GetKey3Status(void)                               //获取按键2的状态
{
        return GPIO_ReadInputDataBit(KEY3_GPIO, KEY3_PIN);
}
unsigned char GetKey4Status(void)                               //获取按键2的状态
{
        return GPIO_ReadInputDataBit(KEY4_GPIO, KEY4_PIN);
}

