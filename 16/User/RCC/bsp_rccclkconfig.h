#ifndef __BSP_RCCCLKCONFIG_H
#define __BSP_RCCCLKCONFIG_H

#include "stm32f10x.h"

void HSE_SetSysCLK(uint32_t RCC_PLLMul_x);
void MCO_GPIO_Config(void);
void HSI_SetSysCLK(uint32_t RCC_PLLMul_x);
#endif
