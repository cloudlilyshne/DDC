

#ifndef _INTVECS_H_
#define _INTVECS_H_

#define EEPROM_Byte_counts 1191788

#define Erase_command_length 5




typedef enum
{
	Flash_Idle,	
	Flash_Erase,
	Flash_Write,							
	Flash_Process_End
}Flash_Process_T;


typedef struct
{ 
	Flash_Process_T Flash_Process:8;
	//uint8 SPI_Read_Data;
	bool Erase_OK:1;
	uint32 data_counts_Total;
	//unsigned char config_done;
	//unsigned char nstatus:1;
	//unsigned char nce:1;
	//unsigned char nceo:1;
}Flash_Data_T;

#endif

