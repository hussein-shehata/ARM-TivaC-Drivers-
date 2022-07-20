/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_REGS_H
#define GPT_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Timers base addresses */
/*
#define TIMER_0_BASE_ADDRESS                0x40030000
#define TIMER_1_BASE_ADDRESS                0x40031000
#define TIMER_2_BASE_ADDRESS                0x40032000
#define TIMER_3_BASE_ADDRESS                0x40033000
#define TIMER_4_BASE_ADDRESS                0x40034000
#define TIMER_5_BASE_ADDRESS                0x40035000

#define WIDE_TIMER_0_BASE_ADDRESS           0x40036000
#define WIDE_TIMER_1_BASE_ADDRESS           0x40037000
#define WIDE_TIMER_2_BASE_ADDRESS           0x4004C000
#define WIDE_TIMER_3_BASE_ADDRESS           0x4004D000
#define WIDE_TIMER_4_BASE_ADDRESS           0x4004E000
#define WIDE_TIMER_5_BASE_ADDRESS           0x4004F000
*/

/* It has its own defination because it is not in the sequence of increasing the offset */
#define GPTMPP_OFFSET_ADDRESS               0xFC0


/* Pointer to struct for each timer so we can access the registers corresponding to each Timer */
/*
#define     TIMER0                         ((volatile GPT_Regs * ) TIMER_0_BASE_ADDRESS)
#define     TIMER1                         ((volatile GPT_Regs * ) TIMER_1_BASE_ADDRESS)
#define     TIMER2                         ((volatile GPT_Regs * ) TIMER_2_BASE_ADDRESS)
#define     TIMER3                         ((volatile GPT_Regs * ) TIMER_3_BASE_ADDRESS)
#define     TIMER4                         ((volatile GPT_Regs * ) TIMER_4_BASE_ADDRESS)
#define     TIMER5                         ((volatile GPT_Regs * ) TIMER_5_BASE_ADDRESS)

#define     WIDE_TIMER0                    ((volatile GPT_Regs * ) WIDE_TIMER_0_BASE_ADDRESS)
#define     WIDE_TIMER1                    ((volatile GPT_Regs * ) WIDE_TIMER_1_BASE_ADDRESS)
#define     WIDE_TIMER2                    ((volatile GPT_Regs * ) WIDE_TIMER_2_BASE_ADDRESS)
#define     WIDE_TIMER3                    ((volatile GPT_Regs * ) WIDE_TIMER_3_BASE_ADDRESS)
#define     WIDE_TIMER4                    ((volatile GPT_Regs * ) WIDE_TIMER_4_BASE_ADDRESS)
#define     WIDE_TIMER5                    ((volatile GPT_Regs * ) WIDE_TIMER_5_BASE_ADDRESS)
*/


/* Pointer to struct for each timer so we can access the registers corresponding to each Timer */
/*
#define     TIMER0_GPTMPP                  (*((volatile uint32 *) TIMER_0_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     TIMER1_GPTMPP                  (*((volatile uint32 *) TIMER_1_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     TIMER2_GPTMPP                  (*((volatile uint32 *) TIMER_2_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     TIMER3_GPTMPP                  (*((volatile uint32 *) TIMER_3_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     TIMER4_GPTMPP                  (*((volatile uint32 *) TIMER_4_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     TIMER5_GPTMPP                  (*((volatile uint32 *) TIMER_5_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))

#define     WIDE_TIMER0_GPTMPP             (*((volatile uint32 *) WIDE_TIMER_0_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     WIDE_TIMER1_GPTMPP             (*((volatile uint32 *) WIDE_TIMER_1_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     WIDE_TIMER2_GPTMPP             (*((volatile uint32 *) WIDE_TIMER_2_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     WIDE_TIMER3_GPTMPP             (*((volatile uint32 *) WIDE_TIMER_3_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
#define     WIDE_TIMER4_GPTMPP             (*((volatile uint32 *) WIDE_TIMER_4_BASE_ADDRESS + GPTMPP_OFFSET_ADDRESS))
*/
/* Definations for the common bits in the register */
#define GPTMCTL_TAEN_BIT                   0

#define GPTMTAMR_TAMIE_BIT                 5
#define GPTMTAMR_TACDIR_BIT                4
#define GPTMTAMR_TAMR_BIT                  0

#define GPTMIMR_TAMIM_BIT                  4
#define GPTMIMR_TATOIM_BIT                 0
#define GPTMICR_TAMCINT_BIT                4

/* General Purpose Timer Run Mode Clock Gating Control Addresses */
#define RCGCTIMER_ADDRESS               0x400FE604
#define RCGCWTIMER_ADDRESS              0x400FE65C


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* To get the base address of the timer */
#define GPT_BASE_ADDRESS(x)		    (x<8? ((0x40030000) + ((x)*0x1000)):((0x4004C000) + ((x-8)*0x1000)))

#define GPTMCFG(x)                  *((volatile uint32*)GPT_BASE_ADDRESS(x))
#define GPTMTAMR(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x004))
#define GPTMTBMR(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x008))
#define GPTMCTL(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x00C))
#define GPTMSYNC(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x010))
#define GPTMIMR(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x018))
#define GPTMRIS(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x01C))
#define GPTMMIS(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x020))
#define GPTMICR(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x024))
#define GPTMTAILR(x)                *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x028))
#define GPTMBILR(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x02C))
#define GPTMTAMATCHR(x)             *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x030))        
#define GPTMTBMATCHR(x)             *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x034))
#define GPTMTAPR(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x038))
#define GPTMTBPR(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x03C))
#define GPTMTAPMR(x)                *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x040))
#define GPTMTBPMR(x)                *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x044))
#define GPTMTAR(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x048))
#define GPTMTBR(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x04C))
#define GPTMTAV(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x050))
#define GPTMTBV(x)                  *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x054))
#define GPTMRTCPD(x)                *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x058))
#define GPTMTAPS(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x05C))
#define GPTMTBPS(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x060))
#define GPTMTAPV(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x064))
#define GPTMTBPV(x)                 *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0x068))
#define GPTMPP(x)                   *((volatile uint32*)(GPT_BASE_ADDRESS(x) + 0xFC0))


/* Registers to enable clock for the timers */
#define RCGCTIMER                  *((volatile uint32*)(RCGCTIMER_ADDRESS))     
#define RCGCWTIMER                 *((volatile uint32*)(RCGCWTIMER_ADDRESS)) 

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*
typedef struct 
{
    uint32 GPTMCFG;
    uint32 GPTMTAMR;
    uint32 GPTMTBMR;
    uint32 GPTMCTL;
    uint32 GPTMSYNC;
    uint32 GPTMIMR;
    uint32 GPTMRIS;
    uint32 GPTMMIS;
    uint32 GPTMICR;
    uint32 GPTMTAILR;
    uint32 GPTMTBILR;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTBMATCHR;
    uint32 GPTMTAPR;
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMRTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;
}GPT_Regs;
*/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
