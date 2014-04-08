#ifndef _DDCCI_H

#define _DDCCI_H

 
#include "MCCS.h" 

#define DDCCI_MSG_SZ                        (32)
#define DDCCI_MSG_SZ_min                        (5)

#define DDCCI_MSG_PAYLOAD_SZ                (DDCCI_MSG_SZ - 4)

 

// The address of normal working mode for DDC/CI

#define DDCCI_MASTER_I2C_ADDR                0x50

#define DDCCI_SLAVE_I2C_ADDR                0x6E

 

// The external display dependent device

#define DDCCI_SLAVE_PRINTER_I2C_ADDR                0xF0 // Touch Screen, Light pen or Remote Control Track Ball

#define DDCCI_SLAVE_AUDIO_DEV_I2C_ADDR                0xF2 // Speaker / Microphone

#define DDCCI_SLAVE_SERIAL_COMMUNICATION_I2C_ADDR    0xF4 // Home Network IF (power line modem)

#define DDCCI_SLAVE_CALIBRATION_DEV_I2C_ADDR        0xF6 // Luminance Probe or Colorimeter

#define DDCCI_SLAVE_INPUT_DEV_I2C_ADDR                0xF8 // IR keyboard and remote control pad (shared IR channel)

#define DDCCI_SLAVE_RESERVED1_I2C_ADDR                0xFA // Reserved for future use

#define DDCCI_SLAVE_RESERVED2_I2C_ADDR                0xFC // Reserved for future use

#define DDCCI_SLAVE_RESERVED3_I2C_ADDR                0xFE // Reserved for future use

 

// Fixed address I2C devices

#define DDCCI_SLAVE_SMART_BATTERY_CHARGER_I2C_ADDR    0x12

#define DDCCI_SLAVE_SMART_BATTERY_SELECTOR_I2C_ADDR    0x14

#define DDCCI_SLAVE_SMART_BATTERY_I2C_ADDR            0x16

#define DDCCI_SLAVE_AUDIO_PROCESSOR_I2C_ADDR        0x80

#define DDCCI_SLAVE_PAL_NTSC_DECODER_I2C_ADDR        0x40

#define DDCCI_SLAVE_DDC2B_MONITOR_I2C_ADDR            0xA0

 
//command
#define DDCCI_VCP_REQUEST                    0x01
#define DDCCI_VCP_REPLY                        0x02
#define DDCCI_VCP_SET                        0x03
#define DDCCI_SAVE_CURRENT_SETTINGS            0x0C
//#define DDCCI_VCP_RESET                        0x09
//#define DDCCI_IDENTIFICATION_REQUEST        0xF1
//#define DDCCI_IDENTIFICATION_REPLY            0xE1

#define DDCCI_CAPABILITIES_REPLY            0xE3
#define DDCCI_CAPABILITIES_REQUEST            0xF3

//#define DDCCI_TIMING_REPLY                    0x06
#define DDCCI_TIMING_REQUEST                0x07
#define DDCCI_TIMING_REPLY            0x4E
#define DDCCI_TIMING_REPLY_LENGTH          0x06
#define DDCCI_TIMING_SS          0x00
#define DDCCI_TIMING_HH          0x17
#define DDCCI_TIMING_HL          0x70
#define DDCCI_TIMING_VH          0x17
#define DDCCI_TIMING_VL          0x70


#define DDCCI_DISPLAY_SELF_TEST_REQEUST        0xB1
#define DDCCI_VCP_REPLY_LENGTH          0x88

#define DDCCI_VCP_REPLY_NULL_LENGTH          0x80


#define DDCCI_TABLE_READ_REQEUST            0xE2
#define DDCCI_TABLE_READ_REPLY                0xE4
#define DDCCI_TABLE_WRITE                    0xE7

 

#define DDCCI_ENABLE_APPLICATION_REPORT        0xF5



