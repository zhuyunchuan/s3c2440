#include "LPC210x.h"
#include "type.h"

#ifndef __GPIO_H__
#define __GPIO_H__

//led config
#define LED1   (0x1 << 19)
#define LED2   (0x1 << 18)
#define LED3   (0x1 << 17)

//beep config
#define BEEP   (0x1 << 21)

//int gpio_set(int pin, int val);
int gpio_read(int pin);
int gpio_init(void);
int led_on(int led_num);
int led_off(int led_num);
int beep_on(void);
int beep_off(void);

#endif //__GPIO_H__


