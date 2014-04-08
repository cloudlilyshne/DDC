#include "private.h" 
#include "ddc.h"
#include "flash.h"

/*
11:46:34.517BD...GetCaps - segment 0x0000:0
11:46:34.548BE.....[S] <6E:w> 51 83 F3 00 00 4F [P]
11:46:34.719BF.....[S] <6F:r> 6E A3 E3 00 00 28 70 72 6F 74 28 6D 6F 6E 69 74 6F 72 29 74 79 70 65 28 4C 43 44 29 6D 6F 64 65 6C 28 55 32 32 62*[P]
11:46:34.860C0...GetCaps - segment 0x0020:0
11:46:34.875C1.....[S] <6E:w> 51 83 F3 00 20 6F [P]
11:46:35.047C2.....[S] <6F:r> 6E A3 E3 00 20 31 32 48 4D 29 63 6D 64 73 28 30 31 20 30 32 20 30 33 20 30 37 20 30 43 20 45 33 20 46 33 29 76 68*[P]
11:46:35.187C3...GetCaps - segment 0x0040:0
11:46:35.203C4.....[S] <6E:w> 51 83 F3 00 40 0F [P]
11:46:35.375C5.....[S] <6F:r> 6E A3 E3 00 40 63 70 28 30 32 20 30 34 20 30 35 20 30 36 20 30 38 20 30 45 20 31 30 20 31 32 20 31 34 28 30 34 56*[P]
11:46:35.515C6...GetCaps - segment 0x0060:0
11:46:35.531C7.....[S] <6E:w> 51 83 F3 00 60 2F [P]
11:46:35.702C8.....[S] <6F:r> 6E A3 E3 00 60 20 30 35 20 30 36 20 30 38 20 30 39 20 30 42 20 30 43 29 20 31 36 20 31 38 20 31 41 20 31 45 20 1E*[P]
11:46:35.843C9...GetCaps - segment 0x0080:0
11:46:35.858CA.....[S] <6E:w> 51 83 F3 00 80 CF [P]
11:46:36.030CB.....[S] <6F:r> 6E A3 E3 00 80 32 30 20 33 30 20 33 45 20 35 32 20 36 30 28 30 31 20 30 33 20 30 46 29 20 41 41 28 30 31 20 30 E4*[P]
11:46:36.170CC...GetCaps - segment 0x00A0:0
11:46:36.186CD.....[S] <6E:w> 51 83 F3 00 A0 EF [P]
11:46:36.357CE.....[S] <6F:r> 6E A3 E3 00 A0 32 29 20 41 43 20 41 45 20 42 32 20 42 36 20 43 36 20 43 38 20 43 39 20 44 36 28 30 31 20 30 34 CC*[P]
11:46:36.498CF...GetCaps - segment 0x00C0:0
11:46:36.513D0.....[S] <6E:w> 51 83 F3 00 C0 8F [P]
11:46:36.685D1.....[S] <6F:r> 6E A3 E3 00 C0 20 30 35 29 20 44 43 28 30 30 20 30 32 20 30 33 20 30 35 29 20 44 46 20 45 30 20 45 31 20 46 30 C5*[P]
11:46:36.825D2...GetCaps - segment 0x00E0:0
11:46:36.841D3.....[S] <6E:w> 51 83 F3 00 E0 AF [P]
11:46:37.013D4.....[S] <6F:r> 6E A3 E3 00 E0 20 46 44 29 6D 73 77 68 71 6C 28 31 29 61 73 73 65 74 5F 65 65 70 28 34 30 29 6D 63 63 73 5F 76 D4*[P]
11:46:37.153D5...GetCaps - segment 0x0100:0
11:46:37.169D6.....[S] <6E:w> 51 83 F3 01 00 4E [P]
11:46:37.309D7.....[S] <6F:r> 6E 8C E3 01 00 65 72 28 32 2E 31 29 29 00 42*[P]
11:46:37.465D8...GetCaps - segment 0x0109:0
11:46:37.481D9.....[S] <6E:w> 51 83 F3 01 09 47 [P]
11:46:37.621DA.....[S] <6F:r> 6E 83 E3 01 09 56*[P]
static const char CAPABILITIES_REACT[128] = 
"(prot(monitor)
type(LCD)
model(U2212HM)
cmds(01 02 03 07 0C E3 F3)
vcp(02 04 05 06 08 0E 10 12 14(04 05 06 08 09 0B 0C) 16 18 1A 1E 20 30 3E 52 60(01 03 0F) AA(01 02) AC AE B2 B6 C6 C8 C9 D6(01 04 05) DC(00 02 03 05) DF E0 E1 F0 FD)
mswhql(1)
asset_eep(40)
mccs_ver(2.1))";
*/

