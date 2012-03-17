#line 1 "ds1820demo.c"
#line 1 "ds1820demo.c"

#line 9 "ds1820demo.c"
 


#line 40 "ds1820demo.c"
 

#line 1 "./ds1820demo.h"


 
 
 
#line 7 "./ds1820demo.h"

 






#line 1 "../_inc/types.h"

#line 9 "../_inc/types.h"
 


#line 21 "../_inc/types.h"
 


#line 25 "../_inc/types.h"

 
 
 
#line 30 "../_inc/types.h"

typedef unsigned char bool;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long sint32;
typedef unsigned char  uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;

#line 40 "../_inc/types.h"



 
 
 
#line 47 "../_inc/types.h"
#line 57 "../_inc/types.h"

#line 59 "../_inc/types.h"
#line 15 "./ds1820demo.h"



 
#pragma config OSC = HSPLL
#pragma config WDT = OFF
#pragma config LVP = ON


#line 25 "./ds1820demo.h"
#line 26 "./ds1820demo.h"

  
#line 29 "./ds1820demo.h"
#line 30 "./ds1820demo.h"


#line 33 "./ds1820demo.h"
#line 34 "./ds1820demo.h"



#line 39 "./ds1820demo.h"
 
 
extern void delay_asm_c18_32mhz(sint16 usec);

#line 44 "./ds1820demo.h"




#line 50 "./ds1820demo.h"
 
void delay_ms(uint16 msec)
{
    while(msec!=0)
    {
        msec--;
        Delay100TCYx(80);
    }
}

#line 61 "./ds1820demo.h"
#line 62 "./ds1820demo.h"
#line 63 "./ds1820demo.h"
#line 64 "./ds1820demo.h"

#line 66 "./ds1820demo.h"




 
 
 
#line 74 "./ds1820demo.h"
#line 87 "./ds1820demo.h"

#line 89 "./ds1820demo.h"


#line 42 "ds1820demo.c"

#line 1 "./..\_inc\types.h"

#line 9 "./..\_inc\types.h"
 


#line 21 "./..\_inc\types.h"
 

#line 30 "./..\_inc\types.h"
#line 40 "./..\_inc\types.h"
#line 47 "./..\_inc\types.h"
#line 57 "./..\_inc\types.h"
#line 59 "./..\_inc\types.h"
#line 43 "ds1820demo.c"



 
#line 48 "ds1820demo.c"
#line 49 "ds1820demo.c"
#line 50 "ds1820demo.c"
#line 51 "ds1820demo.c"
#line 52 "ds1820demo.c"
bool input_func(void)
{
    TRISBbits.TRISB3 = 1;
    return (PORTBbits.RB3);
}
#line 58 "ds1820demo.c"

#line 60 "ds1820demo.c"
#line 62 "ds1820demo.c"

#line 1 "./..\_drv\ds1820.h"
   
#line 9 "./..\_drv\ds1820.h"
 


#line 47 "./..\_drv\ds1820.h"
 


#line 51 "./..\_drv\ds1820.h"


 
#line 57 "./..\_drv\ds1820.h"


#line 60 "./..\_drv\ds1820.h"


 
 
 

#line 67 "./..\_drv\ds1820.h"
#line 68 "./..\_drv\ds1820.h"
#line 69 "./..\_drv\ds1820.h"
#line 70 "./..\_drv\ds1820.h"
#line 71 "./..\_drv\ds1820.h"
#line 72 "./..\_drv\ds1820.h"


 
 
 

#line 79 "./..\_drv\ds1820.h"
#line 80 "./..\_drv\ds1820.h"
#line 81 "./..\_drv\ds1820.h"
#line 82 "./..\_drv\ds1820.h"
#line 83 "./..\_drv\ds1820.h"

#line 85 "./..\_drv\ds1820.h"


 
 
 

