#include "private.h" 
static void copy_C2D(void);
//static void write_SegC(char value);


//------------------------------------------------------------------------------
// Copy Seg C to Seg D
//------------------------------------------------------------------------------
static void copy_C2D(void)
{
  unsigned int i;
  char *Flash_ptrC;
  char *Flash_ptrD;

  Flash_ptrC = (char *) 0x1880;             // Initialize Flash segment C ptr
  Flash_ptrD = (char *) 0x1800;             // Initialize Flash segment D ptr

  //__disable_interrupt();                    // 5xx Workaround: Disable global
                                            // interrupt while erasing. Re-Enable
                                            // GIE if needed
  FCTL3 = FWKEY;                            // Clear Lock bit
  FCTL1 = FWKEY+ERASE;                      // Set Erase bit
  *Flash_ptrD = 0;                          // Dummy write to erase Flash seg D
  FCTL1 = FWKEY+WRT;                        // Set WRT bit for write operation

  for (i = 0; i < 128; i++)
  {
    *Flash_ptrD++ = *Flash_ptrC++;          // copy value segment C to seg D
	
    
  }
  FCTL1 = FWKEY;                            // Clear WRT bit
  FCTL3 = FWKEY+LOCK;                       // Set LOCK bit
 // __enable_interrupt();
}


//------------------------------------------------------------------------------
// Input = value, holds value to write to Seg C
//------------------------------------------------------------------------------
void write_SegC(char value)
{
  unsigned int i;
  char * Flash_ptr;                         // Initialize Flash pointer
  Flash_ptr = (char *) 0x1880;
  FCTL3 = FWKEY;                            // Clear Lock bit
  FCTL1 = FWKEY+ERASE;                      // Set Erase bit
  *Flash_ptr = 0;                           // Dummy write to erase Flash seg
  FCTL1 = FWKEY+WRT;                        // Set WRT bit for write operation

  for (i = 0; i < 128; i++)
  {
    *Flash_ptr++ = value;                   // Write value to flash
  }
  FCTL1 = FWKEY;                            // Clear WRT bit
  FCTL3 = FWKEY+LOCK;                       // Set LOCK bit
}


//------------------------------------------------------------------------------
// Input = value, holds value to write to Seg C
//------------------------------------------------------------------------------
void write_SegC_Allocate_Addr(uint8  Addr_OFFSET, uint16  *value)
{
  unsigned int i;
  char *Flash_ptrC;
  char *Flash_ptrD;
  Flash_ptrC = (char *) 0x1880;             // Initialize Flash segment C ptr
  Flash_ptrD = (char *) 0x1800;             // Initialize Flash segment D ptr
  copy_C2D();
  FCTL3 = FWKEY;                            // Clear Lock bit
  FCTL1 = FWKEY+ERASE;                      // Set Erase bit
  *Flash_ptrC = 0;                           // Dummy write to erase Flash seg
  FCTL1 = FWKEY+WRT;                        // Set WRT bit for write operation

  for(i=0;i<Addr_OFFSET;i++)
  {
    *Flash_ptrC++ = *Flash_ptrD++;
  }
  *Flash_ptrC=(*value)>>8;
  Flash_ptrC++;
  Flash_ptrD++;
  *Flash_ptrC=(*value)&0xFF;  
  Flash_ptrC++;
  Flash_ptrD++;
  for(i=Addr_OFFSET;i<128;i++)
  *Flash_ptrC++ = *Flash_ptrD++;
  FCTL1 = FWKEY;                            // Clear WRT bit
  FCTL3 = FWKEY+LOCK;                       // Set LOCK bit
}



