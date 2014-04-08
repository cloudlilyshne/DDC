

#ifndef _FSJIG_PRIVATE_H_
#define _FSJIG_PRIVATE_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>



typedef int bool;

#define TRUE  (!0)
#define FALSE  0

//#define Debug_mode

typedef unsigned int uint; 

typedef unsigned char uint8;

typedef unsigned short uint16;



typedef unsigned long uint32;

/*

0x6E:
01101110

00110111


*/

#define I2C_EDID_Address 0x50
#define I2C_MONITOR_Address 0x37
#define I2C_AD9984_Address 0x4C


//#include "segment.h" 

//#include "i2cHandler.h"

//#include "nconfig.h" 



#define BACK_LIGHT_EN BIT0
#define BACK_LIGHT_ADJ BIT1
#define LCD_EN BIT2

#define Test_Pin BIT3
#define Test_Dir_OUT P2DIR |= Test_Pin;
#define Test_Exc P2OUT ^= Test_Pin;
#define Test_High P2OUT |= Test_Pin;
#define Test_Low P2OUT &= ~Test_Pin;

typedef enum
{
       BrightNESS_VALUE_HH,
       BrightNESS_VALUE_HL,
       Contrast_VALUE_HH,
       Contrast_VALUE_HL,       
	FLASH_WRITE_End
	
}FLASH_WRITE_OFFSET;

typedef enum
{
	FS_Input=0x01,
	TT_Input,							
	ECG_Input,
	Error_Input
}Device_T;


typedef enum
{
	ECG_Display,
	FS_Display,							
	Probe_Display,
	Error_Display,
	P_Ongoing_Display,
	P_Done_Display,
	USB_R_Display,	
	Number_Display,	
	Process_Display_End
}Segment_ID_T;

typedef struct
{
	uint16           TimeA_counts_1ms;
	uint16           Segment_Display_1ms;
	uint16	      P_Ongoing_100ms;
	uint16           Nconfig_Display_1ms;
	uint16           Probe_Reset_1ms;
	uint16           Probe_Poll_1ms;
}Timer_1ms_Counts_T;

typedef struct
{
	bool Time_1_ms_Mark :1; 
	bool Time_10_ms_Mark :1; 
	bool Time_100_ms_Mark :1;
	bool Time_1_s_Mark :1; 
	bool Time_10_s_Mark :1; 
	bool Time_60_s_Mark :1; 
} Time_intMark_T;


typedef struct
{
	Segment_ID_T Segment_ID;
	uint16              Segment_Data; 
} Segment_ID_Data_T;





typedef struct
{
	bool                mute:1;

	} fsjigTaskData;



/****************************************************************************
NAME    
    avGetApp
    
DESCRIPTION
  Returns system application state

RETURNS
    fsjigTaskData
*/
fsjigTaskData *getApp(void);
void   init_Globle(void);





#endif

