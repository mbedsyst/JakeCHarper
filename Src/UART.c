#include "UART.h"
#include "stm32f4xx.h"

void UART_Init(void)
{
  /* Initializing UART Peripheral */
  RCC->AHB1ENR  |=  (1<<0);
  RCC->APB1ENR  |=  (1<<17);
  USART2->BRR    =  (0x008B);
  USART2->CR1   |=  (1<<13)  | (1<<3) | (1<<2);

  GPIOA->MODER  &= ~((1U<<4) | (1<<6));
  GPIOA->MODER  |=  (1<<5)   | (1<<7);
  GPIOA->AFR[0] |=  (0x07<<8) | (0x07<<12);
}

void UART_Tx(char data)
{
  /* Function to transmit character via UART */
  while (!(USART2->SR & (1<<7)));
  USART2->DR = data;
}

void UART_Tx_String(char *str)
{
	while(*str)
	{
		UART_Tx(*str++);
	}
}
char UART_Rx(void)
{
	while(!(USART2->SR & (1<<5)));
	return USART2->DR;
}
