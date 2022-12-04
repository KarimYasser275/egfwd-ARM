/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union INTCTRL_Tag_u
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag_t;
INTCTRL_Tag_t INTCTRL_Tag



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GlobalSystemClock                      16000000U

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
/*NVIC Enable Registers*/
#define NVIC_EN0                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define NVIC_EN1                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define NVIC_EN2                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define NVIC_EN3                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define NVIC_EN4                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))
/*NVIC Priority Registers*/
#define NVIC_PRI0                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define NVIC_PRI1                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define NVIC_PRI2                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define NVIC_PRI3                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40c))
#define NVIC_PRI4                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define NVIC_PRI5                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define NVIC_PRI6                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define NVIC_PRI7                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41c))
#define NVIC_PRI8                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define NVIC_PRI9                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define NVIC_PRI10                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define NVIC_PRI11                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42c))
#define NVIC_PRI12                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define NVIC_PRI13                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define NVIC_PRI14                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define NVIC_PRI15                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43c))
#define NVIC_PRI16                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define NVIC_PRI17                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define NVIC_PRI18                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define NVIC_PRI19                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44c))
#define NVIC_PRI20                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define NVIC_PRI21                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define NVIC_PRI22                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define NVIC_PRI23                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45c))
#define NVIC_PRI24                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define NVIC_PRI25                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define NVIC_PRI26                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define NVIC_PRI27                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46c))
#define NVIC_PRI28                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define NVIC_PRI29                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define NVIC_PRI30                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define NVIC_PRI31                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47c))
#define NVIC_PRI32                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define NVIC_PRI33                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define NVIC_PRI34                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))
/*GPIO Register*/
#define GPIO_APB_BASE_ADDRESS_A                (volatile uint32*)(0x40004000)
#define GPIO_APB_BASE_ADDRESS_B                (volatile uint32*)(0x40005000)
#define GPIO_APB_BASE_ADDRESS_C                (volatile uint32*)(0x40006000)
#define GPIO_APB_BASE_ADDRESS_D                (volatile uint32*)(0x40007000)
#define GPIO_APB_BASE_ADDRESS_E                (volatile uint32*)(0x40024000)
#define GPIO_APB_BASE_ADDRESS_F                (volatile uint32*)(0x40025000)
#define GPIO_APB_BASE_ADDRESS                  (volatile uint32*)(0x40000000)
#define GPIO_APB_BASE_ADDRESS_OFFSET_A         (volatile uint32*)(0x00004000)
#define GPIO_APB_BASE_ADDRESS_OFFSET_B         (volatile uint32*)(0x00005000)
#define GPIO_APB_BASE_ADDRESS_OFFSET_C         (volatile uint32*)(0x00006000)
#define GPIO_APB_BASE_ADDRESS_OFFSET_D         (volatile uint32*)(0x00007000)
#define GPIO_APB_BASE_ADDRESS_OFFSET_E         (volatile uint32*)(0x00024000)
#define GPIO_APB_BASE_ADDRESS_OFFSET_F         (volatile uint32*)(0x00025000)
#define GPIODATA(Port_APB_BaseAddress)         *((volatile uint32*)(Port_APB_BaseAddres))
#define GPIODIR(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x400))
#define GPIOAFSEL(Port_APB_BaseAddress)        *((volatile uint32*)(Port_APB_BaseAddress+0x420))						
#define GPIOLOCK(Port_APB_BaseAddress)	       *((volatile uint32*)(Port_APB_BaseAddress+0x520))
#define GPIOCR(Port_APB_BaseAddress)           *((volatile uint32*)(Port_APB_BaseAddress+0x524))
#define GPIOPCTL(Port_APB_BaseAddress)	       *((volatile uint32*)(Port_APB_BaseAddress+0x52C))
#define GPIODR2R(Port_APB_BaseAddress)         *((volatile uint32*)(Port_APB_BaseAddress+0x500))
#define GPIODR4R(Port_APB_BaseAddress)         *((volatile uint32*)(Port_APB_BaseAddress+0x504))
#define GPIODR8R(Port_APB_BaseAddress)         *((volatile uint32*)(Port_APB_BaseAddress+0x508))
#define GPIOPUR(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x510))
#define GPIOPDR(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x514))
#define GPIOODR(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x50C))
#define GPIOIS(Port_APB_BaseAddress)	       *((volatile uint32*)(Port_APB_BaseAddress+0x404))
#define GPIOIBE(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x408))
#define GPIOIEV(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x40c))
#define GPIOIM(Port_APB_BaseAddress)	       *((volatile uint32*)(Port_APB_BaseAddress+0x410))
#define GPIORIS(Port_APB_BaseAddress)          *((volatile uint32*)(Port_APB_BaseAddress+0x414))


/* GPT REGISTERS */
#define GPT_16_32_BIT_TIMER0_BASE_ADDRESS							0x40030000
#define	GPT_16_32_BIT_TIMER1_BASE_ADDRESS							0x40031000
#define	GPT_16_32_BIT_TIMER2_BASE_ADDRESS							0x40032000
#define	GPT_16_32_BIT_TIMER3_BASE_ADDRESS							0x40033000
#define	GPT_16_32_BIT_TIMER4_BASE_ADDRESS							0x40034000
#define	GPT_16_32_BIT_TIMER5_BASE_ADDRESS							0x40035000
#define	GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS						0x40036000
#define	GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS						0x40037000
#define	GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS						0x4004C000
#define	GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS						0x4004D000
#define	GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS						0x4004E000
#define	GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS						0x4004F000

#define GPTMCFG_OFFSET					                            0x000
#define GPTMTAMR_OFFSET					                            0x004
#define GPTMTBMR_OFFSET					                            0x008
#define GPTMCTL_OFFSET					                            0x00C
#define GPTMIMR_OFFSET					                            0x018
#define GPTMTAV_OFFSET					                            0x050
#define GPTMTAILR_OFFSET				                            0x028
#define GPTMCFG(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMCFG_OFFSET))
#define GPTMTAMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAMR_OFFSET))
#define GPTMTBMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTBMR_OFFSET))
#define GPTMCTL(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMCTL_OFFSET))	
#define GPTMIMR(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMIMR_OFFSET))
#define GPTMTAV(BaseAddr)										*((volatile uint32*)(BaseAddr+GPTMTAV_OFFSET))
#define GPTMTAILR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAILR_OFFSET))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
