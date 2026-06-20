#include "uart.h"

int main() 
{
	UART_Init();
	
	UART_SendString("Hello World.");
	UART_SendNumber(123);
	UART_SendNumber(-456);
	return 0;
}