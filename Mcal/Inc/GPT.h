/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  General purpose Timer
 *
 *  Description:  header file for General purpose Timer   
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT_Types.h"
#include "GPT_Regs.h"
#include "BIT_MATH.h"
#include "GPT_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Init(const  Gpt_ConfigType* ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeElapsed (Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel);

void Gpt_Notfication_TIMER0(void);
void Gpt_Notfication_TIMER1(void);
void Gpt_Notfication_TIMER2(void);
void Gpt_Notfication_TIMER3(void);
void Gpt_Notfication_TIMER4(void);
void Gpt_Notfication_TIMER5(void);
void Gpt_Notfication_W_TIMER0(void);
void Gpt_Notfication_w_TIMER1(void);
void Gpt_Notfication_w_TIMER2(void);
void Gpt_Notfication_w_TIMER3(void);
void Gpt_Notfication_w_TIMER4(void);
void Gpt_Notfication_w_TIMER5(void);


 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
