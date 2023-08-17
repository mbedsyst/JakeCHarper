#ifndef __UART_H__
#define __UART_H__

void UART_Init(void);
void UART_Tx(char data);
void UART_Tx_String(char *str);
char UART_Rx(void);


#endif
