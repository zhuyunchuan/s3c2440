#include "LPC210x.h"
#include "type.h"
#include "config.h"
#include "uart.h"
#include <stdio.h>	   
	  
#define UART_BPS 9600

int uart_init()
{
	int Fvid = 0;

	PINSEL0 |= 0x00050005;					//set p0.9/0.8/0.0/0.1 as uart
	U0LCR = 0x83;							//set 1 stop bit,8
	U1LCR = 0x83;
	
	Fdiv = (Fpclk / 16)/ UART_BPS;           // …Ë÷√≤®Ãÿ¬ 
    U0DLM = Fdiv / 256;							
    U0DLL = Fdiv % 256;
	U1DLM = Fdiv / 256;							
    U1DLL = Fdiv % 256;
		
    U0LCR = 0x03;
   	U1LCR = 0x03;
	return 0;
}

static char uart_getchar(void)
{
	char rev_data;

	while( 0 == (U0LSR & 0x01))
	{
		;
	}
	rev_data = U0RBR;
	return rev_data;	
}

static void uart_putchar(char data)
{
	U0THR = data;

	while(1 != (U0LSR & 0x40))
	{
		;
	}

}

int putchar(int c)  
{  
  while (!(U0LSR & 0x20)); 
  return (U0THR=c);  
}  