#line 92 "./..\_drv\ds1820.h"
#line 93 "./..\_drv\ds1820.h"
#line 94 "./..\_drv\ds1820.h"
#line 95 "./..\_drv\ds1820.h"
#line 96 "./..\_drv\ds1820.h"
#line 97 "./..\_drv\ds1820.h"
#line 98 "./..\_drv\ds1820.h"
#line 99 "./..\_drv\ds1820.h"
#line 100 "./..\_drv\ds1820.h"
#line 101 "./..\_drv\ds1820.h"


#line 104 "./..\_drv\ds1820.h"
#line 105 "./..\_drv\ds1820.h"


 
 
 

static bool bDoneFlag;
static uint8 nLastDiscrepancy_u8;
static uint8 nRomAddr_au8[8 ];



 
 
 



#line 129 "./..\_drv\ds1820.h"
 
#line 131 "./..\_drv\ds1820.h"



#line 140 "./..\_drv\ds1820.h"
 
#line 142 "./..\_drv\ds1820.h"



#line 151 "./..\_drv\ds1820.h"
 
#line 155 "./..\_drv\ds1820.h"
#line 156 "./..\_drv\ds1820.h"
#line 157 "./..\_drv\ds1820.h"




#line 167 "./..\_drv\ds1820.h"
 
#line 171 "./..\_drv\ds1820.h"
#line 172 "./..\_drv\ds1820.h"
#line 173 "./..\_drv\ds1820.h"



#line 182 "./..\_drv\ds1820.h"
 
bool DS1820_Reset(void)
{
   bool bPresPulse;

    ;
   
    
   TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 0) ;
   delay_asm_c18_32mhz (480 ) ;
   TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 1) ;

    
   delay_asm_c18_32mhz (40 ) ;

    
   bPresPulse = input_func() ;

   delay_asm_c18_32mhz (424) ;
   
    ;

   return bPresPulse;
}



#line 215 "./..\_drv\ds1820.h"
 
bool DS1820_ReadBit(void)
{
   bool bBit;

    ;
   
   TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 0) ;
   delay_asm_c18_32mhz (2 ) ;
   input_func() ;
   delay_asm_c18_32mhz (5 ) ;

   bBit = input_func() ;
   
    ;

   return (bBit);
}



#line 242 "./..\_drv\ds1820.h"
 
void DS1820_WriteBit(bool bBit)
{
    ;
   
   TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 0) ;
   delay_asm_c18_32mhz (2 ) ;

   if (bBit != 0 )
   {
      TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 1) ;
   }

   delay_asm_c18_32mhz (100 ) ;
   TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 1) ;
   
    ;
}



#line 269 "./..\_drv\ds1820.h"
 
uint8 DS1820_ReadByte(void)
{
   uint8 i;
   uint8 value = 0;

   for (i=0 ; i < 8; i++)
   {
      if ( DS1820_ReadBit() )
      {
         value |= (1 << i);
      }
      delay_asm_c18_32mhz (120) ;
   }
   return(value);
}



#line 294 "./..\_drv\ds1820.h"
 
void DS1820_WriteByte(uint8 val_u8)
{
   uint8 i;
   uint8 temp;

   for (i=0; i < 8; i++)       
   {
      temp = val_u8 >> i;      
      temp &= 0x01;            
      DS1820_WriteBit(temp);   
   }

   delay_asm_c18_32mhz (105) ;
}



 
 
 



#line 325 "./..\_drv\ds1820.h"
 
void DS1820_AddrDevice(uint8 nAddrMethod)
{
   uint8 i;
   
   if (nAddrMethod == 0x55 )
   {
      DS1820_WriteByte(0x55 );      
      for (i = 0; i < 8 ; i ++)
      {
         DS1820_WriteByte(nRomAddr_au8[i]);
      }
   }
   else
   {
      DS1820_WriteByte(0xCC );      
   }
}



#line 353 "./..\_drv\ds1820.h"
 
