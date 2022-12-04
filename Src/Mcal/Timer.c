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
#include "Timer_Cfg.h"
#include "Timer.h"
#include "mcu_hw.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MAX_NUMBER_OF_GPIO_GPT 		12u

#define TAEN 		0
#define TBEN 		8

#define TACDIR	4

#define PREDEF_TIMER					GPT_32_64_BIT_WIDE_TIMER4
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
GptNotification	locGptNotification[MAX_NUMBER_OF_GPIO_GPT];


static volatile uint32 gptPredefTimer_1USPrescale;
static volatile uint32 gptPredefTimer_100US_32BitPrescale;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Gpt_ConfigType_t*			globalGptConfig;

extern volatile uint32 GlobalSystemClock;
static const uint32 Gpt_BaseAddress[MAX_NUMBER_OF_GPIO_GPT] = {GPT_16_32_BIT_TIMER0_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER1_BASE_ADDRESS,		
	                                                           GPT_16_32_BIT_TIMER2_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER3_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER4_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER5_BASE_ADDRESS,			
	                                                           GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS};
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
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType_t* ConfigPtr)
{
	uint32 i,prescale;
	uint32 										gptBaseAddress;
	Gpt_ChannelType_t 							channel;
	ChannelMode_t								locChannelMode;
	Gpt_ChannelTickFrequency_t 					locChannelTickFreq;
	GptChannelTickValueMax_t					locChannelTickMaxValue;
	globalGptConfig = ConfigPtr;
	
	for(i=0;i<GPT_ACTIVATED_CHANNELS_SIZE;i++)
	{
		channel								= ConfigPtr[i].channel;
		locChannelTickFreq				= ConfigPtr[i].channelTickFreq;
		locChannelTickMaxValue		= ConfigPtr[i].channelTickMaxValue;
		locChannelMode						= ConfigPtr[i].channelMode;
		
		locGptNotification[channel]= ConfigPtr[i].gptNotification;
		
		gptBaseAddress = Gpt_BaseAddress[channel];
		GPTMCTL(gptBaseAddress) =	0;
		
		/*
		* For a 16/32-bit timer, this value selects the 16-bit timer configuration.
		* For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.
		*/
		GPTMCFG(gptBaseAddress) = 0x4;
		
		/* counting up */
		GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);
		
		/* channel mode */
		if (locChannelMode == GPT_CH_MODE_ONESHOT)
		{
			GPTMTAMR(gptBaseAddress) |= 0x1;
		}
		else if (locChannelMode == GPT_CH_MODE_CONTINUOUS)
		{
			GPTMTAMR(gptBaseAddress) |= 0x2; 
		}
		
		/* Disablling interupt notifation */
		Gpt_DisableNotification(channel);
	}		
	
		
}


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
void Gpt_DisableNotification( Gpt_ChannelType_t Channel )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMIMR(gptBaseAddress) = 0;
}
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
void Gpt_EnableNotification( Gpt_ChannelType_t Channel )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMIMR(gptBaseAddress) = 0x1;
}


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
void Gpt_StartTimer( Gpt_ChannelType_t Channel, Gpt_ValueType_t Value )
{
	uint32 							i;
	uint32 							prescale;
	uint32 							gptBaseAddress;
	Gpt_ChannelTickFrequency_t 		locChannelTickFreq;
	/*get tick frequency from corresponding channel*/
	gptBaseAddress = Gpt_BaseAddress[Channel];
		for(i=0;i<MAX_NUMBER_OF_GPIO_GPT;i++)
	{
		if (globalGptConfig[i].channel == Channel)
		{
			locChannelTickFreq = globalGptConfig[i].channelTickFreq;			
			break;
		}
	}
	/*calculate required prescale value*/
	prescale = GlobalSystemClock / locChannelTickFreq;
	/*calculate the timer starting value*/
	for(i=2;;i*=2)
	{
		if(prescale/i == 1)
		{
			if(prescale%i <= (i/2))
			{
				prescale = i;
			}
			else
			{
				prescale = i*2;
			}
			break;
		}
	}
	/* setting upper bound for timeout event*/
	GPTMTAILR(gptBaseAddress) = Value * prescale;
	GPTMCTL(gptBaseAddress) |= (1<<TAEN);

}

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
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	
	GPTMCTL(gptBaseAddress) &= (~(1<<TAEN));
}



void TIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_16_32_BIT_TIMER0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_16_32_BIT_TIMER0];
		gptNotificationFn_TIMER0A();
	}
}

void TIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER1A;
	if (locGptNotification[GPT_16_32_BIT_TIMER1] != NULL)
	{
		gptNotificationFn_TIMER1A = locGptNotification[GPT_16_32_BIT_TIMER1];
		gptNotificationFn_TIMER1A();
	}
}

void TIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER2A;
	if (locGptNotification[GPT_16_32_BIT_TIMER2] != NULL)
	{
		gptNotificationFn_TIMER2A = locGptNotification[GPT_16_32_BIT_TIMER2];
		gptNotificationFn_TIMER2A();
	}
}

void TIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER3A;
	if (locGptNotification[GPT_16_32_BIT_TIMER3] != NULL)
	{
		gptNotificationFn_TIMER3A = locGptNotification[GPT_16_32_BIT_TIMER3];
		gptNotificationFn_TIMER3A();
	}
}

void TIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER4A;
	if (locGptNotification[GPT_16_32_BIT_TIMER4] != NULL)
	{
		gptNotificationFn_TIMER4A = locGptNotification[GPT_16_32_BIT_TIMER4];
		gptNotificationFn_TIMER4A();
	} 
}

void TIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_TIMER5A;
	if (locGptNotification[GPT_16_32_BIT_TIMER5] != NULL)
	{
		gptNotificationFn_TIMER5A = locGptNotification[GPT_16_32_BIT_TIMER5];
		gptNotificationFn_TIMER5A();
	}
}

void WTIMER0A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER0A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER0] != NULL)
	{
		gptNotificationFn_WTIMER0A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER0];
		gptNotificationFn_WTIMER0A();
	}
}

void WTIMER1A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER1A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER1] != NULL)
	{
		gptNotificationFn_WTIMER1A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER1];
		gptNotificationFn_WTIMER1A();
	}
}

void WTIMER2A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER2A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER2] != NULL)
	{
		gptNotificationFn_WTIMER2A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER2];
		gptNotificationFn_WTIMER2A();
	}
}

void WTIMER3A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER3A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER3] != NULL)
	{
		gptNotificationFn_WTIMER3A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER3];
		gptNotificationFn_WTIMER3A();
	}
}

void WTIMER4A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER4A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER4] != NULL)
	{
		gptNotificationFn_WTIMER4A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER4];
		gptNotificationFn_WTIMER4A();
	}
}

void WTIMER5A_Handler(void)
{
	static GptNotification gptNotificationFn_WTIMER5A;
	if (locGptNotification[GPT_32_64_BIT_WIDE_TIMER5] != NULL)
	{
		gptNotificationFn_WTIMER5A = locGptNotification[GPT_32_64_BIT_WIDE_TIMER5];
		gptNotificationFn_WTIMER5A();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
