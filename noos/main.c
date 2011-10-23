#include <s3c2440.h>
#include "uart.h"
#include "init.h"

int main(int argc, char *argv[])
{
	systerm_init();
	
	while(1)
	{
		unsigned char data = read_char();

		write_char(data);
	}
}