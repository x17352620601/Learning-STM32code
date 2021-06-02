#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIOG_InitStruct;

	//�Ĵ���ʱ�ӿ���
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);
	//GPIO�ĳ�ʼ��	
	GPIOG_InitStruct.GPIO_Pin   = LED_G_GPIO_PIN ;
	GPIOG_InitStruct.GPIO_Mode 	=	GPIO_Mode_Out_PP;
	GPIOG_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT, &GPIOG_InitStruct);
	
}
