/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"
//#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/







const Config Configurations =
{
	GPIO_PORT_A,					Disabled, Group0,
	GPIO_PORT_B, 					Disabled, Group0,
	GPIO_PORT_C, 					Disabled, Group0,
	GPIO_PORT_D, 					Disabled, Group0,
	GPIO_PORT_E, 					Disabled, Group0,
	UART_0, 	 					Disabled, Group0,
	UART_1,							Disabled, Group0,
	SSI0,							Disabled, Group0,
	I2C0,							Disabled, Group0,
	PWM0_Fault,						Disabled, Group0,
	PWM0_Generator_0,				Disabled, Group0,
	PWM0_Generator_1,				Disabled, Group0,
	PWM0_Generator_2,				Disabled, Group0,
	QEI0,							Disabled, Group0,
	ADC0_Sequence_0,				Disabled, Group0,
	ADC0_Sequence_1,				Disabled, Group0,
	ADC0_Sequence_2,				Disabled, Group0,
	ADC0_Sequence_3,				Disabled, Group0,
	Watchdog_Timers_0_1,			Disabled, Group0,
	Timer_0A_16_32,					Disabled, Group0,
	Timer_0B_16_32,					Disabled, Group0,
	Timer_1A_16_32,					Enabled, Group0,
	Timer_1B_16_32,					Enabled, Group0,
	Timer_2A_16_32,					Disabled, Group0,
	Timer_2B_16_32,					Disabled, Group0,
	Analog_Comparator_0,			Disabled, Group0,
	Analog_Comparator_1,			Disabled, Group0,
	System_Control,					Disabled, Group0,
	Flash_Memory_Control_EEPROM,	Disabled, Group0,
	GPIO_PORT_F,					Disabled, Group0,
	UART_2 ,						Disabled, Group0,
	SSI_1,							Disabled, Group0,
	Timer_3A,						Disabled, Group0,
	Timer_3B,						Disabled, Group0,
	I2C_1,							Disabled, Group0,
	QEI_1,							Disabled, Group0,
	CAN_0,							Disabled, Group0,
	CAN_1,							Disabled, Group0,
	Hibernation_module,				Disabled, Group0,
	USB,							Disabled, Group0,
	PWM_Generation_3,				Disabled, Group0,
	uDMA_Software,					Disabled, Group0,
	uDMA_Error,						Disabled, Group0,
	ADC1_Sequence_0,				Disabled, Group0,
	ADC1_Sequence_1,				Disabled, Group0,
	ADC1_Sequence_2,				Disabled, Group0,
	ADC1_Sequence_3,				Disabled, Group0,
	SSI2,							Disabled, Group0,
	SSI3,							Disabled, Group0,
	UART_3,							Disabled, Group0,
	UART_4,							Disabled, Group0,
	UART_5,							Disabled, Group0,
	UART_6,							Disabled, Group0,
	UART_7,							Disabled, Group0,
	I2C_2,							Disabled, Group0,
	I2C_3,							Disabled, Group0,
	Timer_4A_16_32,					Disabled, Group0,
	Timer_4B_16_32,					Disabled, Group0,
	Timer_5A_16_32,					Disabled, Group0,
	Timer_5B_16_32,					Disabled, Group0,
	Timer_0A_32_64,					Disabled, Group0,
	Timer_0B_32_64,					Disabled, Group0,	
	Timer_1A_32_64,					Disabled, Group0,
	Timer_1B_32_64,					Disabled, Group0,
	Timer_2A_32_64,					Disabled, Group0,
	Timer_2B_32_64,					Disabled, Group0,
	Timer_3A_32_64,					Disabled, Group0,
	Timer_3B_32_64,					Disabled, Group0,
	Timer_4A_32_64,					Disabled, Group0,
	Timer_4B_32_64,					Disabled, Group0,
	Timer_5A_32_64,					Disabled, Group0,
	Timer_5B_32_64,					Disabled, Group0,
	System_Exception,				Disabled, Group0,
	PWM1_Generator_0,				Disabled, Group0,
	PWM1_Generator_1,				Disabled, Group0,
	PWM1_Generator_2,				Disabled, Group0,
	PWM1_Generator_3,				Disabled, Group0,
	PWM1_Fault,						Disabled, Group0,
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
