
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
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
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : void IntCtrl_Init(void)        
* \Description     : Initiate Interrupt Control                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                       
*******************************************************************************/
void IntCtrl_Init(void)
{
    
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    /*Write 0x05FA in the VECTKEY bits and write priority level type that will be used in NVIC_PRIx or SCB_SYSPRIx Registers in PRIGROUP bits */
    APINT = 0x05FA|0x05; //4 group priorities and 2 sub priorities
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    /*Set priority for interrupt 0 to 3 in bits 7 & 6 and sub-priority to 1 in bit 5*/
    NVIC_PRI0 = 0xE0;
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	/*Enable Interrupt 0*/
    NVIC_EN0 &= 1;
	
    INTCTRL_Tag.B.VECACT = IntCtrl_InterruptType.INTERUPT_VECTOR0;

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
