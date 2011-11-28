#include "LPC210x.h"
#include "config.h"
#include "type.h"

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define 

typedef struct uart_dev uart_dev;

int uart_init();
int uart_read(char*);
int uart_write();

#endif //config_h