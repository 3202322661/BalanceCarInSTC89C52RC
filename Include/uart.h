#ifndef __UART_H__
#define __UART_H__

#include "config.h"

void UART_Init();
void UART_SendByte(uint8_t dat);
void UART_SendString(uint8_t *str);
void UART_SendNumber(int32_t num);

#endif