bool DS1820_FindNextDevice(void)
{
    uint8 state_u8;
    uint8 byteidx_u8;
    uint8 mask_u8 = 1;
    uint8 bitpos_u8 = 1;
    uint8 nDiscrepancyMarker_u8 = 0;
    bool bit_b;
    bool bStatus;
    bool next_b = 0 ;

     
    for (byteidx_u8=0; byteidx_u8 < 8; byteidx_u8 ++)
    {
        nRomAddr_au8[byteidx_u8] = 0x00;
    }

    bStatus = DS1820_Reset();         

    if (bStatus || bDoneFlag)         
    {
        nLastDiscrepancy_u8 = 0;      
        return 0 ;
    }

     
    DS1820_WriteByte(0xF0 );

    byteidx_u8 = 0;
    do
    {
        state_u8 = 0;

         
        if ( DS1820_ReadBit() != 0 )
        {
            state_u8 = 2;
        }
        delay_asm_c18_32mhz (120) ;

         
        if ( DS1820_ReadBit() != 0 )
        {
            state_u8 |= 1;
        }
        delay_asm_c18_32mhz (120) ;

         
         
         
         
         
         

         
        if (state_u8 == 3)
        {
            break;
        }
        else
        {
             
            if (state_u8 > 0)
            {
                 
                bit_b = (bool)(state_u8 >> 1);
            }
             
            else
            {
                 
                if (bitpos_u8 < nLastDiscrepancy_u8)
                {
                     
                    bit_b = ( (nRomAddr_au8[byteidx_u8] & mask_u8) > 0 );
                }
                else
                {
                    bit_b = (bitpos_u8 == nLastDiscrepancy_u8);
                }

                if (bit_b == 0)
                {
                    nDiscrepancyMarker_u8 = bitpos_u8;
                }
            }

             
           if (bit_b != 0)
           {
               nRomAddr_au8[byteidx_u8] |= mask_u8;
           }
           else
           {
               nRomAddr_au8[byteidx_u8] &= ~mask_u8;
           }

           DS1820_WriteBit(bit_b);

            
           bitpos_u8 ++;

            
           mask_u8 = mask_u8 << 1;

            
           if (mask_u8 == 0)
           {
               byteidx_u8 ++;   
               mask_u8 = 1;     
           }
        }
    } while (byteidx_u8 < 8 );


     
    if (bitpos_u8 < 65)
    {
         
        nLastDiscrepancy_u8 = 0;
    }
    else
    {
         
        nLastDiscrepancy_u8 = nDiscrepancyMarker_u8;
        bDoneFlag = (nLastDiscrepancy_u8 == 0);

         
        next_b = 1 ;
    }

    return next_b;
}



#line 497 "./..\_drv\ds1820.h"
 
bool DS1820_FindFirstDevice(void)
{
    nLastDiscrepancy_u8 = 0;
    bDoneFlag = 0 ;

    return ( DS1820_FindNextDevice() );
}



#line 515 "./..\_drv\ds1820.h"
 
void DS1820_WriteEEPROM(uint8 nTHigh, uint8 nTLow)
{
     
    DS1820_Reset();
    DS1820_AddrDevice(0x55 );
    DS1820_WriteByte(0x4E );  
    DS1820_WriteByte(nTHigh);
    DS1820_WriteByte(nTLow);

    delay_asm_c18_32mhz (10) ;

    DS1820_Reset();
    DS1820_AddrDevice(0x55 );
    DS1820_WriteByte(0x48 );  

    delay_ms(10);
}



#line 575 "./..\_drv\ds1820.h"
 
