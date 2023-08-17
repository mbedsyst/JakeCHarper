#include "stm32f4xx.h"
#include "Delay.h"

void delay_us(uint32_t us)                              /* Micro-second Delay Function*/
{
	uint32_t i;

	SysTick->CTRL |= (1<<0) | (1<<2) ;
	SysTick->LOAD  = (SystemCoreClock/1000000) - 1;
	for(i=0; i<us; i++)
	{
    while(!(SysTick->CTRL & (1<<16)));
	}
	SysTick->CTRL &=~(1U<<0);
}
void delay_ms(uint32_t ms)                              /* Milli-second Delay Function*/
{
	uint32_t i;

	SysTick->CTRL |= (1<<0) | (1<<2) ;
	SysTick->LOAD  = (SystemCoreClock/1000) - 1;
	for(i=0; i<ms; i++)
	{
    while(!(SysTick->CTRL & (1<<16)));
	}
	SysTick->CTRL &=~(1U<<0);
}

