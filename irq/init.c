#include <s3c2440.h>
#include "init.h"

static int gpio_init(void)
{
	GPHCON |= 0Xaaa0;		//set GPH2~7 as TXD/RXD
	GPHUP |= 0xfc;			//pull up

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

i
