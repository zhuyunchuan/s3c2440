#include "type.h"

#ifndef __IRQ_H 
#define __IRQ_H
#define NESTED_INTERRUPT	0

#define I_Bit			0x80
#define F_Bit			0x40

#define SYS32Mode		0x1F
#define IRQ32Mode		0x12
#define FIQ32Mode		0x11



#define IRQ_SLOT_EN		0x20	/* bit 5 in Vector control register */
#define VIC_SIZE		16

#define VIC_BASE_ADDR	0xfffff000
#define VECT_ADDR_INDEX	0x100
#define VECT_CNTL_INDEX 0x200

static DWORD sysreg;		/* used as LR register */
#if NESTED_INTERRUPT 
#define IENABLE __asm { MRS sysreg, SPSR; MSR CPSR_c, #SYS32Mode }
#else
#define IENABLE ;	/* do nothing */
#endif

#if NESTED_INTERRUPT
#define IDISABLE __asm { MSR CPSR_c, #(IRQ32Mode|I_Bit); MSR SPSR_cxsf, sysreg }
#else
#define IDISABLE ;	/* do nothing */
#endif

typedef void (*IRQHANDLEFun)(void)

void irq_init(void);
int install_irq(int irq_num, IRQHANDLEFUN irq_fun);

#endif