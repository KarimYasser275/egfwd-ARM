/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
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
#include "C:\KarimYasser\egfwd\Prj1\Workspace\egfwd-ARM\Src\HAL\DIO\Inc\DIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define GPIO_BIT_BAND_BASE                                      (volatile uint32*)(0x40000000)
#define SetBit(Port,Channel)                                    Port|=(1<<Channel)   
#define ResetBit(Port,Channel)                                  Port&=~(1<<Channel)     
#define TogglePin(Port,Channel)                                 Port^=(1<<Channel) 
                

#define bit_word_addr(bit_band_base,byte_offset,bit_number)    (uint32*)(bit_band_base+(byte_offset*32)+(bit_number*4))
// Example : bit_word_addr(GPIO_APB_BASE_ADDRESS_A,GPIO_APB_BASE_ADDRESS_OFFSET_A,1) --> returns DIO port A pin number 1 bit word address alias

/*where:
bit_word_addr
The address of the word in the alias memory region that maps to the targeted bit.
bit_band_base
The starting address of the alias region.
byte_offset
The number of the byte in the bit-band region that contains the targeted bit.
bit_number
The bit position, 0-7, of the targeted bit.
*/

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
* \Syntax          : void Bit_Band_Set_Pin(uint32* Bit_Word_Addr)       
* \Description     :Sets Bit in Bit Band Alias Word 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : uint32* Bit_Word_Addr (bit_word_addr(bit_band_base,byte_offset,bit_number))                                                        
* \Return value:   : Void,
																		                               
*******************************************************************************/
void Bit_Band_Set_Pin(uint32* Bit_Word_Addr)  
{
    *Bit_Word_Addr=0x01;
}

