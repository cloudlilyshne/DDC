//#include "msp430f5505.h"

//#define msp430f5505
//#define msp430g2333
#include "private.h" 
#include "ddc.h"
static fsjigTaskData app;
fsjigTaskData *getApp(void)
{
    return &app;
}
void Init_Timer()
{
#ifdef msp430f5505
#if 1
   TA1CCTL0 = CCIE;                          // 对应CCR0使能 interrupt enable
   TA1CCR0 = 25000;           //  1ms interuppt
    //TA1CCR0 = 32;                   //500ns   
   TA1CTL = TASSEL_2 + MC_1 + TACLR;         // 时钟源选择SMCLK，Up to CCR0，清计数器

	 

#endif

   #if 1
   //TA1CCTL0 = CCIE;                          // 对应CCR0使能 interrupt enable
   // TA1CCR0 = 25000;           //  1ms interuppt
    //TA1CCR0 = 32;                   //500ns
   // TA1CTL = TASSEL_1 + MC_1 + TACLR;         // 时钟源选择SMCLK，Up to CCR0，清计数器



	   //引脚设置(暂时使用P1.2输出一路PWM)     
       P1SEL |= BIT2;  //PWM从P1.2输出     
       P1DIR |= BIT2;  //PWM从P1.2输出           
       TA0CTL = TASSEL_1 + MC_1 + TACLR;  //时钟源选择ACLK，增计数模式 TA设置     
       TA0CCTL1 = OUTMOD_7; //模式7 高电平PWM输出 PWM设置  


	P1OUT &= ~BIT1;
	P1OUT |= BIT3;
//      Brigntness_PWM_Control(DDC_Data.BrigntNess_Valule);
	 TA0CCR0 = 1200;
	 TA0CCR1 = 400;
   #endif 

#if 0

    TA2CCTL0 = CCIE;                          // 对应CCR0使能 interrupt enable
    TA2CCR0 = 1000;           //  1ms interuppt
    TA2CTL = TASSEL_2 + MC_1 + TACLR;         // 时钟源选择SMCLK，Up to CCR0，清计数器
 #endif


 #else
  TA0CCTL0 = CCIE;                          // 对应CCR0使能 interrupt enable 
  TA0CCR0 = 12000;           //  1ms interuppt  
  TA0CTL = TASSEL_2 + MC_1 + TACLR;         // 时钟源选择SMCLK，Up to CCR0，清计数器  


	//引脚设置(暂时使用P1.1输出一路PWM)     
	P2SEL |= BACK_LIGHT_ADJ;  //PWM从P2.1输出     
	P2DIR |= BACK_LIGHT_ADJ;  //PWM从P2.1输出           
	TA1CTL = TASSEL_2 + MC_1 + TACLR;  //时钟源选择ACLK，增计数模式 TA设置     
	TA1CCTL1 = OUTMOD_7; //模式7 高电平PWM输出 PWM设置  

	//      Brigntness_PWM_Control(DDC_Data.BrigntNess_Valule);
	//TA1CCR0 = 1600;
	//TA1CCR1 = 800;
 #endif
}


void Init_I2c()
{

#ifdef msp430f5505
/*
  master mode:
  P4SEL |= BIT1 + BIT2;

  UCB1CTL0 = UCMODE_3 + UCMST;
  UCB1BRW = 240;
  UCB1CTL1 = UCSSEL__SMCLK;

  */
  P4SEL |= BIT1 + BIT2;
  UCB1CTL1 |= UCSWRST;                      // Enable SW reset
  UCB1CTL0 = UCMODE_3 + UCSYNC;             // I2C Slave, synchronous mode
  //UCB1I2COA = I2C_Slave_Address;                         // Own Address is 0x6E
  UCB1I2COA = I2C_EDID_Address;                         // Own Address is 0x6E
  UCB1CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
  UCB1IE |= UCTXIE + UCSTTIE + UCSTPIE + UCRXIE;     // Enable TX interrupt
                                            // Enable Start condition interrupt
  //__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupts
  //__no_operation();                         // For debugger


  #else


/*
UCBxI2CIE, USCI_Bx I2C Interrupt Enable Register
Reserved Bits 7-4 Reserved
UCNACKIE Bit 3 Not-acknowledge interrupt enable
0 Interrupt disabled
1 Interrupt enabled
UCSTPIE Bit 2 Stop condition interrupt enable
0 Interrupt disabled
1 Interrupt enabled
UCSTTIE Bit 1 Start condition interrupt enable
0 Interrupt disabled
1 Interrupt enabled
UCALIE Bit 0 Arbitration lost interrupt enable
0 Interrupt disabled
1 Interrupt enabled

IE2, Interrupt Enable Register 2
UCB0TXIE Bit 3 USCI_B0 transmit interrupt enable
0 Interrupt disabled
1 Interrupt enabled
UCB0RXIE Bit 2 USCI_B0 receive interrupt enable
0 Interrupt disabled
1 Interrupt enabled
Bits 1-0 These bits may be used by other modules (see the device-specific data sheet).

*/

/* slave mode  */

  P1SEL |= BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
  P1SEL2|= BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
  
  UCB0CTL1 |= UCSWRST;                      // Enable SW reset
  UCB0CTL0 = UCMODE_3 + UCSYNC;             // I2C Slave, synchronous mode
  UCB0I2COA = I2C_EDID_Address;                         // Own Address is 048h
  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
  UCB0I2CIE |= UCSTTIE + UCSTPIE;                     // Enable STT interrupt and STP interrupt
  IE2 |= UCB0TXIE + UCB0RXIE;                          // Enable TX and RX interrupt

  #endif


  
}


