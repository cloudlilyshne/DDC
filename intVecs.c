
#include "private.h" 

#include "intVecs.h"
/*  TA0 中断服务:1ms   */


#ifdef msp430f5505
#if 1
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{

       fsjigTaskData* app;           /* pointer to main app structure *///P1OUT ^= BIT2;
       app = getApp();

}

#endif

// TA1 中断服务程序   

#if 1
#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR(void)
{


	fsjigTaskData* app;           /* pointer to main app structure *///P1OUT ^= BIT2;
	app = getApp();
  	{
		//FPGA_Trig_Exc
//P2OUT ^=BACK_LIGHT_ADJ;		
  	}
	
	
}

#endif


#else
/*1ms interrupt*/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
	//P2OUT ^=BACK_LIGHT_ADJ;		


}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR(void)
{


}


#endif




