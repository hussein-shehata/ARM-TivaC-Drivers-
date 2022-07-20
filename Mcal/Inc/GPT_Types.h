/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* defining the num of timers in the MCU */
#define     TIMERS_NUM      12


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint32  Gpt_ValueType ;

typedef void (*Gpt_CallBack_Ptr)(void)  ;   /* pointer to be used to call the  call back function */



/*Declaring the enums used to configure the Timers */


typedef enum 
{
    GPT_TIMER0,
    GPT_TIMER1,
    GPT_TIMER2,
    GPT_TIMER3,
    GPT_TIMER4,
    GPT_TIMER5,

    GPT_WIDE_TIMER0,
    GPT_WIDE_TIMER1,
    GPT_WIDE_TIMER2,
    GPT_WIDE_TIMER3,
    GPT_WIDE_TIMER4,
    GPT_WIDE_TIMER5
}Gpt_ChannelType;




typedef enum 
{
    GPT_NO_PS,
    GPT_PS_2,
    GPT_PS_4,
    GPT_PS_8,
    GPT_PS_16,
    GPT_PS_32,
    GPT_PS_64,
    GPT_PS_128,
    GPT_PS_256,
    GPT_PS_512,

}Gpt_PrescaleValue;




typedef enum 
{
    GPT_ONE_SHOT,
    GPT_PERIODIC
}Gpt_ChannelMode;




typedef enum 
{
    GPT_MODE_SLEEP =1 ,
    GPT_MODE_NORMAL 
}Gpt_Mode;



typedef enum 
{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;


/*Declaring the config struct used to config the Timer */

typedef struct  
{
    /* data */
    Gpt_ChannelType     GptChannelId;
    Gpt_PrescaleValue   GptChannelTickFrequency;
    Gpt_ValueType       GptChannelTickValueMax;
    Gpt_ChannelMode     ChannelMode;
    Gpt_CallBack_Ptr    GptNotification;

}Gpt_ConfigType;

extern const Gpt_ConfigType  Configurations[TIMERS_NUM] ;




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
