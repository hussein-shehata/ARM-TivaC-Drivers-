#ifndef INTCTRL_REGS_H
#define INTCTRL_REGS_H

#include "Std_Types.h"


typedef struct
{

    volatile uint32     CPUID;
    volatile uint32     INTCTRL;
    volatile uint32     VTABLE;
    volatile uint32     APINT;
    volatile uint32     SYSCTRL;
    volatile uint32     CFGCTRL;
    volatile uint32     SYSPRI1;
    volatile uint32     SYSPRI2;
    volatile uint32     SYSPRI3;
    volatile uint32     SYSHNDCTRL;
    volatile uint32     FAULTSTAT;
    volatile uint32     HFAULTSTAT;
} SCB_Regs;

typedef struct
{
    /* data */
    volatile uint32     EN[5];
    volatile uint32     DIS[5];
    volatile uint32     PEND[5];
    volatile uint32     UNPEND[5];
    volatile uint32     ACTIVE[5];
    volatile uint32     PRI[35];

}NVIC_Regs;





#define     SCB_BASE_ADDRESS            0XE000ED00
#define     SCB                         ((volatile SCB_Regs * ) SCB_BASE_ADDRESS)

#define     NVIC_BASE_ADDRESS           0xE000E100
#define     NIVC_SWTRIG                 (*((volatile uint32 *) 0XE000EF00))
#define     NVIC                        ((volatile NVIC_Regs * ) NVIC_BASE_ADDRESS)


#endif

