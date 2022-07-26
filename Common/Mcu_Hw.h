/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "PORT_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/******************************************************************************************
 * ***************************************IntCtrl Registers ******************************
 * ***************************************************************************************/

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




/******************************************************************************************
 * ***************************************Port Registers ******************************
 * ***************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* used to configure the used Data Bus for the GPIO
 used in the Cfg file */

#define         GPIO_AHB             1
#define         GPIO_APP             0






#if GPIO_BUS == GPIO_APP

#define         GPIO_PORTA_BASE_ADDRESS              0X40004000
#define         GPIO_PORTB_BASE_ADDRESS              0X40005000
#define         GPIO_PORTC_BASE_ADDRESS              0X40006000
#define         GPIO_PORTD_BASE_ADDRESS              0X40007000
#define         GPIO_PORTE_BASE_ADDRESS              0X40024000
#define         GPIO_PORTF_BASE_ADDRESS              0X40025000

#define         GPIO_X_ADDRESS(x)              ( x < 4 ? (GPIO_PORTA_BASE_ADDRESS + (x * 0x00001000) ) : (GPIO_PORTE_BASE_ADDRESS + (( (x-4) * 0x00001000)) ) )

#elif GPIO_BUS == GPIO_AHB

#define         GPIO_PORTA_BASE_ADDRESS              0X40058000
#define         GPIO_PORTB_BASE_ADDRESS              0X40059000
#define         GPIO_PORTC_BASE_ADDRESS              0X4005A000
#define         GPIO_PORTD_BASE_ADDRESS              0X4005B000
#define         GPIO_PORTE_BASE_ADDRESS              0X4005C000
#define         GPIO_PORTF_BASE_ADDRESS              0X4005D000

#define         GPIO_X_ADDRESS(x)              (( GPIO_PORTA_BASE_ADDRESS + (x * 0x00001000) ) )

#else
#error "Wrong input in config file "

#endif


#define     GPIOHBCTL_BASE_ADDRESS                    0x400FE06C
#define     RCGCGPIO_BASE_ADDRESS                     0X400FE608


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#define         GPIODATA(x)                 *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x3FC))
#define         GPIODIR(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x400))
#define         GPIOIS(x)                   *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x404))
#define         GPIOIBE(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x408))
#define         GPIOIEV(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x40C))
#define         GPIOIM(x)                   *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x410))
#define         GPIORIS(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x414))
#define         GPIOMIS(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x418))
#define         GPIOICR(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x41C))
#define         GPIOAFSEL(x)                *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x420))
#define         GPIODR2R(x)                 *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x500))
#define         GPIODR4R(x)                 *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x504))
#define         GPIODR8R(x)                 *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x508))
#define         GPIOODR(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x50C))
#define         GPIOPUR(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x510))
#define         GPIOPDR(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x514))
#define         GPIOSLR(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x518))
#define         GPIODEN(x)                  *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x51C))
#define         GPIOLOCK(x)                 *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x520))
#define         GPIOCR(x)                   *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x524))
#define         GPIOAMSEL(x)                *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x528))
#define         GPIOPCTL(x)                 *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x52C))
#define         GPIOADCCTL(x)               *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x530))
#define         GPIODMACTL(x)               *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0x534))
#define         GPIOPeriphID4(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFD0))
#define         GPIOPeriphID5(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFD4))
#define         GPIOPeriphID6(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFD8))
#define         GPIOPeriphID7(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFDC))
#define         GPIOPeriphID0(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFE0))
#define         GPIOPeriphID1(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFE4))
#define         GPIOPeriphID2(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFE8))
#define         GPIOPeriphID3(x)            *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFEC))
#define         GPIOPCellID0(x)             *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFF0))
#define         GPIOPCellID1(x)             *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFF4))
#define         GPIOPCellID2(x)             *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFF8))
#define         GPIOPCellID3(x)             *((volatile uint32*)(GPIO_X_ADDRESS(x) + 0xFFC))



/* register responsible for configuring the used bus for each port */
#define         GPIOHBCTL                    *((volatile uint32*)(GPIOHBCTL_BASE_ADDRESS))


#define         RCGCGPIO                     *((volatile uint32*)(RCGCGPIO_BASE_ADDRESS))







/******************************************************************************************
 * ***************************************GPIO Registers ******************************
 * ***************************************************************************************/
/* It has its own defination because it is not in the sequence of increasing the offset */
#define GPTMPP_OFFSET_ADDRESS               0xFC0

/* Definations for the common bits in the register */
#define GPTMCTL_TAEN_BIT                   0

#define GPTMTAMR_TAMIE_BIT                 5
#define GPTMTAMR_TACDIR_BIT                4
#define GPTMTAMR_TAMR_BIT                  0

#define GPTMIMR_TAMIM_BIT                  4
#define GPTMIMR_TATOIM_BIT                 0
//#define GPTMICR_TAMCINT_BIT                4

#define GPTMICR_TATOCINT_BIT               0

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
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
