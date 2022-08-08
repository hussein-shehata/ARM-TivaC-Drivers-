/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define 		GROUP3_0SUB 			0x05FA0400 	/* 3 bits for gp priority  and 0 bit for sub*/
#define 		GROUP2_1SUB				0x05FA0500 	/* 2 bits for gp priority  and 1 bit for sub*/
#define 		GROUP1_2SUB 			0x05FA0600 	/* 1 bits for gp priority  and 2 bit for sub*/
#define 		GROUP0_3SUB 			0x05FA0700 	/* 0 bits for gp priority  and 3 bit for sub*/

#define 		NUMBER_OF_INTERRUPTS	78



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



#if (OPERATED_OPTION == GROUP3_0SUB)
	typedef enum
	{
		Group0,
		Group1,
		Group2,
		Group3,
		Group4,
		Group5,
		Group6,
		Group7

	}PriGroup;

#elif (OPERATED_OPTION == GROUP2_1SUB)
	typedef enum
	{
		Group0_Sub0, // 000
		Group0_Sub1, // 001
		Group1_Sub0, // 010
		Group1_Sub1,
		Group2_Sub0,
		Group2_Sub1,
		Group3_Sub0,
		Group3_Sub1
		
	}PriGroup;

#elif  (OPERATED_OPTION == GROUP1_2SUB)
	typedef enum
	{
		Group0_Sub0,
		Group0_Sub1,
		Group0_Sub2,
		Group0_Sub3,
		Group1_Sub0,
		Group1_Sub1,
		Group1_Sub2,
		Group1_Sub3
		
	}PriGroup;

#elif  (OPERATED_OPTION == GROUP0_3SUB)
	typedef enum
	{
		Group0_Sub0,
		Group0_Sub1,
		Group0_Sub2,
		Group0_Sub3,
		Group0_Sub4,
		Group0_Sub5,
		Group0_Sub6,
		Group0_Sub7
		
	}PriGroup;

#endif


typedef enum
{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	UART_0,
	UART_1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator_0,
	PWM0_Generator_1,
	PWM0_Generator_2,
	QEI0,
	ADC0_Sequence_0,
	ADC0_Sequence_1,
	ADC0_Sequence_2,
	ADC0_Sequence_3,
	Watchdog_Timers_0_1,
	Timer_0A_16_32,
	Timer_0B_16_32,
	Timer_1A_16_32,
	Timer_1B_16_32,
	Timer_2A_16_32,
	Timer_2B_16_32,
	Analog_Comparator_0,
	Analog_Comparator_1,
	System_Control = 28,
	Flash_Memory_Control_EEPROM,
	GPIO_PORT_F,
	UART_2 = 33,
	SSI_1,
	Timer_3A,
	Timer_3B,
	I2C_1,
	QEI_1,
	CAN_0,
	CAN_1,
	Hibernation_module = 43,
	USB,
	PWM_Generation_3,
	uDMA_Software,
	uDMA_Error,
	ADC1_Sequence_0,
	ADC1_Sequence_1,
	ADC1_Sequence_2,
	ADC1_Sequence_3,
	SSI2  = 57,
	SSI3,
	UART_3,
	UART_4,
	UART_5,
	UART_6,
	UART_7,
	I2C_2 = 68,
	I2C_3,
	Timer_4A_16_32,
	Timer_4B_16_32,
	Timer_5A_16_32 = 92,
	Timer_5B_16_32,
	Timer_0A_32_64,
	Timer_0B_32_64,
	Timer_1A_32_64,
	Timer_1B_32_64,
	Timer_2A_32_64,
	Timer_2B_32_64,
	Timer_3A_32_64,
	Timer_3B_32_64,
	Timer_4A_32_64,
	Timer_4B_32_64,
	Timer_5A_32_64,
	Timer_5B_32_64,
	System_Exception,
	PWM1_Generator_0 = 134,
	PWM1_Generator_1,
	PWM1_Generator_2,
	PWM1_Generator_3,
	PWM1_Fault

}IntCtrl_InterruptType;

typedef enum 
{
    Disabled,
    Enabled
}IntCtrl_state;
 



typedef struct 
{
    /* data */
    IntCtrl_InterruptType InterruptPeripheralGates;
    IntCtrl_state         Interrupt_state;
	PriGroup              Priority; 

}ConfigStruct;


typedef struct 
{
	/* data */
	ConfigStruct interrupt[NUMBER_OF_INTERRUPTS] ;

}Config;

extern const Config Configurations;


#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
