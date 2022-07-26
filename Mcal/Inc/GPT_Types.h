/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  General purpose Timer
 *
 *  Description:  header file for General purpose Timer     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "GPT_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* defining the num of timers in the MCU */



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
    GPT_NO_PS = 1,
    GPT_PS_2 = 2,
    GPT_PS_4 = 4,
    GPT_PS_8 = 8,
    GPT_PS_16 = 16,
    GPT_PS_32 = 32,
    GPT_PS_64 = 64,
    GPT_PS_128 = 128,
    GPT_PS_256 = 255,
    GPT_PS_512 = 512,
    GPT_PS_1024 = 1024,
    GPT_PS_2048 = 2048,
    GPT_PS_4096 = 4096,
    GPT_PS_8192 = 8192,
    GPT_PS_16384 = 16384,
    GPT_PS_32768 = 32768,
    GPT_PS_65536 = 65535

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

extern const Gpt_ConfigType  Configurations_Timer[TIMERS_NUM] ;




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
