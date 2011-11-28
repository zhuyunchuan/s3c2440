#include "LPC210x.h"
#include "type.h"
#include "config.h"
#include "irq.h"

void DefaultVICHandler (void) __irq
(
	VICVectAddr = 0;		/* Acknowledge Interrupt */ 
    while (1)
	{
		;
	}
)

void irq_init()
{
	int i = 0;
	int *vect_addr = NULL;
	int *vect_cntl = NULL;

	VICIntEnClr = 0xffffffff;    /* disabel all interrupt*/
	VICVectAddr = 0;
	VICIntSelect = 0;

	/*set VICVectAddr0~15 to 0,set VICVectCntl0~15 to 0*/
	for ( i = 0; i < VIC_SIZE; i++ )
    {
		vect_addr = (int *)(VIC_BASE_ADDR + VECT_ADDR_INDEX + i*4);
		vect_cntl = (int *)(VIC_BASE_ADDR + VECT_CNTL_INDEX + i*4);
		*vect_addr = 0;	
		*vect_cntl = 0;
    }

	VICDefVectAddr = (int)DefaultVICHandler;
	return;
}

int install_irq(int irq_num, IRQHANDLEFun irq_fun)
{
	int i = 0;
	int *vect_addr = NULL;
	int *vect_cntl = NULL;

	VICIntEnClr = 1 << irq_num;	//disable the interrupt
	
	/* find first un-assigned VIC address for the handler */
	for ( i = 0; i < VIC_SIZE; i++ )
    {
		vect_addr = (int *)(VIC_BASE_ADDR + VECT_ADDR_INDEX + i*4);
		vect_cntl = (int *)(VIC_BASE_ADDR + VECT_CNTL_INDEX + i*4);
		if (NULL == vect_addr)
		{
			*vect_addr = irq_fun;							//set interrput vector
			*vect_cntl = (int)(IRQ_SLOT_EN | IntNumber); 	//set bit5 of vect_cntl to 1
			break;
		}

		if (i == VIC_SIZE)
		{
			return (FALSE);
		}
    }

	
	VICIntEnable = 1 << irq_num;//enable the interrput
	return TURE;		
}