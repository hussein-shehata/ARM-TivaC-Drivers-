/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
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

static void (*Gpt_CallBackPtr[MAX_NUM_TIMERS])(void) = {NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR};

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

    /* for loop for configuring each timer */
    for (index_of_timer = 0 ; index_of_timer < TIMERS_NUM; index_of_timer++)
    {

        current_struct = ConfigPtr[index_of_timer];


         /* Set the callback function */
        Gpt_CallBackPtr[current_struct.GptChannelId] = current_struct.GptNotification;

        
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


        CLR_BIT(GPTMCTL(current_struct.GptChannelId), GPTMCTL_TAEN_BIT); /* we have to make sure that the bit is cleared before any operations */
        
        GPTMCFG(current_struct.GptChannelId) = 0x0;                 /*Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000*/
        GPTMCFG(current_struct.GptChannelId) = 0x4;

        /* Clear the bits fields so I can config the mode */
        CLR_BIT(GPTMTAMR(current_struct.GptChannelId),0);
        CLR_BIT(GPTMTAMR(current_struct.GptChannelId),1);

        /* it configs the register according to the requested channel mode */
        GPTMTAMR(current_struct.GptChannelId) |= current_struct.ChannelMode;
         
        SET_BIT(GPTMTAMR(current_struct.GptChannelId),GPTMTAMR_TACDIR_BIT); /* makes the timer counts up*/

        /********************************Configuring the prescaler************************* */
        GPTMTAPR(current_struct.GptChannelId) = current_struct.GptChannelTickFrequency;

    }
	
}


void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    /* Disable the Timer interrupt */
    CLR_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);

    /* Disable the timer out interrupt */
    CLR_BIT(GPTMIMR(Channel), GPTMIMR_TATOIM_BIT);
}


void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    /* Enable the Timer interrupt */
    SET_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);

    /* Enable the timer out interrupt */
    SET_BIT(GPTMIMR(Channel), GPTMIMR_TATOIM_BIT);

}


void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    /* Load the value in GPTMTAILR Register with the required matching value*/
    GPTMTAILR(Channel) = Value;

    /* Start the timer */
    SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}


void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    /* Stop the timer  */
    CLR_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}



Gpt_ValueType Gpt_GetTimeElapsed (Gpt_ChannelType Channel)
{
    return (GPTMTAV(Channel));
}


Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel)
{
    Gpt_ValueType time_difference;
    time_difference = GPTMTAILR(Channel) - GPTMTAV(Channel);
    return (time_difference);
}

/* ********************************************************************************************
*********************************the ISRs of all the timers************************************
**********************************************************************************************/

void TIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER0])();
        SET_BIT(GPTMICR(GPT_TIMER0),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void TIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER1])();
        SET_BIT(GPTMICR(GPT_TIMER1),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void TIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER2])();
        SET_BIT(GPTMICR(GPT_TIMER2),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void TIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER3])();
        SET_BIT(GPTMICR(GPT_TIMER3),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void TIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER4])();
        SET_BIT(GPTMICR(GPT_TIMER4),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void TIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER5])();
        SET_BIT(GPTMICR(GPT_TIMER5),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}


void WTIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER0])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER0),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}


void WTIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER1])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER1),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    } 
}

void WTIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER2])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER2),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void WTIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER3])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER3),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void WTIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER4])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER4),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}

void WTIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER5])();
        SET_BIT(GPTMICR(GPT_WIDE_TIMER5),GPTMICR_TATOCINT_BIT); /*clearing the interrupt flag manually */
    }
}






/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
