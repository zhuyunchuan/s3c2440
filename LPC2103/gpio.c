#include "LPC210x.h"
#include "gpio.h"
#include "type.h"


int gpio_init()
{
	PINSEL0 = 0x00000000;
	PINSEL1 &= ~( (0x1 << 3) | (0x1 << 4) | (0x1 << 5) | (0x1 << 6) | (0x1 << 7) | (0x1 << 8) | (0x1 << 11) | (0x1 << 12)); //set p0.17/18/19/21 as gpio port
	IODIR = LED3 | LED2 | LED1 | BEEP;   //set direction
	IOSET = LED3 | LED2 | LED1 | BEEP;	 //inti as high v
	return 0;
}


int static gpio_set(int pin, int val)
{
	if (pin < 0) 
	{
		return -1;
	}

	if (0 == val) 
	{
		IOCLR |= (0x1 << pin);
	}
	if (1 == val) {
		IOSET |= (0x1 << pin);
	}

	return 0;
}

int gpio_read(int pin)
{
	int val =  IOPIN;
	return val;
} 

int beep_on(void)
{
	gpio_set(21, 0);
	
	return 0;
}

int beep_off(void)
{
	gpio_set(21, 1);

	return 0;
}

int led_on(led_num)
{
	gpio_set(led_num, 0);
	
	return 0;	
}

int led_off(led_num)
{
	gpio_set(led_num, 1);
	
	return 0;	
}
