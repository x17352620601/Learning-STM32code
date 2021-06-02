#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

#define addrb      (GPIOB_BASE+0X0C)
#define FBout(n) *(unsigned int*)((addrb & 0xF0000000)+0x02000000+((addrb &0x00FFFFFF)<<5)+(n<<2))
	
#define addrc      (GPIOC_BASE+0X08)
#define FCin(n)  *(unsigned int*)((addrc & 0xF0000000)+0x02000000+((addrc &0x00FFFFFF)<<5)+(n<<2))
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x02000000+((addr &0x00FFFFFF)<<5)+(bitnum<<2))

void delay5s(void)   //误差 -0.363636363498us
{
    unsigned char a,b,c;
    for(c=156;c>0;c--)
        for(b=254;b>0;b--)
            for(a=172;a>0;a--);
}


int main(void)
{
	
		LED_GPIO_Config();
	//LED_R_GPIO_Config();
	//LED_B_GPIO_Config();
	//LED_GPIO_Config();
	  KEY2_GPIO_Config();
	#if 0
	while(1)
	{
			//GPIO_SetBits(LED_G_GPIO_PORT,LED_GPIO_APIN);
		
//			if(KEY2CHECK(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON)
//			{
//			LED_R_TOGGLE; 
//			}
		//LED_SET;
		//LED_G(ON);
		FBout(5)=1;
		delay5s();
		FBout(5)=0;
		//LED_G(OFF);
		delay5s();
	
/*		
		LED_SET;
		LED_R(ON);
		delay5s();
		
		
		LED_SET;
		LED_B(ON);
		delay5s();*/
		
		
	}	//来到这里的时候系统的时钟已经被配置成72Mhz;
#else
	while(1)
	{
		if(FCin(13) == KEY_ON)
		{
			while(FCin(13) == KEY_ON);
			LED_G_TOGGLE;
		}
	}
	#endif
}
