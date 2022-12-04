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
#include "platform_Types.h"
#include "Timer.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define GPT_ACTIVATED_CHANNELS_SIZE						1
/**********************************************************************************************************************
  *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void LedBlink (void);
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
const Gpt_ConfigType_t User_GPT_Cfg[GPT_ACTIVATED_CHANNELS_SIZE];

User_GPT_Cfg[0].channel = GPT_16_32_BIT_TIMER0;
User_GPT_Cfg[0].channelMode = GPT_CH_MODE_CONTINUOUS;
User_GPT_Cfg[0].channelTickFreq = 1000000U;
User_GPT_Cfg[0].gptNotification = &LedBlink();

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
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
void LedBlink (void)
{
    static uint16 counter;
    uint8 PinState;
    if (counter == 256)
    {
        PinState = Dio_ReadChannel(Channel_A0);
        if (PinState == 0) Port_Pin_Write(PORT_A,0,HIGH);
        else if (PinState == 1) Port_Pin_Write(PORT_A,0,LOW);
        counter = 0;
    }
    else
    {
        counter+=1;
    }
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/



/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

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

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
