#include <s3c2440.h>
#include "uart.h"

#define WRITEREADY (1<<3)
#define READREADY   0x01

static int com_init_test()
{
	int pclk = 403000000;
	ULCON0 |= 0x03; //set length
	ULCON0 &= 0xfb;	//set stop_bit
	ULCON0 &= 0xd0; //set sck
	UCON0 |= 0x05;	//set
	UFCON0 &= 0xfe; //set no fifo
	UMCON0 = 0x00;	//set no flow
	UBRDIV0  = (pclk/(115200*16))-1;

	return 0;
}
int com_init()
{
/*
	int channle = com_cfg->channle;
	int bit_rate =  com_cfg->bitrate;
	int sck = com_cfg->sck;
	int stop_bit = com_cfg->stop_bit;
	
	switch channle
	{
		case 0:
			ULCON0 
	}
*/
	com_init_test();

	return 0;
}



static int com_read_char(int channle, unsigned char data)
{
		
}

static int com_write_char(int channle, unsigned char data)
{
}

void write_char(unsigned char data)
{
	while(UTRSTAT0 & WRITEREADY)
	;
	UTXH0 = data;
}

unsigned char read_char()
{
	while(UTRSTAT0 & READREADY)
	;
	return URXH0;
}