void Init_Ports()
{

  #ifdef msp430f5505
  P2OUT = BIT0;
  P2DIR = BIT0;

  //P4DIR |= BIT1 + BIT2;

  P5DIR &= ~BIT4;//TT_dectect
  P5DIR &= ~BIT5;//FS_detect
  
  P4DIR |=BIT7 + BIT3;
  P4OUT &=~BIT7;
  P5DIR |= FPGA_Reset +FPGA_Trig ;
  P5OUT |= FPGA_Reset +FPGA_Trig ;
  P5OUT &= ~FPGA_Trig;

  P1DIR |=	BIT1 + BIT3;
  #else

  P2DIR |=BACK_LIGHT_EN + BACK_LIGHT_ADJ +LCD_EN;

	
  P2OUT |=LCD_EN;
  P2OUT &=~BACK_LIGHT_EN;	
  Test_Dir_OUT	


  #endif	
  
}
/*
LFXT1CLK
XT2CLK
DCOCLK:Internal digitally controlled oscillator (DCO).
VLOCLK:Internal very low power, low frequency oscillator with 12-kHz typical frequency

After a PUC, MCLK and SMCLK are sourced from DCOCLK at ~1.1 MHz (see the device-specific data
sheet for parameters) and ACLK is sourced from LFXT1CLK in LF mode with an internal load capacitance
of 6 pF.

*/
void Init_Clock()
{
	#ifdef msp430f5505
  P5SEL |= BIT2 + BIT3;

  UCSCTL6 &= ~XT2OFF;
  UCSCTL3 = SELREF__REFOCLK;
  UCSCTL2 = 0x12ED;//  b0001  0010  1110   1101   FLLN:749   FLLD:1
  //UCSCTL2 = 0x13D0;
  UCSCTL1 = DCORSEL_7;
  UCSCTL4 = SELM__DCOCLKDIV + SELS__DCOCLKDIV + SELA__DCOCLKDIV;//source is DCOCLKDIV     DCOCLKDIV=(FLLN+1)*REFOCLK=750*32768=24576000=24M
	#else  //msp430g2333
	if (CALBC1_12MHZ==0xFF)					// If calibration constant erased
	{											
	  while(1);                               // do not load, trap CPU!!	
	}
	DCOCTL = 0;                               // Select lowest DCOx and MODx settings
	BCSCTL1 = CALBC1_12MHZ;                    // Set DCO to 1MHz
	DCOCTL = CALDCO_12MHZ;
   BCSCTL3 |= LFXT1S_2;                    // LFXT1 = VLO	
   P1DIR |= BIT0 + BIT4;                            // P1.0,1 and P1.4 outputs
   P1SEL |= 0x11;                            // P1.0,4 ACLK, SMCLK output   
	#endif  
}
#ifdef msp430f5505
void SetVCoreLevel( unsigned char level )
{
  if ( level > PMMCOREV_3 )
    level = PMMCOREV_3;

    PMMCTL0_H = PMMPW_H;

    PMMRIE = 0;
    SVSMHCTL = 0;
    SVSMLCTL = 0;

    PMMCTL0_L = level;
}
	#endif  

void init_Globle(void)
{
	 WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer

	 #ifdef msp430f5505

  	SetVCoreLevel( PMMCOREV_3 );

	 #endif
  	Init_Clock();
  	Init_Ports();

 	Init_I2c();

  	Init_Timer();
	DDC_init();
	__enable_interrupt();
}

void main()
{
 
	init_Globle();
  while ( 1 )
  {
       DDC_Process(&app);     
  }
  
}