//static const char CAPABILITIES_REACT[] = "(prot(monitor)type(LCD)model(U2212HM)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0E 10 12 14(04 05 06 08 09 0B 0C) 16 18 1A 1E 20 30 3E 52 60(01 03 0F) AA(01 02) AC AE B2 B6 C6 C8 C9 D6(01 04 05) DC(00 02 03 05) DF E0 E1 F0 FD)mswhql(1)asset_eep(40)mccs_ver(2.1))";
/*
"(prot(monitor)
type(LCD)
model(E2010H)
cmds(01 02 03 07 0C E3 F3)
vcp(02 04 05 06 08 10 12 14(01 05 08 0B 0C) 16 18 1A 60(01 03) AC AE B2 B6 C6 C8 C9 D6(01 04 05) DC(00 02 03 04 05 06) DF FD FF)
mswhql(1)
asset_eep(40)
mccs_ver(2.1))";
*/
static const char CAPABILITIES_REACT[] = "(prot(monitor)type(LCD)model(TCT KDR18.5)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 10 12 14(01 05 08 0B 0C) 16 18 1A 60(01 03))mswhql(1)asset_eep(40)mccs_ver(2.1))";
static const uint8 EDID_CONTEXT[] = 
{
//header
0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,
//ID Manufacturer name(2 bytes)
0x50,0x74,
//ID Product code(2 bytes)
0x01,0x22,
//ID Serial number (4 bytes)
0x01,0x00,0x00,0x00,
//Week of Manufacture£¨1byte£©
0x15,
//Year of manufacture (1byte)
0x16,
//EDID Structure Version/Revision(2 bytes)
0x01,0x03,
//£¨5bytes£©--- Basic Display Parameters/Features
//Video input para
0x80,
//image seze
0x30,0x1B,
//gamma
0x78,
//DPMS
0xEA,
//(10 bytes)--- color Characteristics
0x7C,0xA5,0xA3,0x54,0x4E,0xA0,0x27,0x12,0x50,0x54,
//Timing(3bytes)--- Established Timing
0xA5,0x4B,0x00,
//Timing (16 bytes)--- Standard Timing Identification
0x71,0x4F,0x81,0x80,0xD1,0xC0,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
//(72 bytes)--- Detailed Timing Description
0x02,0x3A,
0x80,0x18,0x71,0x38,0x2D,0x40,0x58,0x2C,
0x45,0x00,0xDB,0x0B,0x11,0x00,0x00,0x1E,
0x00,0x00,
0x00,0xFF,0x00,0x4B,0x4E,0x35,0x39,0x58,
0x31,0x38,0x53,0x30,0x47,0x57,0x4C,0x0A,
0x00,0x00,
0x00,0xFC,0x00,0x4B,0x44,0x52,0x32,0x31,
0x2E,0x35,0x0A,0x20,0x20,0x20,0x20,0x20,
0x00,0x00,
0x00,0xFD,0x00,0x38,0x4C,0x1E,0x53,0x11,
0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,
//Checksum (2 bytes)--- Extension Flag and Checksum
0x00,0x73,
};

static const uint8 REACT_ORDER[]=
{
	DDCCI_MCCS_SEC_DEGARSS,
	DDCCI_MCCS_RESTORE_FACTORY,
	DDCCI_MCCS_RESTORE_FACTORY_RESERVE,
	DDCCI_MCCS_RESTORE_FACTORY_GEORMETRY,
	DDCCI_MCCS_RESTORE_FACTORY_COLOR,
	DDCCI_MCCS_BRIGHTNESS,
	DDCCI_MCCS_CONTRAST,
	DDCCI_MCCS_SELECT_COLOR_PRESET,
	DDCCI_MCCS_RED_VIDEO_GAIN,
	DDCCI_MCCS_GREEN_VIDEO_GAIN,
	DDCCI_MCCS_BLUE_VIDEO_GAIN,
	DDCCI_MCCS_INPUT_SOURCE_SECECT
};

