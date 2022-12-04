/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "platform_Types.h"
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum Gpt_ChannelType_e
{
	GPT_16_32_BIT_TIMER0,
	GPT_16_32_BIT_TIMER1,
	GPT_16_32_BIT_TIMER2,
	GPT_16_32_BIT_TIMER3,
	GPT_16_32_BIT_TIMER4,
	GPT_16_32_BIT_TIMER5,
	GPT_32_64_BIT_WIDE_TIMER0,
	GPT_32_64_BIT_WIDE_TIMER1,
	GPT_32_64_BIT_WIDE_TIMER2,
	GPT_32_64_BIT_WIDE_TIMER3,
	GPT_32_64_BIT_WIDE_TIMER4,
	GPT_32_64_BIT_WIDE_TIMER5
}Gpt_ChannelType_t; 

typedef uint32 Gpt_ValueType_t; /*type for reading and writing timer values in number of ticks*/

typedef enum Gpt_ModeType_e
{
	GPT_MODE_NORMAL,
	GPT_MODE_SLEEP 
} Gpt_ModeType_t;

typedef enum Gpt_PredefTimerType_e
{
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType_t;

typedef uint32 Gpt_ChannelTickFrequency_t;
typedef uint32 GptChannelTickValueMax_t;

typedef enum ChannelMode_e
{
	GPT_CH_MODE_CONTINUOUS,
	GPT_CH_MODE_ONESHOT
}ChannelMode_t;

typedef void(*GptNotification)(void);

typedef struct Gpt_ConfigType_s
{
	Gpt_ChannelType_t  					channel;
	/* Gpt_ChannelTickFrequency_t       channelTickFreq;*/
	GptChannelTickValueMax_t  	        channelTickMaxValue;
	ChannelMode_t						channelMode;
	GptNotification						gptNotification;
}Gpt_ConfigType_t;

#define PREDEF_TIMERS_INT_SIZE   4

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr);
/******************************************************************************
* \Syntax          : void Gpt_DisableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : void Gpt_EnableNotification( Gpt_ChannelType Channel )        
* \Description     : Enables the interrupt notification for a channel (relevant in normal mode).                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : Gpt_GetTimeElapsed( Gpt_ChannelType Channel )        
* \Description     : Returns the time already elapsed.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): Gpt_ValueType                                                      
* \Return value:   : Gpt_ValueType  uint32                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );

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
Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);
/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )       
* \Description     : Returns the time remaining until the target time is reached.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  uint32                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );
/******************************************************************************
* \Syntax          : void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );        
* \Description     : Starts a timer channel.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant(but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel. 
*										 Value		 Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );

/******************************************************************************
* \Syntax          : void Gpt_StopTimer( Gpt_ChannelType Channel )       
* \Description     : Stops a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                           
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel );
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
void Gpt_Notification_Channel ( void);
 
#endif  /* TIMER_H */

/**********************************************************************************************************************
 *  END OF FILE: Timer.h
 *********************************************************************************************************************/
