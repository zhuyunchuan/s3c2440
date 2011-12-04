#include "LPC210x.h"
#include "type.h"
#include "config.h"
#include "gpio.h"
#include "uart.h"
#include <stdio.h>

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

static int pll_init()
{

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


	while (1) {
//		led_off(18);	//turn off led2
		beep_on();	
        Delay(5000);
//		led_on(18);	//light led2
		beep_off();
        Delay(5000);
	}
}

