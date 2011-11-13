#include "LPC210x.h"

/*pll config*/
#define Fosc 	11059200 		//外部晶振频率
#define Fcclk  	(Fosc * 4)      //系统工作频率，需为FOSC 的整数倍，�?=60MHz
#define Fcco 	(Fcclk * 4) 		//CCO频率，必须为FCCKL�?�?�?�?6倍，范围156M-320M
#define Fpclk   (Fcclk / 4) * 1  //VPB时钟频率，只能为系统时钟(CCLK)�?倍，1/2倍或1/4�?
/*LED config*/

