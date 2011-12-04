#include "LPC210x.h"

#ifndef __CONFIG_H__
#define __CONFIG_H__

/*pll config*/
#define Fosc 	11059200 		//澶栭儴鏅舵尟棰戠巼
#define Fcclk  	(Fosc * 4)      //绯荤粺宸ヤ綔棰戠巼锛岄渶涓篎OSC 鐨勬暣鏁板�嶏紝涓?=60MHz
#define Fcco 	(Fcclk * 4) 		//CCO棰戠巼锛屽繀椤讳负FCCKL鐨?銆?銆?銆?6鍊嶏紝鑼冨洿156M-320M
#define Fpclk   (Fcclk / 4) * 1  //VPB鏃堕挓棰戠巼锛屽彧鑳戒负绯荤粺鏃堕挓(CCLK)鐨?鍊嶏紝1/2鍊嶆垨1/4鍊?

/*irq config*/
//中断号根据VICIntEnable来设置
#define	WDT_INT			0
#define SWI_INT			1
#define ARM_CORE0_INT	2
#define	ARM_CORE1_INT	3
#define	TIMER0_INT		4
#define TIMER1_INT		5
#define UART0_INT		6
#define	UART1_INT		7
#define	PWM0_INT		8
#define I2C0_INT		9
#define SPI0_INT		10
#define	SPI1_INT		11
#define	PLL_INT			12
#define RTC_INT			13
#define EINT0_INT		14
#define EINT1_INT		15
#define EINT2_INT		16
#define EINT3_INT		17
#define	ADC0_INT		18
#define I2C1_INT		19
#define BOD_INT			20
#define ADC1_INT		21
#define USB_INT			22

#endif //__CONFIG_H__
