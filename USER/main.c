#include <stdio.h>
#include "stm32f10x.h"
#include "delay.h"
#include "AD9854.h"

 


int main(void) 
{
	   GPIO_InitTypeDef GPIO_InitStructure;
 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		AD9854_Init();
		AD9854_SetSine_double(10000,4095);
 
    while(1)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_1);
        delay_ms(1000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_1);
        delay_ms(1000);
    }
}

