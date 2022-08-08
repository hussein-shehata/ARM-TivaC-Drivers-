/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Types.h
 *       Module:  PORT
 *
 *  Description: header file for PORT Driver      
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "PORT_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    PORT_A0, PORT_A1, PORT_A2, PORT_A3, PORT_A4, PORT_A5, PORT_A6, PORT_A7,
    PORT_B0, PORT_B1, PORT_B2, PORT_B3, PORT_B4, PORT_B5, PORT_B6, PORT_B7,
    PORT_C0, PORT_C1, PORT_C2, PORT_C3, PORT_C4, PORT_C5, PORT_C6, PORT_C7,
    PORT_D0, PORT_D1, PORT_D2, PORT_D3, PORT_D4, PORT_D5, PORT_D6, PORT_D7,
    PORT_E0, PORT_E1, PORT_E2, PORT_E3, PORT_E4, PORT_E5, PORT_E6, PORT_E7,
    PORT_F0, PORT_F1, PORT_F2, PORT_F3, PORT_F4, PORT_F5, PORT_F6, PORT_F7

}Port_PinType;

typedef enum 
{
    PORT_PIN_INPUT,
    PORT_PIN_OUTPIUT
}Port_PinDirectionType;

typedef enum 
{
    PORT_DIO_MODE,
    PORT_AF_1_MODE,
    PORT_AF_2_MODE,
    PORT_AF_3_MODE,
    PORT_AF_4_MODE,
    PORT_AF_5_MODE,
    PORT_AF_6_MODE,
    PORT_AF_7_MODE,
    PORT_AF_8_MODE,
    PORT_AF_9_MODE,
    PORT_AF_10_MODE,
    PORT_AF_11_MODE,
    PORT_AF_12_MODE,
    PORT_AF_13_MODE,
    PORT_AF_14_MODE,
    PORT_ANALOG_MODE
}Port_PinModeType;

typedef enum 
{
    PORT_NO_INTERNAL_RES,
    PORT_PULL_UP_RES,
    PORT_PULL_DOWN_RES,
    PORT_OPEN_DRAIN
}Port_PinInterrnalAttachType;

typedef enum 
{
    PORT_OUTPUT_CURRENT_2MA,
    PORT_OUTPUT_CURRENT_4MA,
    PORT_OUTPUT_CURRENT_8MA

}Port_PinOutputCurrentType;

typedef enum 
{
    PORT_PIN_LOW_LEVEL,
    PORT_PIN_HIGH_LEVEL
}Port_PinLevelValue;



typedef struct 
{
    /* data */
    Port_PinType                    PortPin;
    Port_PinDirectionType           PortPinDirection;
    Port_PinModeType                PortPinMode;
    Port_PinInterrnalAttachType     PortPinInternal;
    Port_PinOutputCurrentType       PortPinOPCurrent;
    Port_PinLevelValue              PortPinLevelValue;

}Port_ConfigType;


extern const Port_ConfigType Port_Configurations [PINS_NUM] ;


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
