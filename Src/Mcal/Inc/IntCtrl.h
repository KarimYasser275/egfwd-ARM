/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  INTCTRL Header file
 *       Module:  INTCTRL
 *
 *  Description:  INTCTRL Header file  
 *  
 *********************************************************************************************************************/
// #ifndef <INTCTRL_H>
#define <INTCTRL_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
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
typedef enum IntCtrl_InterruptType_e
{
    uint32 THREAD_MODE = 0X0;
    uint32 NMI = 0x02
    uint32 HARD_FAULT=0x03;
    uint32 MEMORY_MANAGEMENT_FAULT = 0x04;
    uint32 BUS_FAULT = 0x05;
    uint32 USAGE_FAULT = 0x06;
    uint32 INTERUPT_VECTOR0 = 0x010;
    uint32 INTERUPT_VECTOR138 = 0x09A;

} IntCtrl_InterruptType_t ;
IntCtrl_InterruptType_t IntCtrl_InterruptType

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IntCtrl_Init(void);
 
// #endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
