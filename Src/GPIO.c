#include "stm32f4xx.h"
#include "GPIO.h"

void GPIO_Init()
{
	RCC -> AHB1ENR |= 1<<0;
	while(!((RCC -> AHB1ENR)&(1<<0)));

	/* Writing to MODER Register */
	GPIOA -> MODER &= ~(1U<<11);
	GPIOA -> MODER |=  (1U<<10);
}
void GPIO_Toggle()
{
	GPIOA->ODR ^= (1U<<5);
}
