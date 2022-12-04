/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  -
 *
 *  Description:  DIO Header file
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "platform_Types.h"
#include "mcu_hw.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define Channel_A0			0
#define Channel_A1			1
#define Channel_A2			2
#define Channel_A3			3
#define Channel_A4			4
#define Channel_A5			5
#define Channel_A6			6
#define Channel_A7			7

#define Channel_B0			8
#define Channel_B1			9
#define Channel_B2			10
#define Channel_B3			11
#define Channel_B4			12
#define Channel_B5			13
#define Channel_B6			14
#define Channel_B7			15

#define Channel_C0			16
#define Channel_C1			17
#define Channel_C2			18
#define Channel_C3			19
#define Channel_C4			20
#define Channel_C5			21
#define Channel_C6			22
#define Channel_C7			23

#define Channel_D0			24
#define Channel_D1			25
#define Channel_D2			26
#define Channel_D3			27
#define Channel_D4			28
#define Channel_D5			29
#define Channel_D6			30
#define Channel_D7			31
				
#define Channel_E0			32
#define Channel_E1			33
#define Channel_E2			34
#define Channel_E3			35
#define Channel_E4			36
#define Channel_E5			37
#define Channel_E6			38
#define Channel_E7			39

#define Channel_F0			40
#define Channel_F1			41
#define Channel_F2			42
#define Channel_F3			43
#define Channel_F4			44
#define Channel_F5			45
#define Channel_F6			46
#define Channel_F7			47

typedef uint8 Dio_ChannelType;
typedef enum Dio_PortType_e{
	PORT_A          = 1U,
	PORT_B,         = 2U,
	PORT_C,         = 3U,
	PORT_D,         = 4U,
	PORT_E,         = 5U,
	PORT_F          = 6U,
}Dio_PortType_t;

typedef enum Dio_LevelType_e{
	STD_LOW         = 0U,
	STD_HIGH        = 1U
}Dio_LevelType_t;

typedef enum DIO_ResType_e
{
    PULL_UP         = 1U,
    PULL_DN         = 2U,
    OPEN_DRAIN      = 3U
}DIO_ResType_t

typedef enum DIO_CurrentDrive_e
{
    CURRENT_2_MA         = 1U,
    CURRENT_4_MA         = 2U,
    CURRENT_8_MA         = 3U
}DIO_CurrentDrive_t

typedef struct DIO_PadCfg
{
    DIO_ResType_t       DIO_ResType;
    DIO_CurrentDrive_t  DIO_CurrentDrive;
    /* data */
};


typedef uint8 Dio_PortLevelType;	//input from 0 to 255



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Dio_LevelType_t Dio_ReadChannel ( Dio_ChannelType ChannelId );
Std_ReturnType Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType_t Level );
Dio_PortLevelType Dio_ReadPort ( Dio_PortType_t PortId );
Std_ReturnType Dio_WritePort ( Dio_PortType_t PortId, Dio_PortLevelType Level );
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

void Bit_Band_Set_Pin(uint32* Bit_Word_Addr);
void Bit_Band_Reset_Pin(uint32* Bit_Word_Addr);
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