static const uint8 REACT_MESSAGE[][7]=
{
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_SEC_DEGARSS,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x02,0x00,0x01},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_RESTORE_FACTORY,VCP_TYPE_CODE_MOMENTARY,0x00,0x01,0x00,0x00},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_RESTORE_FACTORY_RESERVE,VCP_TYPE_CODE_MOMENTARY,0x00,0x01,0x00,0x00},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_RESTORE_FACTORY_GEORMETRY,VCP_TYPE_CODE_MOMENTARY,0x00,0x01,0x00,0x00},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_RESTORE_FACTORY_COLOR,VCP_TYPE_CODE_MOMENTARY,0x00,0x01,0x00,0x00},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_BRIGHTNESS,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x64,0x00,0x32},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_CONTRAST,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x64,0x00,0x2D},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_SELECT_COLOR_PRESET,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x0C,0x00,0x05},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_RED_VIDEO_GAIN,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x64,0x00,0x64},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_GREEN_VIDEO_GAIN,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x64,0x00,0x64},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_BLUE_VIDEO_GAIN,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x64,0x00,0x64},
	{VCP_RESULT_CODE_NOERROR,DDCCI_MCCS_INPUT_SOURCE_SECECT,VCP_TYPE_CODE_SET_PATAMETER,0x00,0x03,0x00,0x03}
};


static const uint8 TIMEING_REACT[] = {DDCCI_TIMING_SS,DDCCI_TIMING_HH,DDCCI_TIMING_HL,DDCCI_TIMING_VH,DDCCI_TIMING_VL};


static DDC_Data_T DDC_Data;
static void Send_Null_Message(void);
//static const uint16 test_value[17]={2400,2300,2200,2100,2000,1900,1800,1700,1600,1500,1400,1300,1200,1100,1000,900,800};
void DDC_init(void)
{
        DDC_Data.ddc_rev.buf=DDC_Data.DDC_rev_buf;
        DDC_Data.ddc_send.buf=DDC_Data.DDC_send_buf;
        DDC_Data.ddc_rev.counts=0;
        DDC_Data.ddc_send.counts=0;
		 DDC_Data.DDC_Process=DDC_EDID_Data_Complete;		

  
}
static void DDC_Parameter_Load(void)
{

      char *Flash_ptrC;
      Flash_ptrC = (char *) 0x1880;             // Initialize Flash segment C ptr
      DDC_Data.BrigntNess_Valule=(*(Flash_ptrC + BrightNESS_VALUE_HH)<<8) + *(Flash_ptrC + BrightNESS_VALUE_HL);

      if(DDC_Data.BrigntNess_Valule>Brightness_Valid)
      {
            DDC_Data.BrigntNess_Valule=Brightness_Default;
            write_SegC_Allocate_Addr(BrightNESS_VALUE_HH,&DDC_Data.BrigntNess_Valule);            
      }
      
      DDC_Data.Contrast_Valule=(*(Flash_ptrC + Contrast_VALUE_HH)<<8) + *(Flash_ptrC + Contrast_VALUE_HL);
      if(DDC_Data.Contrast_Valule>=Contrast_Valid)
      {
            DDC_Data.Contrast_Valule=Contrast_Default;
            write_SegC_Allocate_Addr(Contrast_VALUE_HH,&DDC_Data.Contrast_Valule);            
      }
      Brigntness_PWM_Control(DDC_Data.BrigntNess_Valule);
}

