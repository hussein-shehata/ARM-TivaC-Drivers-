/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "GPT_Types.h"
#include "Platform_Types.h"
#include "GPT_Regs.h"
#include "BIT_MATH.h"
#include "GPT.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define MAX_NUM_TIMERS          12


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static void (*Gpt_CallBackPtr[TIMERS_NUM])(void) ;

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
void Gpt_Init(const  Gpt_ConfigType* ConfigPtr)
{
	uint8 index_of_timer ;
    uint8 counter_for_numbers_of_timers_max;
    Gpt_ConfigType current_struct ;

    /* For loop for making every call back pointer to function points to NULL PTR */
    for (counter_for_numbers_of_timers_max = 0; counter_for_numbers_of_timers_max < MAX_NUM_TIMERS; counter_for_numbers_of_timers_max++)
    {
        Gpt_CallBackPtr[counter_for_numbers_of_timers_max] = NULL_PTR; 
    }

    /* for loop for configuring each timer */
    for (index_of_timer = 0 ; index_of_timer < TIMERS_NUM; index_of_timer++)
    {

        current_struct = ConfigPtr[index_of_timer];


         /* Set the callback function */
        Gpt_CallBackPtr[current_struct.GptChannelId] = current_struct.GptNotification;

        //current_timer = current_struct.GptChannelId;
        /* switch case to know which timer we are processing on in this iteration */
        /*
        switch (current_struct.GptChannelId)
        {
            case GPT_TIMER0:
                current_timer = TIMER0;
                break;
            case GPT_TIMER1:
                current_timer = TIMER1;
                break;
            case GPT_TIMER2:
                current_timer = TIMER2;
                break;
            case GPT_TIMER3:
                current_timer = TIMER3;
                break;
            case GPT_TIMER4:
                current_timer = TIMER4;
                break;
            case GPT_TIMER5:
                current_timer = TIMER5;
                break;

            case GPT_WIDE_TIMER0:
                current_timer = WIDE_TIMER0;
                break;
            case GPT_WIDE_TIMER1:
                current_timer = WIDE_TIMER1;
                break;
            case GPT_WIDE_TIMER2:
                current_timer = WIDE_TIMER2;
                break;
            case GPT_WIDE_TIMER3:
                current_timer = WIDE_TIMER3;
                break;
            case GPT_WIDE_TIMER4:
                current_timer = WIDE_TIMER4;
                break;
            case GPT_WIDE_TIMER5:
                current_timer = WIDE_TIMER5;
                break;
            default:
                break;
        }
        */
       /* Configuring the run mode of the timer */
       if (current_struct.GptChannelId < 6)
       {
            SET_BIT(RCGCTIMER,current_struct.GptChannelId);
       }
       else
       {
            uint8 ReqBit = current_struct.GptChannelId - 6; 
            SET_BIT(RCGCWTIMER,ReqBit);
       }


        CLR_BIT(GPTMCTL(current_struct.GptChannelId), GPTMCTL_TAEN_BIT) /* we have to make sure that the bit is cleared before any operations */
        current_timer->GPTMCFG = 0x0;                 /*Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000*/

        /* Clear the bits fields so I can config the mode */
        CLR_BIT(GPTMTAMR(current_struct.GptChannelId),0);
        CLR_BIT(GPTMTAMR(current_struct.GptChannelId),1);

        /* it configs the register according to the requested channel mode */
        GPTMTAMR(current_struct.GptChannelId) |= current_struct.ChannelMode;
         
        SET_BIT(GPTMTAMR(current_struct.GptChannelId),GPTMTAMR_TACDIR_BIT); /* makes the timer counts up*/

    }
	
}


void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    /* Disable the Timer interrupt */
    CLR_BIT(GPTMTAMR(current_struct.GptChannelId), GPTMTAMR_TAMIE_BIT);

    /* Disable the timer match interrupt */
    CLR_BIT(GPTMIMR(current_struct.GptChannelId), GPTMIMR_TAMIM_BIT);
}


void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    /* Enable the Timer interrupt */
    SET_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);

    /* Enable the timer match interrupt */
    SET_BIT(GPTMIMR(Channel), GPTMIMR_TAMIM_BIT);
}


void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    /* Load the value in GPTMTAMATCHR Register with the required matching value*/
    GPTMTAMATCHR(Channel) = Value;

    /* Start the timer */
    SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}


void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    /* Stop the timer  */
    CLEAR_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}


/* ********************************************************************************************
*********************************the ISRs of all the timers************************************
**********************************************************************************************/

void TIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER0])();
        SET_BIT(GPTMICR(GPT_TIMER0),GPTMICR_TAMCINT_BIT);
    }
}

void TIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER1])();
        SET_BIT(GPTMICR(GPT_TIMER1),GPTMICR_TAMCINT_BIT);
    }
}

void TIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER2])();
        SET_BIT(GPTMICR(GPT_TIMER2),GPTMICR_TAMCINT_BIT);
    }
}

void TIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER3])();
        SET_BIT(GPTMICR(GPT_TIMER3),GPTMICR_TAMCINT_BIT);
    }
}

void TIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER4])();
        SET_BIT(GPTMICR(GPT_TIMER4),GPTMICR_TAMCINT_BIT);
    }
}

void TIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER5])();
        SET_BIT(GPTMICR(GPT_TIMER5),GPTMICR_TAMCINT_BIT);
    }
}


void WTIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER0])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER0),GPTMICR_TAMCINT_BIT);
    }
}


void WTIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER1])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER1),GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER2])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER2),GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER3])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER3),GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER4])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER4),GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER5])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER5),GPTMICR_TAMCINT_BIT);
    }
}






/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
