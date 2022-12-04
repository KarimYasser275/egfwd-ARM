/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
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
#include "Port.h"
#include "DIO.h"
#include"Port_Cfg.h"

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
Std_ReturnType Port_Channel_Dir(Dio_PortType_t port , uint8 channel , Port_PinDir_t direction)
{
    Std_ReturnType result = E_OK;
    uint32* Base_Address;
    switch (port)
    {
    case PORT_A :
        Base_Address = GPIO_APB_BASE_ADDRESS_A
        break;
    case PORT_B:
        Base_Address = GPIO_APB_BASE_ADDRESS_B
        break;
    case PORT_C:
        Base_Address = GPIO_APB_BASE_ADDRESS_C
        break;
    case PORT_D:
        Base_Address = GPIO_APB_BASE_ADDRESS_D
        break;
    case PORT_E:
        Base_Address = GPIO_APB_BASE_ADDRESS_E
        break;
    case PORT_F:
        Base_Address = GPIO_APB_BASE_ADDRESS_F
        break;
        
    default:
    result = E_NOT_OK;
        break;
    }
    switch (direction)
    {
    case OUTPUT:
        GPIODIR(Base_Address) |= (1<<channel); 
        break;
    case INPUT :
        GPIODIR(Base_Address) &= ~(1<<channel); 
        break;
    default:
        result = E_NOT_OK;
        break;
    }
    return result;
}


Std_ReturnType Port_Pin_Write (Dio_PortType_t port , uint8 channel , Port_PinLevel_t Level )
{
	Std_ReturnType state = E_OK;
    switch (port)
    {
    case PORT_A:
        if (Level == LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_A,dio_bit));
        else if (Level == HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_A,dio_bit));
        else state = E_NOT_OK;
        break;
    case PORT_B:
        if (Level == LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_B,dio_bit));
        else if (Level == HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_B,dio_bit));
        else state = E_NOT_OK;
        break;
    case PORT_C:
        if (Level == LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_C,dio_bit));
        else if (Level == HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_C,dio_bit));
        else state = E_NOT_OK;
        break;
    case PORT_D:
        if (Level == LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_D,dio_bit));
        else if (Level == HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_D,dio_bit));
        else state = E_NOT_OK;
        break;
    case PORT_E:
        if (Level == LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_E,dio_bit));
        else if (Level == HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_E,dio_bit));
        else state = E_NOT_OK;
        break;
    case PORT_F:
        if (Level == LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_F,dio_bit));
        else if (Level == HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_F,dio_bit));
        else state = E_NOT_OK;
        break;
    default:
        state = E_NOT_OK;
        break;
    }
    return state;
}

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
void Port_Init(void)
{
    /*Port A initialization from configuration*/
    for (uint8 i=0;i<8;i++)
    {
        Port_Channel_Dir(PORT_A ,i ,Port_Config_A[i].Port_PinDir);
        Std_ReturnType Port_Pin_Write ( PORT_A ,i ,Port_Config_A[i].Port_PinLevel );
    }
    
    /*Port B initialization from configuration*/
    for (uint8 i=0;i<8;i++)
    {
        Port_Channel_Dir(PORT_B ,i ,Port_Config_B[i].Port_PinDir);
        Std_ReturnType Port_Pin_Write ( PORT_B ,i ,Port_Config_B[i].Port_PinLevel );
    }


    /*Port C initialization from configuration*/
    for (uint8 i=0;i<8;i++)
    {
        Port_Channel_Dir(PORT_C ,i ,Port_Config_C[i].Port_PinDir);
        Std_ReturnType Port_Pin_Write ( PORT_C ,i ,Port_Config_C[i].Port_PinLevel );
    }

    /*Port D initialization from configuration*/
    for (uint8 i=0;i<8;i++)
    {
        Port_Channel_Dir(PORT_D ,i ,Port_Config_D[i].Port_PinDir);
        Std_ReturnType Port_Pin_Write ( PORT_D ,i ,Port_Config_D[i].Port_PinLevel );
    }

}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
/*
    loop through all pins of Port






*/