#define DDCCI_FLG_INITED        0x00000001
#define DDCCI_FLG_READ            0x01000000
#define DDCCI_FLG_WRITE            0x02000000
#define DDCCI_FLG_RW            (DDCCI_FLG_READ | DDCCI_FLG_WRITE)

#define DDCCI_LEN_MAGIC            (0x80)
#define DDCCI_GEN_LEN( len )    (DDCCI_LEN_MAGIC | ((len) & (DDCCI_MSG_SZ - 1)))
#define DDCCI_GET_LEN( len )    (((len) & ~DDCCI_LEN_MAGIC) & (DDCCI_MSG_SZ - 1))

 
#define DDCCI_INV_OPCODE        -1
#define DDCCI_MIN_READ_DELAY    35




#define DDCCI_TX( pDDCCI, data, len )         do{  \
    DDCCI_Delay((pDDCCI));                                  \
   // DDCCI_Send( (pDDCCI), (data), (len) );            \
    }while(0)


#define DDCCI_RX( pDDCCI, data, len )         do{  \
    DDCCI_Delay((pDDCCI));  \
    DDCCI_Send( (pDDCCI), (data), (len) );  \
    }while(0)



#define DDCCI_SendNullMsg( pDDCCI )         do{  \
  if ( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_SLAVE )    \
    DDCCI_TX( (pDDCCI),NULL,0);  \
    }while(0)

#define DDCCI_SaveCurrentSettings( pDDCCI )         do{  \
  assert( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER ); \
  if ( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER )    \
  {\
    unsigned char _buf[ 1 ] = { DDCCI_SAVE_CURRENT_SETTINGS };    \
    DDCCI_TX( (pDDCCI), _buf, sizeof( _buf ) );  \
    }\
    }while(0)


#define DDCCI_GetVCPFeature( pDDCCI, mccs, valU32 )    do {                \
        assert( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER );            \
        (valU32) = -1;                                                    \
        if ( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER )                \
        {                                                                \
            unsigned char _buf[ DDCCI_MSG_SZ ];                            \
            _buf[ 0 ] = DDCCI_VCP_REQUEST;                                \
            _buf[ 1 ] = (mccs);                                            \
            DDCCI_TX( (pDDCCI), _buf, 2 );                                \
            DDCCI_Delay( (pDDCCI) );                                    \
            if ( DDCCI_Receive(  _buf, sizeof( _buf ) ) > 0 )    \
            {                                                            \
                if ( _buf[ 0 ] == DDCCI_VCP_REPLY &&                     \
                    _buf[ 1 ] == 0x00 &&                                \
                    _buf[ 2 ] == (mccs) &&                                 \
                    _buf[ 3 ] == 0x01 )                                    \
                {                                                        \
                    (valU32) = ((_buf[ 4 ] << 24) |                        \
                        (_buf[ 5 ] << 16 ) |                            \
                        (_buf[ 6 ] << 8) |                                \
                        (_buf[ 7 ]));                                   \
                }                                                        \
            }                                                            \
        }                                                                \
    } while ( 0 )  


#define DDCCI_SetVCPFeature( pDDCCI, mccs, valU16 )    do {            \
        assert( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER );        \
        if ( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER )           \
        {                                                           \
            unsigned char _buf[ 4 ];                                \
            _buf[ 0 ] = DDCCI_VCP_SET;                                \
            _buf[ 1 ] = (mccs);                                      \
            _buf[ 2 ] = ((valU16) >> 8) & 0xFF;                       \
            _buf[ 3 ] = (valU16) & 0xFF;                            \
            DDCCI_TX( (pDDCCI), _buf, sizeof( _buf ) );                \
        }                                                            \
    } while ( 0 )


