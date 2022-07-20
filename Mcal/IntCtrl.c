/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
//#include "Mcu_Hw.h"
#include "IntCtrl_Regs.h"
#include "BIT_MATH.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	SCB->APINT = OPERATED_OPTION;
	uint8 counter;
	for(counter = 0; counter < NUMBER_OF_INTERRUPTS; counter++)
	{	
		uint8 flag = 0;

		ConfigStruct CurrentStruct = Configurations.interrupt[counter];

		uint8 PRI_num = CurrentStruct.InterruptPeripheralGates / 4;
		uint8 PRI_index = CurrentStruct.InterruptPeripheralGates % 4;

		if(PRI_index == 0 )
		{
			NVIC->PRI[PRI_num] |= (CurrentStruct.Priority << 5);
		}
		else if(PRI_index == 1)
		{
			NVIC->PRI[PRI_num] |= (CurrentStruct.Priority << 13);
		}
		else if(PRI_index == 2)
		{
			NVIC->PRI[PRI_num] |= (CurrentStruct.Priority << 21);
		}
		else
		{
			NVIC->PRI[PRI_num] |= (CurrentStruct.Priority << 29);
		}

		while (CurrentStruct.InterruptPeripheralGates > 32)
		{
			CurrentStruct.InterruptPeripheralGates -= 32;
			flag++;
		}

		/**/



		if (CurrentStruct.Interrupt_state == Enabled)
		{
			SET_BIT(NVIC->EN[flag], CurrentStruct.InterruptPeripheralGates);
		}
		else
		{
			SET_BIT(NVIC->DIS[flag], CurrentStruct.InterruptPeripheralGates);
		}

		


	}
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  


	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/