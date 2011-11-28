#include "i2c.h"

#define SDA0	(0x1 << )
#define SCL0	(0x1 << )
#define I2CEN 	(0X1 << 6)
#define STA		(0X1 << 5)
#define STO		(0x1 << 4)
#define SI		(0x1 << 3)
#define AA		(0x1 << 2)
#define AAC		(0x1 << 2)
#define I2CSLAVEADDR	0xa0	//c02 addr on i2c bus
#define WRITEMODE		1
#define READMODE		0

static i2c_read_byte(char addr)
{
	I2CONSET |= STA;	//send start condition
	while (0x80 != I2CSTAT)
	{
		;
	}	
	I2CONCLR |= STA; //clear start condition

	i2c_write_byte(addr);

}

static i2c_write_byte(char data)
{
	I2DAT = addr;
	I2CONCLR = SI;
}

int i2c_init()
{
	PINSEL0 |= 0x00000030; //set P0.2/0.3 as I2C
	I2SCLL = I2SCLH = 14;	//set BIT Frequence to 100kHz,Fpclk = 2.7648MHz,i2c = Fpclk/14+14 = 100KHz
	I2CONCLR |= STA | STO | SI | AA;	   //set as master mode
	I2CONSET |= I2CEN;
}