#define DDCCI_GetCapabilities( pDDCCI, offsetU16, buf32 )    do {        \
        assert( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER );            \
        if ( (pDDCCI)->i2cMode == EDDCCI_I2C_MODE_MASTER )                \
            {                                                                \
                int           _len;                                            \
                unsigned char _buf[ DDCCI_MSG_SZ + 4 ];                        \
                _buf[ 0 ] = DDCCI_CAPABILITIES_REQUEST;                        \
                _buf[ 1 ] = ((offsetU16) >> 8) & 0xFF;                        \
                _buf[ 2 ] = (offsetU16) & 0xFF;                                \
                DDCCI_TX( (pDDCCI), _buf, 3 );                                \
                DDCCI_Delay( (pDDCCI) );                                    \
                _len = DDCCI_Receive(  _buf, sizeof( _buf ) );        \
                if ( _len > 0 )                                                \
                {                                                            \
                    if ( _buf[ 0 ] == DDCCI_CAPABILITIES_REPLY &&            \
                        ((_buf[ 1 ] << 8) | _buf[ 2 ]) == (offsetU16) )        \
                    { \
                        memcpy( (buf32), &_buf[ 3 ], _len );                \
                    } \
                }                                                            \
                }\
    }   while ( 0 )  

typedef enum _EDDCCIDispDev
{

    EDDCCI_DISP_DEV_INDEP,     // Independent display device

    EDDCCI_DISP_DEV_EXT_DEP, // External display dependent device

    EDDCCI_DISP_DEV_INT_DEP // Internal display dependent device

} EDDCCIDispDev;

 

typedef enum _EDDCCII2CMode

{

    EDDCCI_I2C_MODE_MASTER,

    EDDCCI_I2C_MODE_SLAVE

} EDDCCII2CMode;

 
/*
typedef struct _SDDCCI

{

    int            flags;

    unsigned char  masterI2CAddr; // 0x6E in normal case

    unsigned char  slaveI2CAddr;  // 0x50 in normal case

    unsigned char  rDstI2CAddr;    //Read dst address

    unsigned char  rSrcI2CAddr;   //read src address

    unsigned char  wDstI2CAddr;  //write dst address

    unsigned char  wSrcI2CAddr;  //write src address

    EDDCCIDispDev  dispDev;

    EDDCCII2CMode  i2cMode;

    struct timeval DDCCITimestamp; // The timestamp of last DDC/CI OpCode

    int            DDCCIOpCode;       // Last DDC/CI OpCode

} SDDCCI;

 */


typedef struct _SDDCCI

{

    int            flags;

    unsigned char  masterI2CAddr; //  0x50 in normal case  

    unsigned char  slaveI2CAddr;  // 0x6E in normal case

    unsigned char  rDstI2CAddr;    //Read dst address

    unsigned char  rSrcI2CAddr;   //read src address

    unsigned char  wDstI2CAddr;  //write dst address

    unsigned char  wSrcI2CAddr;  //write src address

    EDDCCIDispDev  dispDev;

    EDDCCII2CMode  i2cMode;

   int            DDCCIOpCode;       // Last DDC/CI OpCode

} SDDCCI;


 

typedef struct _SDDCCITimingReport

{

    unsigned char  timingStatus;

    unsigned char  pad;

    unsigned short horFreq;    // Horizontal frequency

    unsigned short verFreq;    // Vertical frequency

} SDDCCITimingReport;

 

int DDCCI_Create( SDDCCI *pDDCCI,

    unsigned char masterI2CAddr, unsigned char slaveI2CAddr,

    EDDCCIDispDev dispDev, EDDCCII2CMode i2cMode );

 

int DDCCI_Destroy( SDDCCI *pDDCCI );

 

int DDCCI_Send(uint8 *dst,uint16 fix,const uint8 *src, int len);
int DDCCI_Receive(unsigned char *data, int len );

 

int DDCCI_Delay( SDDCCI *pDDCCI );

 

//int DDCCI_GetTimingReport( SDDCCI *pDDCCI, SDDCCITimingReport *pTimingReport );

 

#endif
