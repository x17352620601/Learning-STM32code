#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	  GPIO_InitTypeDef  GPIOG_InitStruct;

	//寄存器时钟控制
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	//GPIO的初始化
	GPIOG_InitStruct.GPIO_Pin   = LED_G_GPIO_PIN ;
	GPIOG_InitStruct.GPIO_Mode 	=	GPIO_Mode_Out_PP;
	GPIOG_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT, &GPIOG_InitStruct);
	
}
void LED_R_GPIO_Config(void)
{
		GPIO_InitTypeDef  GPIOR_InitStruct;
		RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
		GPIOR_InitStruct.GPIO_Pin   = LED_R_GPIO_PIN ;
		GPIOR_InitStruct.GPIO_Mode 	=	GPIO_Mode_Out_PP;
		GPIOR_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
		GPIO_Init(LED_G_GPIO_PORT, &GPIOR_InitStruct);
}
void LED_B_GPIO_Config(void)
{
		GPIO_InitTypeDef  GPIOB_InitStruct;
	
		RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	
		GPIOB_InitStruct.GPIO_Pin   = LED_B_GPIO_PIN ;
		GPIOB_InitStruct.GPIO_Mode 	=	GPIO_Mode_Out_PP;
		GPIOB_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
	
		GPIO_Init(LED_G_GPIO_PORT, &GPIOB_InitStruct);
}
