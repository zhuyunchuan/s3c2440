#include <s3c2440.h>
#include "init.h"

static int gpio_init(void)
{
	GPHCON |= 0xaaa0;		//set GPH2~7 as TXD/RXD
	GPHUP |= 0xfc;			//pull up
	GPFCON |= 0x5566; 	    //set eint0/1/2/3 and gpiof 4/5/6/7
	GPFUP |= 0xf;			//disable gpio pull up
	GPFUP &= 0x0f;
	return 0;
}

//int systerm_init(void)
//{
//	clock_init(void);
//	gpio_init(void);
//	com_init(void);
//
//	return 0;
//}

int systerm_init()
{
	clock_init();
	gpio_init();
	com_init();

	return 0;
}

