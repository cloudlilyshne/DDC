#include "private.h"
#include "DDCCI.h"

 /* send data    

            pDDCCI->rDstI2CAddr = pDDCCI->slaveI2CAddr | 0x01;    //0x6F

            pDDCCI->rSrcI2CAddr = pDDCCI->slaveI2CAddr;              //0x6E

          

            pDDCCI->wDstI2CAddr = pDDCCI->slaveI2CAddr;             //0x6E

            // In order to tell the display that the received message is of DDC/CI type,

            // the Source Address Byte bit 0 is set to 1.

            pDDCCI->wSrcI2CAddr = pDDCCI->masterI2CAddr | 0x01;  //0x51

*/
int DDCCI_Send(uint8 *dst,uint16 fix,const uint8 *src, int len)  //PC send to monitor

{

    int           idx;  
    unsigned char checkSum;
/*S �C [6E]a �C [51]a �C [81]a �C [07]a �C [CHK]a �C P*/
/* static const uint8 BRIGHTNESS_REACT[] = {0x88,0x02,0x00,0x10,0x00,0x00,0x64,0x00,0x32}; */
    #if 0
    if(msgLen<len)
    {
        return -7;
    }
    #endif
    checkSum=dst[0];
    checkSum ^=DDCCI_MASTER_I2C_ADDR;
  for ( idx = 1; idx < fix; ++ idx )
    {
        checkSum^= dst[ idx ];

    }

    
    for ( idx = 0; idx < len; ++ idx )
    {
        dst[ idx + fix ] = *(src+ idx) ;
        checkSum^= *(src +idx);
    }
    dst[ idx + fix ] = checkSum;
    return idx > 0 ? idx : 0;
}

 /*  S �C [6F]a �C [6E]a �C [06]a �C [4E]a �C [SS]a �C [HH]a �C [HL]a �C�C [VH]a �C [VL]a �C [CHK]n �C P   */

int DDCCI_Receive(unsigned char *data, int len )//PC recieve from monitor
{

    int           idx;
    int           msgLen;
    unsigned char checkSum;
       //master mode
    msgLen = DDCCI_GET_LEN( data[1] );
    if ( msgLen > len )
    {
        return -7;
    }
    checkSum = DDCCI_SLAVE_I2C_ADDR;    //send from device to PC
    checkSum ^= data[ 0 ];
    checkSum ^= data[ 1 ];
    for ( idx = 0; idx < msgLen+1; ++ idx )
    {
        checkSum   ^= data[ idx +2];
    }
    if ( checkSum != 0 )
    {
        return -8;
    }
    return msgLen;
}