static void Send_Null_Message(void)
{
       DDC_Data.DDC_send_buf[0]=DDCCI_SLAVE_I2C_ADDR;
       DDC_Data.DDC_send_buf[1]=DDCCI_VCP_REPLY_NULL_LENGTH;
        if(DDCCI_Send(&DDC_Data.DDC_send_buf[0],2,NULL, 0)>0)//send right
       _NOP();

}
void DDC_Process(fsjigTaskData* app)
{

       uint16 start_add; 
       uint16 length;
       uint16 fix_add;
       uint16 i;
	   


	switch(DDC_Data.DDC_Process)
  		{

			case DDC_Data_init:
								#ifdef msp430f5505
                              UCB1I2COA = I2C_EDID_Address;  
								#else

								 UCB0I2COA = I2C_EDID_Address;  
								#endif
                              DDC_Parameter_Load();
                              DDC_Data.DDC_Process=DDC_EDID_Data_Rev;


                              
			       break;
			case DDC_EDID_Data_Rev:
			         _NOP();
			       break;
			case DDC_EDID_Data_Complete:
								#ifdef msp430f5505
                              UCB1I2COA = I2C_MONITOR_Address;  			
								#else
								 UCB0I2COA = I2C_MONITOR_Address;  
								#endif														
                              DDC_Data.DDC_Process=DDC_Data_Rev;
								  DDC_Parameter_Load();								
			       break;			       
			case DDC_Data_Rev:
			
				break;
			case DDC_Data_Rev_Handle:
                             if(DDCCI_Receive(&DDC_Data.DDC_rev_buf[0], sizeof(DDC_Data.DDC_rev_buf))>0);//receive right
                             {
                                switch(DDC_Data.DDC_rev_buf[2])
                                    {
                                         case DDCCI_VCP_REQUEST: 
                                                       fix_add=0;
                                                       DDC_Data.DDC_send_buf[fix_add++]=DDCCI_SLAVE_I2C_ADDR;
                                                       DDC_Data.DDC_send_buf[fix_add++]=DDCCI_VCP_REPLY_LENGTH;
                                                       DDC_Data.DDC_send_buf[fix_add++]=DDCCI_VCP_REPLY;  
                                                  for(i=0;i<sizeof(REACT_ORDER);i++)
                                                  {

                                                        if(DDC_Data.DDC_rev_buf[3]==REACT_ORDER[i])
                                                        break;
                                                        
                                                  }
                                                  if(i<sizeof(REACT_ORDER))//supported
                                                  {
                                                        
                                                       if(DDCCI_Send(&DDC_Data.DDC_send_buf[0],fix_add,&REACT_MESSAGE[i][0], sizeof(REACT_MESSAGE[i]))>0)//send right
                                                       _NOP();
                                                  }
                                                  else//send null
                                                  {
                                                        Send_Null_Message();
                                                  }
                                            break;
                                         case DDCCI_CAPABILITIES_REQUEST: 
                                                        start_add= (DDC_Data.DDC_rev_buf[3]<<8) + DDC_Data.DDC_rev_buf[4];
                                                        length=sizeof(CAPABILITIES_REACT);
                                                                                                                      
                                                        if(start_add>=length)
                                                        {
                                                            length=0;
                                                        }
                                                        else
                                                        {
                                                            length=length - start_add;
                                                            if( length/DDCCI_MSG_SZ>0)
                                                            length=DDCCI_MSG_SZ;
                                                            else
                                                            length %=DDCCI_MSG_SZ;
                                                        }

                                                        fix_add=0;
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDCCI_SLAVE_I2C_ADDR;
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDCCI_LEN_MAGIC|(length + 0x03);
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDCCI_CAPABILITIES_REPLY;  
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDC_Data.DDC_rev_buf[3];  
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDC_Data.DDC_rev_buf[4];                                                          
                                                        if(DDCCI_Send(&DDC_Data.DDC_send_buf[0],fix_add, CAPABILITIES_REACT+ start_add, length)>0)//send right
                                                        _NOP();
                                            break;
                                            case DDCCI_TIMING_REQUEST: 
                                                        fix_add=0;
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDCCI_SLAVE_I2C_ADDR;
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDCCI_TIMING_REPLY_LENGTH;
                                                        DDC_Data.DDC_send_buf[fix_add++]=DDCCI_TIMING_REPLY;                                                          
                                                        if(DDCCI_Send(&DDC_Data.DDC_send_buf[0],fix_add,&TIMEING_REACT[0], sizeof(TIMEING_REACT))>0)//send right
                                                        _NOP();
                                            break;    
                                            case DDCCI_VCP_SET:
                                                        switch(DDC_Data.DDC_rev_buf[3])
                                                        {
                                                               case DDCCI_MCCS_BRIGHTNESS:
                                                                        DDC_Data.BrigntNess_Valule= (DDC_Data.DDC_rev_buf[4]<<8) + DDC_Data.DDC_rev_buf[5];
                                                                        //write_SegC_Allocate_Addr(BrightNESS_VALUE_HH,&DDC_Data.BrigntNess_Valule);
                                                                        Brigntness_PWM_Control(DDC_Data.BrigntNess_Valule);			
																																				Test_Exc
                                                               break;
                                                               case DDCCI_MCCS_CONTRAST:
                                                                        DDC_Data.Contrast_Valule= (DDC_Data.DDC_rev_buf[4]<<8) + DDC_Data.DDC_rev_buf[5];
                                                                        //write_SegC_Allocate_Addr(Contrast_VALUE_HH,&DDC_Data.Contrast_Valule);
                                                               break;
                                                               default:
                                                                    Send_Null_Message();

                                                               break;
                                                        }
                                                        
                                            break;
                                            case DDCCI_SAVE_CURRENT_SETTINGS:
                                                                         //save all para here;
                                                     write_SegC_Allocate_Addr(BrightNESS_VALUE_HH,&DDC_Data.BrigntNess_Valule);
                                            break;
                                   
                                   }                                    
                             }
                              DDC_Data.DDC_Process=DDC_Data_Rev;
	
				break;            
			case DDC_Data_Send:
				break;                
			 default: break;	
  		}
}