/******************************************************************************
* \Syntax          : void Bit_Band_Reset_Pin(uint32* Bit_Word_Addr)       
* \Description     :Resets Bit in Bit Band Alias Word 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : uint32* Bit_Word_Addr (bit_word_addr(bit_band_base,byte_offset,bit_number))                                                        
* \Return value:   : Void,
																		                               
*******************************************************************************/
void Bit_Band_Reset_Pin(uint32* Bit_Word_Addr)  
{
    *Bit_Word_Addr=0x00;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Reads channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                     
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType  STD_LOW,
																		 STD_HIGH                                  
*******************************************************************************/
Dio_LevelType_t Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
	Dio_ChannelType dio_channel = ChannelID/8;
    Dio_PortLevelType port_reading;
    u8 dio_reading;
    dio_Reading
    switch (dio_channel)
    {
    case: 0/* constant-expression */:
        port_reading = GPIODATA(GPIO_APB_BASE_ADDRESS_A)
        break;
    case: 1/* constant-expression */:
        port_reading = GPIODATA(GPIO_APB_BASE_ADDRESS_B)
        break;
    case: 2/* constant-expression */:
        port_reading = GPIODATA(GPIO_APB_BASE_ADDRESS_C)
    break;
    case: 3/* constant-expression */:
        port_reading = GPIODATA(GPIO_APB_BASE_ADDRESS_D)
    break;
    case: 4/* constant-expression */:
        port_reading = GPIODATA(GPIO_APB_BASE_ADDRESS_E)
    break;
    case: 5/* constant-expression */:
        port_reading = GPIODATA(GPIO_APB_BASE_ADDRESS_F)
    break;
    }
    dio_Reading = (port_reading>>(ChannelID%8))&1;
    return dio_reading;
}
/******************************************************************************
* \Syntax          : void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )        
* \Description     : Writes channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
Std_ReturnType Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType_t Level )
{
	Std_ReturnType state = E_OK;
    Dio_ChannelType dio_channel = ChannelID/8;
    uint8 dio_bit = dio_channel%8;
    switch (dio_channel)
    {
    case 0:
        if (Level == STD_LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_A,dio_bit));
        else if (Level == STD_HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_A,dio_bit));
        else state = E_NOT_OK;
        break;
    case:1:
        if (Level == STD_LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_B,dio_bit));
        else if (Level == STD_HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_B,dio_bit));
        else state = E_NOT_OK;
        break;
    case 2:
        if (Level == STD_LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_C,dio_bit));
        else if (Level == STD_HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_C,dio_bit));
        else state = E_NOT_OK;
        break;
    case 3:
        if (Level == STD_LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_D,dio_bit));
        else if (Level == STD_HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_D,dio_bit));
        else state = E_NOT_OK;
        break;
    case 4:
        if (Level == STD_LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_E,dio_bit));
        else if (Level == STD_HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_E,dio_bit));
        else state = E_NOT_OK;
        break;
    case 5:
        if (Level == STD_LOW) Bit_Band_Reset_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_F,dio_bit));
        else if (Level == STD_HIGH) Bit_Band_Set_Pin(bit_word_addr(GPIO_APB_BASE_ADDRESS,GPIO_APB_BASE_ADDRESS_OFFSET_F,dio_bit));
        else state = E_NOT_OK;
        break;
    default:
        state = E_NOT_OK;
        break;
    }
    return state;
}
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )       
* \Description     : Reads Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port                    
* \Parameters (out): Dio_PortLevelType                                                      
* \Return value:   : Dio_PortLevelType   uint8                                  
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort ( Dio_PortType_t PortId )
{
	
    Dio_PortLevelType dio_port_level;
    switch (PortId)
    {
    case: 1/* constant-expression */:
        dio_port_level = GPIODATA(GPIO_APB_BASE_ADDRESS_A)
        break;
    case: 2/* constant-expression */:
        dio_port_level = GPIODATA(GPIO_APB_BASE_ADDRESS_B)
        break;
    case: 3/* constant-expression */:
        dio_port_level = GPIODATA(GPIO_APB_BASE_ADDRESS_C)
    break;
    case: 4/* constant-expression */:
        dio_port_level = GPIODATA(GPIO_APB_BASE_ADDRESS_D)
    break;
    case: 5/* constant-expression */:
        dio_port_level = GPIODATA(GPIO_APB_BASE_ADDRESS_E)
    break;
    case: 6/* constant-expression */:
        dio_port_level = GPIODATA(GPIO_APB_BASE_ADDRESS_F)
    break;
    }
    return dio_port_level;

}
/******************************************************************************
* \Syntax          : void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );       
* \Description     : writes Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port
										 Level  	Value to be written                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
Std_ReturnType Dio_WritePort ( Dio_PortType_t PortId, Dio_PortLevelType Level )
{
    Std_ReturnType state = E_OK;
    switch (PortId)
    {
    case: 1/* constant-expression */:
        GPIODATA(GPIO_APB_BASE_ADDRESS_A) = Level;
        break;
    case: 2/* constant-expression */:
        GPIODATA(GPIO_APB_BASE_ADDRESS_B) = Level;
        break;
    case: 3/* constant-expression */:
         GPIODATA(GPIO_APB_BASE_ADDRESS_C) = Level;
    break;
    case: 4/* constant-expression */:
         GPIODATA(GPIO_APB_BASE_ADDRESS_D) = Level;
    break;
    case: 5/* constant-expression */:
         GPIODATA(GPIO_APB_BASE_ADDRESS_E) = Level;
    break;
    case: 6/* constant-expression */:
         GPIODATA(GPIO_APB_BASE_ADDRESS_F) = Level;
    break;
    default:
        state = E_NOT_OK
    }
    return state;

}
/******************************************************************************
* \Syntax          : void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );       
* \Description     : writes Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                   
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType	STD_LOW,
																		STD_HIGH                                 
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Std_ReturnType state = E_OK;
    Dio_ChannelType dio_channel = ChannelID/8;
    uint8 dio_bit = dio_channel%8;
    switch (dio_channel)
    {
    case 0:
        TogglePin(GPIODATA(GPIO_APB_BASE_ADDRESS_A),dio_bit);
        break;
    case:1:
        TogglePin(GPIODATA(GPIO_APB_BASE_ADDRESS_A),dio_bit);
        break;
    case 2:
       TogglePin(GPIODATA(GPIO_APB_BASE_ADDRESS_A),dio_bit);
        break;
    case 3:
        TogglePin(GPIODATA(GPIO_APB_BASE_ADDRESS_A),dio_bit);
        break;
    case 4:
        TogglePin(GPIODATA(GPIO_APB_BASE_ADDRESS_A),dio_bit);
        break;
    case 5:
        TogglePin(GPIODATA(GPIO_APB_BASE_ADDRESS_A),dio_bit);
        break;
    default:
        state = E_NOT_OK;
        break;
    }



}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
