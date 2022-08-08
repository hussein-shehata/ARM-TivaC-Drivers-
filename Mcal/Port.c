/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
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
#include "Platform_Types.h"
#include "PORT.h"
#include "PORT_Regs.h"
#include "PORT_Types.h"
#include "PORT_Cfg.h"
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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/


void Port_Init(const Port_ConfigType* ConfigPtr) 
{   
    #if GPIO_BUS == GPIO_AHB
        GPIOHBCTL |= 0x3F;      /* Setting the first 6 bits to make the used is AHB */
    #elif GPIO_BUS == GPIO_APP
        GPIOHBCTL &= 0xC0;      /* Clearing the first 6 bits to make the used is App */

    #endif

    uint8 counter ;
    uint8 PortNum ;
    uint8 PinNum ;
    Port_ConfigType current_struct;
    for (counter = 0; counter < PINS_NUM; counter++)
    {
        current_struct = ConfigPtr[counter];
        PortNum = current_struct.PortPin / 8;
        PinNum  = current_struct.PortPin % 8 ;

        /* enabling clock in run mode   hb2a a3ml el sleep mode w el deep sleep mode b3den */
        SET_BIT(RCGCGPIO, current_struct.PortPin / 8 );

        /* **********************configuring the Direction and the Intial value of the Pin of the corresponding port *************************/
        if (current_struct.PortPinDirection == PORT_PIN_OUTPIUT )
        {
            SET_BIT(GPIODIR(PortNum), PinNum);
            /* checking and configuring the intital value for the pin if its output pin */
            if(current_struct.PortPinLevelValue == PORT_PIN_HIGH_LEVEL)
            {
                SET_BIT(GPIODATA(PortNum), PinNum);
            }

            else if(current_struct.PortPinLevelValue == PORT_PIN_LOW_LEVEL)
            {
                CLR_BIT(GPIODATA(PortNum), PinNum);
            }

            else
            {
                /* Do nothing */
            }
        }

        else if (current_struct.PortPinDirection == PORT_PIN_INPUT )
            CLR_BIT(GPIODIR(PortNum), PinNum);


    /* ***************************** Configuring the mode option for each pin either DIO or ADC or AF mode  ********************************/

        if(current_struct.PortPinMode == PORT_DIO_MODE )
        {
            /* Disable Alternive Function for this pin */
            CLR_BIT(GPIOAFSEL(PortNum), PinNum); 
            /* enable digital functions for the correspending pin */
            SET_BIT(GPIODEN(PortNum), PinNum);
            /* Disable the analog functions for the correspending pin */
            CLR_BIT(GPIOAMSEL(PortNum), PinNum) ;

        }

        else if (current_struct.PortPinMode == PORT_ANALOG_MODE)
        {
            /* Disable Alternive Function for this pin */
            CLR_BIT(GPIOAFSEL(PortNum), PinNum); 
            /* Disable digital functions for the correspending pin */
            CLR_BIT(GPIODEN(PortNum), PinNum);
            /* Enable the analog functions for the correspending pin */
            SET_BIT(GPIOAMSEL(PortNum), PinNum) ;

            /* Enable  the correspending pin to trigger the ADC  */
            SET_BIT(GPIOADCCTL(PortNum), PinNum) ;

            /*******************************************************************************
             * ************************ LATER***********************************************
             * *****************************************************************************/

            /* will ask the user to select DMA or ADC later */
            /* Enable  the correspending pin to trigger the DMA  */
            //SET_BIT(GPIODMACTL(PortNum), PinNum) ;
        }


        else if (current_struct.PortPinMode >=  PORT_AF_1_MODE && current_struct.PortPinMode <=  PORT_AF_14_MODE ) 
        {
            /* Enable Alternive Function for this pin */
            SET_BIT(GPIOAFSEL(PortNum), PinNum); 
            /* Disable digital functions for the correspending pin */
            CLR_BIT(GPIODEN(PortNum), PinNum);
            /* Disable the analog functions for the correspending pin */
            CLR_BIT(GPIOAMSEL(PortNum), PinNum) ;

            /* Configuring the AFIO pin to be used as the excat requested peripheral from the user */
            GPIOPCTL(PortNum) &= ~((0b1111) << (4*PinNum) ) ;
            GPIOPCTL(PortNum) |=  ((current_struct.PortPinMode) << (4*PinNum) ) ;
        }
        

        else 
        {
            /* if entered this else condition that means that the user entered wrong input in the MODE option */
        }

        
    /* ***************************** Configuring the Output current option for each pin ********************************/
        if (current_struct.PortPinOPCurrent == PORT_OUTPUT_CURRENT_2MA )
        {
            SET_BIT(GPIODR2R(PortNum), PinNum);
        }
        else if (current_struct.PortPinOPCurrent == PORT_OUTPUT_CURRENT_4MA )
        {
            SET_BIT(GPIODR4R(PortNum), PinNum);
        }

        else if (current_struct.PortPinOPCurrent == PORT_OUTPUT_CURRENT_8MA )
        {
            SET_BIT(GPIODR8R(PortNum), PinNum);
        }

        else 
        {
            /* if entered this else condition that means that the user entered wrong input in the OUTPUT CURRENT option */
        }



        


    /* ***************************** Configuring the internal resistance option for each pin ********************************/

        if (current_struct.PortPinInternal == PORT_PULL_UP_RES )
        {
            SET_BIT(GPIOPUR(PortNum), PinNum);
        }

        else if (current_struct.PortPinInternal == PORT_PULL_DOWN_RES )
        {
            SET_BIT(GPIOPDR(PortNum), PinNum);
        }

        else if (current_struct.PortPinInternal == PORT_OPEN_DRAIN )
        {
            SET_BIT(GPIOODR(PortNum), PinNum);
        }
        else if (current_struct.PortPinInternal == PORT_NO_INTERNAL_RES)
        {
            /* this part is responsible for the No internal resistance part  therefor there is nothing to do here only clearing bit to be more sure */
            CLR_BIT(GPIOPUR(PortNum), PinNum);
            CLR_BIT(GPIOPDR(PortNum), PinNum);
            CLR_BIT(GPIOODR(PortNum), PinNum);
        }
        else 
        {
            /* if entered this else condition that means that the user entered wrong input in theINTERNAL RESISTANCE option */
        }
    }
}   
	
	


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
