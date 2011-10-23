/*系统时钟设置*/
#include <s3c2440.h>
#include "clock.h"

int clock_init(void)
{
	MPLLCON = 0x7f021;//set MPLL 403MHz
	CLKCON |= 0x1a00; //set uart0/1/2
	CLKDIVN |= 0x03;  //set FCLK : HCLK : PCLK = 1:4:8

	return 0;
}
