#include "LPC210x.h"
#include "config.h"
#include "type.h"

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define 

typedef struct uart_dev uart_dev;

int uart_init(void);
//char* uart_read(int chan);
//int uart_write(int chan, char* str);
int putchar(int c);

#endif //config_h