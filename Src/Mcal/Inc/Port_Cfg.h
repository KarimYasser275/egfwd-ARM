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
#include "Port.h"

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
const Port_Config_t Port_Config_A[8];
const Port_Config_t Port_Config_B[8];
const Port_Config_t Port_Config_C[8];
const Port_Config_t Port_Config_D[8];
const Port_Config_t Port_Config_E[8];
const Port_Config_t Port_Config_F[8];


/*Configuration Parameters for Port A*/
Port_Config_A[0].Port_PinDir = OUTPUT;
Port_Config_A[1].Port_PinDir = OUTPUT;
Port_Config_A[2].Port_PinDir = OUTPUT;
Port_Config_A[3].Port_PinDir = OUTPUT;
Port_Config_A[4].Port_PinDir = OUTPUT;
Port_Config_A[5].Port_PinDir = OUTPUT;
Port_Config_A[6].Port_PinDir = OUTPUT;
Port_Config_A[7].Port_PinDir = OUTPUT;

Port_Config_A[0].Port_PinLevel = LOW;
Port_Config_A[1].Port_PinLevel = LOW;
Port_Config_A[2].Port_PinLevel = LOW;
Port_Config_A[3].Port_PinLevel = LOW;
Port_Config_A[4].Port_PinLevel = LOW;
Port_Config_A[5].Port_PinLevel = LOW;
Port_Config_A[6].Port_PinLevel = LOW;
Port_Config_A[7].Port_PinLevel = LOW;

Port_Config_A[0].Port_PinInternalAttach = PULL_DN;
Port_Config_A[1].Port_PinInternalAttach = PULL_DN;
Port_Config_A[2].Port_PinInternalAttach = PULL_DN;
Port_Config_A[3].Port_PinInternalAttach = PULL_DN;
Port_Config_A[4].Port_PinInternalAttach = PULL_DN;
Port_Config_A[5].Port_PinInternalAttach = PULL_DN;
Port_Config_A[6].Port_PinInternalAttach = PULL_DN;
Port_Config_A[7].Port_PinInternalAttach = PULL_DN;

Port_Config_A[0].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[1].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[2].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[3].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[4].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[5].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[6].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_A[7].Port_PinOutputCurrent = CURRENT_2MA;

/*Configuration Parameters for Port B*/
Port_Config_B[0].Port_PinDir = OUTPUT;
Port_Config_B[1].Port_PinDir = OUTPUT;
Port_Config_B[2].Port_PinDir = OUTPUT;
Port_Config_B[3].Port_PinDir = OUTPUT;
Port_Config_B[4].Port_PinDir = OUTPUT;
Port_Config_B[5].Port_PinDir = OUTPUT;
Port_Config_B[6].Port_PinDir = OUTPUT;
Port_Config_B[7].Port_PinDir = OUTPUT;

Port_Config_B[0].Port_PinLevel = LOW;
Port_Config_B[1].Port_PinLevel = LOW;
Port_Config_B[2].Port_PinLevel = LOW;
Port_Config_B[3].Port_PinLevel = LOW;
Port_Config_B[4].Port_PinLevel = LOW;
Port_Config_B[5].Port_PinLevel = LOW;
Port_Config_B[6].Port_PinLevel = LOW;
Port_Config_B[7].Port_PinLevel = LOW;

Port_Config_B[0].Port_PinInternalAttach = PULL_DN;
Port_Config_B[1].Port_PinInternalAttach = PULL_DN;
Port_Config_B[2].Port_PinInternalAttach = PULL_DN;
Port_Config_B[3].Port_PinInternalAttach = PULL_DN;
Port_Config_B[4].Port_PinInternalAttach = PULL_DN;
Port_Config_B[5].Port_PinInternalAttach = PULL_DN;
Port_Config_B[6].Port_PinInternalAttach = PULL_DN;
Port_Config_B[7].Port_PinInternalAttach = PULL_DN;

Port_Config_B[0].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[1].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[2].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[3].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[4].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[5].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[6].Port_PinOutputCurrent = CURRENT_2MA;
Port_Config_B[7].Port_PinOutputCurrent = CURRENT_2MA;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
