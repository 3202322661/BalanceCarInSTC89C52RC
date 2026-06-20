#include "uart.h"

void UART_Init()
{
	SCON = 0x50;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	
	TH1 = 0xFD;
	TL1 = 0xFD;
	
	PCON &= 0x7F;
	TR1 = 1;
	ES = 0;
	TI = 0;
}

void UART_SendByte(uint8_t dat)
{
	SBUF = dat;
	while(!TI);
	TI = 0;
}

void UART_SendString(uint8_t *str)
{
	while (*str)
	{
		UART_SendByte(*str++);
	}
}

void UART_SendNumber(int32_t num)
{
	uint8_t buf[12];
	uint8_t i = 0;
	uint8_t j;
	uint8_t is_neg = 0;
	
	if (num == 0)
	{
		UART_SendByte('0');
		return;
	}
	
	if (num < 0)
	{
		is_neg = 1;
		num = -num;
	}
	
	while (num > 0)
	{
		buf[i++] = (uint8_t) (num % 10) + '0';
		num /= 10;
	}
	
	if (is_neg)
	{
		buf[i++] = '-';
	}
	
	for (j = i; j > 0; j--)
	{
		UART_SendByte(buf[j - 1]);
	}
}