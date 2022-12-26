/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic.h"
#include "mcu_hw.h"
#include "Nvic_cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define NVIC_GROUPING_SYSTEM_XXX 	4
#define	NVIC_GROUPING_SYSTEM_XXY 	5
#define	NVIC_GROUPING_SYSTEM_XYY 	6
#define	NVIC_GROUPING_SYSTEM_YYY 	7

#define APINT_VECTKEY 							0x05FA
#define APINT_VECTKEY_FIRLED_OFFSET				16u
#define PRIGROUP_FIELED_OFFSET					0x8u
#define NVIC_REG_NUM_OF_PRI_FIELDS				4u

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
* \Syntax          : Svoid NVIC_init(void)        
* \Description     : NVIC initialization                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : void
*******************************************************************************/
void NVIC_init(void)
{
	Nvic_IntType intNum;
	uint8 locGroup, locSubGroup,i,locGroupingField;
	uint32 enRegOffset, enBitOffset;
	uint32 priRegOffset, priBit , priReg;
	
	/* configure grouping and subgrouping int APINT register in SCB */
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIRLED_OFFSET)
					|(NVIC_GROUPING_SYSTEM << PRIGROUP_FIELED_OFFSET);
	
	for(i=0; i< NVIC_ACTIVATED_INT_SIZE ;i++)
	{
		intNum			= NVIC_Cfg[i].Interupt_Number;
		locGroup		= NVIC_Cfg[i].Group_Priority;
		locSubGroup = NVIC_Cfg[i].SubGroup_Priority;
		
		/* enable\disable based on user configuration */
		enRegOffset = (intNum/WORD_LENGTH_BITS);
		enBitOffset = intNum%WORD_LENGTH_BITS;
		
		switch (enRegOffset)
		{
		case 0/* constant-expression */:
			SetBit(NVIC_EN0,enBitOffset);
			break;
		case 1/* constant-expression */:
			SetBit(NVIC_EN1,enBitOffset);
			break;
		case 2/* constant-expression */:
			SetBit(NVIC_EN2,enBitOffset);
			break;
		case 3/* constant-expression */:
			SetBit(NVIC_EN3,enBitOffset);
			break;
		case 4/* constant-expression */:
			SetBit(NVIC_EN4,enBitOffset);
			break;
		
		default:
			break;
		}

		priRegOffset = ((intNum/4)*WORD_LENGTH_BYTES);
		priReg = *((uint32*)(priRegOffset + NVIC_PRI0_OFFSET));
		priBit = intNum%4;	
		

		
#if NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX
			locGroupingField = locGroup;
			/* create enum or array to hold all pri values , divide intNum by 4 to find which priX register is used ,
			 modulus intNum by 4 to find which Int of the 4 is used* , creae switch for 4 values with 4 offsets (bit shift) ,
			  write locGroupingField at those bits*/
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY
			locGroupingField = (locGroup<<1) | (locSubGroup);
			switch (priBit)
		{
		case 0:
			priReg |= locGroupingField<<5;
			break;
		case 1:
			priReg |= locGroupingField<<13;
			break;
		case 2:
			priReg |= locGroupingField<<21;
			break;
		case 3:
			priReg |= locGroupingField<<29;
			break;		
		default:
			break;
		}
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY
        locGroupingField = (locGroup<<2) | (locSubGroup);
		switch (priBit)
		{
		case 0:
			priReg |= locGroupingField<<5;
			break;
		case 1:
			priReg |= locGroupingField<<13;
			break;
		case 2:
			priReg |= locGroupingField<<21;
			break;
		case 3:
			priReg |= locGroupingField<<29;
			break;		
		default:
			break;
		}
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY
        locGroupingField = locGroup;
        switch (priBit)
		{
		case 0:
			priReg |= locGroupingField<<5;
			break;
		case 1:
			priReg |= locGroupingField<<13;
			break;
		case 2:
			priReg |= locGroupingField<<21;
			break;
		case 3:
			priReg |= locGroupingField<<29;
			break;		
		default:
			break;
		}
#else
     #error INVALID GROUPING SELECTION			
#endif
		
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/