sint16 DS1820_GetTempRaw(void)
{
    uint8 i;
    uint16 temp_u16;
    uint16 highres_u16;
    uint8 scrpad[9 ];

     
    DS1820_Reset();
    DS1820_AddrDevice(0x55 );      
    TRISBbits.TRISB3 = 0;(PORTBbits.RB3 = 1) ;
    DS1820_WriteByte(0x44 );    
    
    delay_ms(750) ;


     
    DS1820_Reset();
    DS1820_AddrDevice(0x55 );    
    DS1820_WriteByte(0xBE );   

     
    for (i=0; i < 9 ; i++)
    {
        scrpad[i] = DS1820_ReadByte();
    }


     
     
     

     
    temp_u16 = 0;
    temp_u16 = (uint16)((uint16)scrpad[1 ] << 8);
    temp_u16 |= (uint16)(scrpad[0 ]);

    if (nRomAddr_au8[0] == 0x10 )
    {
         
        temp_u16 >>= 1;
    
         
         
        temp_u16 = ((uint16)temp_u16 << 8);
    
         
        temp_u16 -= ((uint16)0x100  >> 2);
    
         
        highres_u16 = scrpad[7 ] - scrpad[6 ];
        highres_u16 = ((uint16)highres_u16 << 8);
        if (scrpad[7 ])
        {
            highres_u16 = highres_u16 / (uint16)scrpad[7 ];
        }
    
         
        highres_u16 = highres_u16 + temp_u16;
    }
    else
    {
         
         
        highres_u16 = temp_u16;
        highres_u16 <<= 4;
    }

    return (highres_u16);
}



#line 655 "./..\_drv\ds1820.h"
 
float DS1820_GetTempFloat(void)
{
    return ((float)DS1820_GetTempRaw() / (float)0x100 );
}



#line 670 "./..\_drv\ds1820.h"
 
void DS1820_GetTempString(sint16 tRaw_s16, char *strTemp_pc)
{
    sint16 tPhyLow_s16;
    sint8 tPhy_s8;

     
    tPhy_s8 = (sint8)(tRaw_s16/0x100 );

     
     
    tPhyLow_s16 = tRaw_s16 & 0xFF;       
                                         
    tPhyLow_s16 = tPhyLow_s16 * 100;
    tPhyLow_s16 = (uint16)tPhyLow_s16 / 0x100 ;

     
    sprintf(strTemp_pc, "%d.%02d", tPhy_s8, (sint8)tPhyLow_s16);
}

#line 691 "./..\_drv\ds1820.h"

#line 63 "ds1820demo.c"





#line 70 "ds1820demo.c"
 
void initialize()
{
     
#line 75 "ds1820demo.c"
    ADCON1 |= 0x0F;
    
     
    LATC = 0xFF;
    TRISC = 0x00;
    TRISD = 0x00;
    LATD = 0x00;

     
     
     
     
     
     
    OpenUSART(USART_TX_INT_OFF &     
              USART_RX_INT_OFF &     
              USART_ASYNCH_MODE &    
              USART_EIGHT_BIT &      
              USART_CONT_RX &        
              USART_BRGH_LOW,        
              25);                   
#line 97 "ds1820demo.c"
    

         
#line 101 "ds1820demo.c"
#line 115 "ds1820demo.c"
}



#line 121 "ds1820demo.c"
 
void main()
{
    sint16 temperature_raw;      
    float temperature_float;
    char temperature[8];         
    uint8 sensor_count;          


     
    initialize();

    printf("\n\r*** DS1820 Demo! ***\n\r");

     
    while (1)
    {
         
        LATCbits.LATC0 = 1 ;
        
        sensor_count = 0;

        if ( DS1820_FindFirstDevice() )
        {
            do
            {
                 
                temperature_raw = DS1820_GetTempRaw();

                 
                DS1820_GetTempString(temperature_raw, temperature);
                
                 
                temperature_float = DS1820_GetTempFloat();
               

                 
#line 159 "ds1820demo.c"
                printf("Sensor %d: %s°C , temperature_raw = %d)\n\r",
                       sensor_count,
                       temperature,
                       temperature_raw);
#line 164 "ds1820demo.c"

                     
#line 167 "ds1820demo.c"
#line 173 "ds1820demo.c"
                

                sensor_count ++;
            }
            while ( DS1820_FindNextDevice() );

            sensor_count = 0;
        }

         
        LATCbits.LATC0 = 0 ;
      
         
        delay_ms(2000);
    }
}

