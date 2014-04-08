

#ifndef _DDC_H_
#define _DDC_H_
#include "DDCCI.h"

#define Brightness_Valid  100
#define Contrast_Valid  0xFF00
#define Brightness_Default  50
#define Contrast_Default  0x32

#define PWM_Hz_High 16*10 //250K
#define PWM_Hz_Low 32*10   //100K
#define PWM_Duty_High 0x5fff
#define PWM_Duty_Low 0x5fff



#define PWM_DUTY_VALUE  2400

#ifdef msp430f5505
#define Brigntness_PWM_Control( val )    TA1CCR0 = PWM_DUTY_VALUE;TA1CCR1 = val*(PWM_DUTY_VALUE/100)
#else
#define Brigntness_PWM_Control( val )    TA1CCR0 = PWM_DUTY_VALUE;TA1CCR1 = val*(PWM_DUTY_VALUE/100)
#endif

typedef struct 
{

    unsigned char            counts;
 
    unsigned char  *buf;   //read src address

} DDC_REV_T;


typedef struct 
{

    unsigned char            counts;
    
    unsigned char  *buf;   //read src address

} DDC_SEND_T;


enum
{
	F_BUSY=0x01,//read
	F_WEL=0x02,    //Chip-Erase
	F_BP0=0x04, //Auto Address Increment Programming
	F_BP1=0x08,//Read-Status-Register  
	F_BP2=0x10, //Enable-Write-Status-Register
	F_BP3=0x20,  //Write-Status-Register
	F_AAI=0x40,	//Write-Enable
	F_BPL=0x80

};

typedef enum
{
      DDC_Data_init,
       DDC_EDID_Data_Rev,
       DDC_EDID_Data_Complete,       
	DDC_Data_Rev,		
	DDC_Data_Rev_Handle,		
	DDC_Data_Send,
	DDC_Process_End
	
}DDC_Process_T;


typedef struct
{ 
	DDC_Process_T DDC_Process:8;


	DDC_REV_T ddc_rev;
	DDC_SEND_T ddc_send;

	uint8 DDC_rev_buf[DDCCI_MSG_SZ*2];
	uint8 DDC_send_buf[DDCCI_MSG_SZ*2];
	uint16 BrigntNess_Valule;
	uint16 Contrast_Valule;        
}DDC_Data_T;



void DDC_init(void);

void DDC_Process(fsjigTaskData* app);

#endif
