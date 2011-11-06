#include <LPC2103.h>
#include <gpio.h>

int gpio_init()
{
	PINSEL1 &= ~( (0x1 << 3) | (0x1 << 4) | (0x1 << 5) | (0x1 << 6) | (0x1 << 7) | (0x1 << 8)); //set p0.17/18/19 as gpio port
	IO0DIR = LED3 | LED2 | LED1;
}

int gpio_set(int pin, int val)
{
	if (pin < 0) 
	{
		return -1;
	}

	if (0 == val) 
	{
		IO0CLR |= (1 << pin);
	}
	if (1 == val) {
		IO0SET |= (1 << pin);
	}

	return 0;
}

int gpio_read(int pin)
{
	int val =  IO0PIN;
	return val;
}
