#include "LPC210x.h"
#include "type.h"

#define LED1   (0x1 << 19)
#define LED2   (0x1 << 18)
#define LED3   (0x1 << 17)

int gpio_set(int pin, int val);
int gpio_read(int pin);
int gpio_init(void);


