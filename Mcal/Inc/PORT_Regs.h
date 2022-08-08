/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Regs.h
 *       Module:  PORT
 *
 *  Description: header file for PORT Registers    
 *  
 *********************************************************************************************************************/
#ifndef PORT_REGS_H
#define PORT_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "PORT_Cfg.h"
#include "Platform_Types.h"
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



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


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
