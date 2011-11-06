#include <LPC2103.h>

/*pll config*/
#define FOSC 	11059200 		//外部晶振频率
#define CCLK  	(FOSC * 6)      //系统工作频率，需为FOSC 的整数倍，且<=60MHz
#define FCCO 	(CCLK * 4) 		//CCO频率，必须为FCCKL的2、4、8、16倍，范围156M-320M
#define FPCLK   (CCLK / 4) * 4  //VPB时钟频率，只能为系统时钟(CCLK)的1倍，1/2倍或1/4倍

/*LED config*/
#define  LED1CON (0x)
#define  LED2CON
#define  LED3CON
