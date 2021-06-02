#include "bsp_rccclkconfig.h"

void HSE_SetSysCLK(uint32_t RCC_PLLMul_x)
{
	ErrorStatus HSEStatus; 
	
	//��RCC�Ĵ�����λ�ɸ�λֵ
	RCC_DeInit();
	//ʹ��HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus ==SUCCESS)
	{
		//ʹ��Ԥȡֵ
	 	 FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		 FLASH_SetLatency(FLASH_Latency_2);
		
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//����PLLCLK=HSE*RCC_PLLMul_x
		 RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		//ʹ��PLL
		 RCC_PLLCmd(ENABLE);
		//�ȴ�PLLʱ���ȶ�
		
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
			
		}
		
		//ѡ��ϵͳʱ��
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		 while( RCC_GetSYSCLKSource() != 0x08)
		 {
			 
		 }
	}
	else
	{
		//���SHE����ʧ�ܣ��û�������������Ӵ������Ĵ���
	}
}

void HSI_SetSysCLK(uint32_t RCC_PLLMul_x)
{
	__IO uint32_t HSIStatus; 
	
	//��RCC�Ĵ�����λ�ɸ�λֵ
	RCC_DeInit();
	//ʹ��HSI
	RCC_HSICmd(ENABLE);
	
	HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	
	if(HSIStatus ==SUCCESS)
	{
		//ʹ��Ԥȡֵ
	 	 FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		 FLASH_SetLatency(FLASH_Latency_2);
		
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//����PLLCLK=HSE*RCC_PLLMul_x
		 RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		//ʹ��PLL
		 RCC_PLLCmd(ENABLE);
		//�ȴ�PLLʱ���ȶ�
		
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
			
		}
		
		//ѡ��ϵͳʱ��
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		 while( RCC_GetSYSCLKSource() != 0x08)
		 {
			 
		 }
	}
	else
	{
		//���HSI����ʧ�ܣ��û�������������Ӵ������Ĵ���
	}
}
void MCO_GPIO_Config(void)
{
		  GPIO_InitTypeDef  GPIOG_InitStruct;

	//�Ĵ���ʱ�ӿ���
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//GPIO�ĳ�ʼ��
	GPIOG_InitStruct.GPIO_Pin   = GPIO_Pin_8 ;
	GPIOG_InitStruct.GPIO_Mode 	=	GPIO_Mode_Out_PP;
	GPIOG_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIOG_InitStruct);
}
