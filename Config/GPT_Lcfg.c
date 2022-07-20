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
#include "GPT_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
************     *********************************************************************************************************/
#define     _16BITMAXVALUE       65536

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Gpt_ConfigType Configurations = 
{
    GPT_TIMER0,              GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_TIMER1,              GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_TIMER2,              GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_TIMER3,              GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_TIMER4,              GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_TIMER5,              GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_WIDE_TIMER0,         GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_WIDE_TIMER1,         GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_WIDE_TIMER2,         GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_WIDE_TIMER3,         GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_WIDE_TIMER4,         GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
    GPT_WIDE_TIMER5,         GPT_NO_PS, _16BITMAXVALUE, GPT_MODE_NORMAL, NULL_PTR,
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/