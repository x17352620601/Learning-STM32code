#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h"

//void delay5s(void)   //��� -0.363636363498us
//{
//    unsigned char a,b,c;
//    for(c=156;c>0;c--)
//        for(b=254;b>0;b--)
//            for(a=172;a>0;a--);
//}


int main(void)
{
	//���������ʱ��ϵͳ��ʱ���Ѿ������ó�72Mhz;
	LED_GPIO_Config();
	
	EXTI_Key_Config();
	while(1)
	{
		
	}
	
}
