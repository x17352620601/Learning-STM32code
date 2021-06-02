#include "stm32f10x.h"
#include "bsp_led.h"

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
	while(1)
	{

		LED_G(ON);
		delay5s();
		LED_G(OFF);
		
		LED_R(ON);
		delay5s();

		LED_R(OFF);
		
		LED_B(ON);
		delay5s();
		LED_B(OFF);		
	}	//来到这里的时候系统的时钟已经被配置成72Mhz;
}
