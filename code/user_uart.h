#ifndef _USER_UART_H_
#define _USER_UART_H_

#include "cms32f033x.h"

void UART_Config(void);
void USART0_send_byte(uint8_t Data);		//����һ���ֽ�

extern u8	F_transmit_0;							//UART0���ͱ�־λ


#endif
