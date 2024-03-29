#include "bsp_rccclkconfig.h"

void HSE_SetSysCLK(uint32_t RCC_PLLMul_x)
{
	ErrorStatus HSEStatus; 
	
	//把RCC寄存器复位成复位值
	RCC_DeInit();
	//使能HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus ==SUCCESS)
	{
		//使能预取值
	 	 FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		 FLASH_SetLatency(FLASH_Latency_2);
		
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//配置PLLCLK=HSE*RCC_PLLMul_x
		 RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		//使能PLL
		 RCC_PLLCmd(ENABLE);
		//等待PLL时钟稳定
		
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
			
		}
		
		//选择系统时钟
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		 while( RCC_GetSYSCLKSource() != 0x08)
		 {
			 
		 }
	}
	else
	{
		//如果SHE启动失败，用户可以在这里添加处理错误的代码
	}
}

void HSI_SetSysCLK(uint32_t RCC_PLLMul_x)
{
	__IO uint32_t HSIStatus; 
	
	//把RCC寄存器复位成复位值
	RCC_DeInit();
	//使能HSI
	RCC_HSICmd(ENABLE);
	
	HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	
	if(HSIStatus ==SUCCESS)
	{
		//使能预取值
	 	 FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		 FLASH_SetLatency(FLASH_Latency_2);
		
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//配置PLLCLK=HSE*RCC_PLLMul_x
		 RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		//使能PLL
		 RCC_PLLCmd(ENABLE);
		//等待PLL时钟稳定
		
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
			
		}
		
		//选择系统时钟
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		 while( RCC_GetSYSCLKSource() != 0x08)
		 {
			 
		 }
	}
	else
	{
		//如果HSI启动失败，用户可以在这里添加处理错误的代码
	}
}
void MCO_GPIO_Config(void)
{
		  GPIO_InitTypeDef  GPIOG_InitStruct;

	//寄存器时钟控制
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//GPIO的初始化
	GPIOG_InitStruct.GPIO_Pin   = GPIO_Pin_8 ;
	GPIOG_InitStruct.GPIO_Mode 	=	GPIO_Mode_Out_PP;
	GPIOG_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIOG_InitStruct);
}
