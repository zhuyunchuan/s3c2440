#include "type.h"
#include "config.h"

static delay(int delay)
{
	int j,i;

	for (j = 0; j < delay; j++) {
		for (i = 0; i < 600; i++) {
		}
	}
}

static int pll_init()
{
	PLLCON = 1; //set pll enable but not connect

	//set M 倍频和P分频
	int M = (CCLK / FOSC) - 1;
	int P = (FCCO / CCLK) / 2;

	switch (P)	
	{
		int PSEL;
		case 1:
				PSEL = 0x0;
				PLLCFG = (M) | (PSEL << 5);
		case 2:
				PSEL = 0x01;
				PLLCFG = (M) | (PSEL << 5);
		case 4:
				PSEL = 0x10;
				PLLCFG = (M) | (PSEL << 5);
		case 8:
				PSEL = 0x11;
				PLLCFG = (M) | (PSEL << 5);
		default:
				return -1;
	}

	//set  VPBDIV,VPBDIV只能是系统时钟CCLK的1倍，1/2，1/4
	int APBDIV = (CCLK / 4) / FPCLK;
	switch (APBDIV)
	{
		case 1:
				VPBDIV = 0;
		case 2:
				VPBDIV = 2;
		case 4:
				VPBDIV = 1;
		default:
				return -1;
	}

	PLLFEED = 0xaa;
	PLLFEED = 0x55;
	while(1 == (PLLSTAT & (1 << 10)))
	{
			;
	}
	PLLCON = 3;
	PLLFEED = 0xaa;
	PLLFEED = 0x55;

	return 0;
}

int  init(void)
{
	int ret = -1;
	if ((ret = pll_init()) != -1) 
	{
		gpio_init();
		return 0;
	}
	else {
		return -1;
	}
}


int main(int argc, const char *argv[])
{
	int led2 = 18;

	init();
	while (1) {
		gpio_set(led2, 1);
		delay(5);
		gpio_set(led2, 0);
		delay(5);
	}
}
