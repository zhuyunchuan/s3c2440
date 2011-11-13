#include "LPC210x.h"
#include "type.h"
#include "config.h"
#include "gpio.h"

#define LED2CON (0x1<<18)

void Delay(int delay)
{
   int k;
   while(delay--)
   {
     for(k=0; k<1000; k++)
     {
        ;
     }
   }
}

/*
static int gpio_init()
{
	PINSEL0 = 0x00000000;
	PINSEL1 &= ~((0x1 << 3) | (0x1 << 4) | (0x1 << 5) | (0x1 << 6) | (0x1 << 7) | (0x1 << 8)); //set p0.17/18/19 as gpio port
	IODIR = LED3 | LED2 | LED1;
//	IOCLR = LED3 | LED2 | LED1;
	return 0;
}
*/

static int pll_init()
{
/*	
	//set M 鍊嶉鍜孭鍒嗛
	int M = (FCCLK / FOSC) - 1;
	int P = (FCCO / FCCLK) / 2;
	DWORD VPBDIV = 0;
	PLLCON = 1; //set pll enable but not connect

	switch (P)	
	{
		int PSEL;
		case 1:
				PSEL = 0;
				PLLCFG = (M) | (PSEL << 5);
		case 2:
				PSEL = 1;
				PLLCFG = (M) | (PSEL << 5);
		case 4:																																							 
				PSEL = 2;
				PLLCFG = (M) | (PSEL << 5);
		case 8:
				PSEL = 3;
				PLLCFG = (M) | (PSEL << 5);
		default:
				return -1;
	}

	//set  VPBDIV,VPBDIV鍙兘鏄郴缁熸椂閽烠CLK鐨?鍊嶏紝1/2锛?/4
	VPBDIV = (FCCLK / 4) / FPCLK;
	switch (VPBDIV)
	{
		case 1:
				APBDIV = 0;
		case 2:
				APBDIV = 2;
		case 4:
				APBDIV = 1;
		default:
				return -1;
	}

	PLLFEED = 0xaa;
	PLLFEED = 0x55;
	while(0 == (PLLSTAT & (1 << 10)))
	{
			;
	}
	PLLCON = 3;
	PLLFEED = 0xaa;
	PLLFEED = 0x55;
*/
	 /* 设置系统各部分时钟 */
	   PLLCON = 1;
	#if ((Fcclk / 4) / Fpclk) == 1
		VPBDIV = 0;
	#endif
	#if ((Fcclk / 4) / Fpclk) == 2
		VPBDIV = 2;
	#endif
	#if ((Fcclk / 4) / Fpclk) == 4
		VPBDIV = 1;
	#endif
                
	#if (Fcco / Fcclk) == 2
		PLLCFG = ((Fcclk / Fosc) - 1) | (0 << 5);
	#endif
	#if (Fcco / Fcclk) == 4
		PLLCFG = ((Fcclk / Fosc) - 1) | (1 << 5);
	#endif
	#if (Fcco / Fcclk) == 8
		PLLCFG = ((Fcclk / Fosc) - 1) | (2 << 5);
	#endif
	#if (Fcco / Fcclk) == 16
		PLLCFG = ((Fcclk / Fosc) - 1) | (3 << 5);
	#endif
                
		PLLFEED = 0xaa;
		PLLFEED = 0x55;
		while((PLLSTAT & (1 << 10)) == 0);
		PLLCON = 3;
		PLLFEED = 0xaa;
		PLLFEED = 0x55;	

	return 0;
}

int  sys_init(void)
{

	gpio_init();
	pll_init();
	
	return 0;
}


int main(int argc, const char *argv[])
{
	sys_init();
//	PINSEL1 &= ~( (0x1 << 3) | (0x1 << 4) | (0x1 << 5) | (0x1 << 6) | (0x1 << 7) | (0x1 << 8)); //set p0.17/18/19 as gpio port
//	IODIR = LED3 | LED2 | LED1;
//	PINSEL0 = 0X00000000;
//	PINSEL1 = 0X00000000;
//	IODIR =  LED2;

	while (1) {
		gpio_set(18, 1);
        Delay(2000);
//		IOSET = LED2;
		gpio_set(18, 0);
//		IOCLR = LED2;
        Delay(2000);
	}
}

