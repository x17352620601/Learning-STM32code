#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

void delay5s(void)   //误差 -0.363636363498us
{
    unsigned char a,b,c;
    for(c=156;c>0;c--)
        for(b=254;b>0;b--)
            for(a=172;a>0;a--);
}


int main(void)
{
	
	//LED_GPIO_Config();
	LED_R_GPIO_Config();
	//LED_B_GPIO_Config();
	//LED_GPIO_Config();
	KEY2_GPIO_Config();
	while(1)
	{
			//GPIO_SetBits(LED_G_GPIO_PORT,LED_GPIO_APIN);
		
			if(KEY2CHECK(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON)
			{
			LED_R_TOGGLE; 
			}
/*		LED_SET;
		LED_G(ON);
		delay5s();
	
		
		LED_SET;
		LED_R(ON);
		delay5s();
		
		
		LED_SET;
		LED_B(ON);
		delay5s();*/
		
		
	}	//来到这里的时候系统的时钟已经被配置成72Mhz;
}
