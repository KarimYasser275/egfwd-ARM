/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
//#ifndef <PORT_H>
#define <PORT_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_HW.h"
#include "platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum Port_PinDir_e
{
    INPUT,
    OUTPUT
}Port_PinDir_t;

typedef enum Port_PinLevel_e
{
    HIGH = 1U,
    LOW = 0U,
} Port_PinLevel_t;

typedef enum Port_PinInternalAttach_e
{
    PULL_UP,
    PULL_DN,
    OPEN_DRAIN
}Port_PinInternalAttach_t;

typedef enum Port_PinOutputCurrent_e
{
    CURRENT_2MA,
    CURRENT_4MA,
    CURRENT_8MA,
}Port_PinOutputCurrent_t;


typedef struct Port_Config_s
{
    Port_PinDir_t Port_PinDir;
    Port_PinLevel_t Port_PinLevel;
    Port_PinInternalAttach_t Port_PinInternalAttach;
    Port_PinOutputCurrent_t Port_PinOutputCurrent;
}Port_Config_t;

typedef struct Ports_Cfg_s
{
    Port_Config_t Port_A;
    Port_Config_t Port_B;
    Port_Config_t Port_C;
    Port_Config_t Port_D;
    Port_Config_t Port_E;
    Port_Config_t Port_F;
}Ports_Cfg_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init(void);
Std_ReturnType Port_Channel_Dir(Dio_PortType_t port , uint8 channel , Port_PinDir_t direction);
Std_ReturnType Port_Pin_Write (Dio_PortType_t port , uint8 channel , Port_PinLevel_t Level );

 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