#ifdef msp430f5505

// USCI_B1 State ISR
#pragma vector = USCI_B1_VECTOR
__interrupt void USCI_B1_ISR(void)
{
  switch(__even_in_range(UCB1IV,12))
  {
  case  0: break;                           // Vector  0: No interrupts
  case  2: break;                           // Vector  2: ALIFG
  case  4: break;                           // Vector  4: NACKIFG
  case  6:                                  // Vector  6: STTIFG
      _NOP();
     UCB1IFG &= ~UCSTTIFG;                  // Clear start condition int flag
     DDC_Data.ddc_rev.counts=0;
     DDC_Data.ddc_send.counts=0;
     break;
  case  8:       //stop handle
      switch(DDC_Data.DDC_Process)
      {
        case DDC_EDID_Data_Rev:
        DDC_Data.DDC_Process=DDC_EDID_Data_Complete;
        break;
        case DDC_Data_Rev:
        DDC_Data.DDC_Process=DDC_Data_Rev_Handle;
        break;
        case DDC_Data_Send:
        DDC_Data.DDC_Process=DDC_Data_Rev;
        break;
        default:
        break;
      }
    UCB1IFG &= ~UCSTPIFG;                   // Clear stop condition int flag
     DDC_Data.ddc_rev.counts=0;
     DDC_Data.ddc_send.counts=0;
    break;
  case 10:    
  DDC_Data.DDC_rev_buf[DDC_Data.ddc_rev.counts++]= UCB1RXBUF;                     // Get RX data
  break;                           // Vector 10: RXIFG  
  case 12:                                  // Vector 12: TXIFG---send interrupt
  if(DDC_Data.DDC_Process<DDC_EDID_Data_Complete)//in the rev state
  UCB1TXBUF=EDID_CONTEXT[DDC_Data.ddc_send.counts++];
  else
  UCB1TXBUF=DDC_Data.DDC_send_buf[DDC_Data.ddc_send.counts++];
      break;
  default: break; 
  }
}


#else 
/*
#define msp430g2333:
USCIAB0TX_VECTOR:
USCI_Ax and USCI_Bx share the same interrupt vectors. 
In I2C mode the state change interrupt flags
UCSTTIFG, UCSTPIFG, UCNACKIFG, UCALIFG from USCI_Bx and UCAxRXIFG from USCI_Ax are
routed to one interrupt vector.

USCIAB0RX_VECTOR:
The I2C transmit and receive interrupt flags UCBxTXIFG and UCBxRXIFG
from USCI_Bx and UCAxTXIFG from USCI_Ax share another interrupt vector.

*/

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void)
{

	if(UC0IFG & UCB0RXIFG)
	DDC_Data.DDC_rev_buf[DDC_Data.ddc_rev.counts++]= UCB0RXBUF;                     // Get RX data
	else if(UC0IFG & UCB0TXIFG)
	{
	  if(DDC_Data.DDC_Process<DDC_EDID_Data_Complete)//in the rev state
	  UCB0TXBUF=EDID_CONTEXT[DDC_Data.ddc_send.counts++];
	  else
	  UCB0TXBUF=DDC_Data.DDC_send_buf[DDC_Data.ddc_send.counts++];
	}
}
//------------------------------------------------------------------------------
// The USCI_B0 state ISR is used to wake up the CPU from LPM0 in order to
// process the received data in the main program. LPM0 is only exit in case
// of a (re-)start or stop condition when actual data was received.
//------------------------------------------------------------------------------
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIAB0RX_ISR(void)
{
    if(UCB0STAT & UCSTTIFG)
  	{
		_NOP();
		UCB0STAT &= ~UCSTTIFG;                  // Clear start condition int flag
		DDC_Data.ddc_rev.counts=0;
		DDC_Data.ddc_send.counts=0;
  	}
	else if(UCB0STAT&UCSTPIFG)
	{
		switch(DDC_Data.DDC_Process)
		{
			case DDC_EDID_Data_Rev:
				DDC_Data.DDC_Process=DDC_EDID_Data_Complete;
			break;
			case DDC_Data_Rev:
				DDC_Data.DDC_Process=DDC_Data_Rev_Handle;
			break;
			case DDC_Data_Send:
				DDC_Data.DDC_Process=DDC_Data_Rev;
			break;
			default:
			break;
		}
		UCB0STAT &= ~UCSTPIFG;                   // Clear stop condition int flag
		DDC_Data.ddc_rev.counts=0;
		DDC_Data.ddc_send.counts=0;
	}
}                                           // received
#endif








