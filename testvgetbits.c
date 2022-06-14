#include <stdio.h>
#include <stdlib.h>
#include "vgetbits.h"

int main() {

    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test of helper functions***");
    printf("%s \n", "----------------------------------------------------------------------------------------");
    
    UNSIGNED8 u8Input = 0x0A;
    UNSIGNED16 u16StartBit = 3;
    UNSIGNED16 u16BitLen = 5;
    UNSIGNED16 u16Input = 0xBA98;
    UNSIGNED16 u16Output = 0;
    UNSIGNED32 u32Output = 0;
    UNSIGNED32 u32Input = 0x0a0b0c0d;
    UNSIGNED16 u16InputArr[] = { 0x9876, 0xDCBA };
    UNSIGNED16 u16OutputArr[] = {0};

    vPrintU8BinaryHex(u8Input);
    vPrintU8BinaryHexWithDescription( "u8Input: "
        , u8Input);

    vPrintU16BinaryHex(u16Input);
    vPrintU16BinaryHexWithDescription((char*)"u16Input: "
        , u16Input);
    vSwitchItemEndian( &u16Input, &u16Output, typeU16);
    vPrintU16BinaryHexWithDescription( "u16Output after endian switching: "
        , u16Output);

    vPrintU32BinaryHexWithDescription( "u32Input: "
        , u32Input);
    vSwitchItemEndian( &u32Input, &u32Output, typeU32);

    vPrintU32BinaryHexWithDescription( "u16Output after endian switching: "
        , u32Output);

    vPrintArrayItemBinaryHex("u16InputArr",0, u16InputArr ,16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArr",1, u16InputArr,16, typeU16);

    vPrintArrayDataTypeBinaryHex( "u16InputArr", 
        2, u16InputArr, 16, typeU16);

    vSwitchArrayEndianDataType( 2,
     &u16InputArr, &u16OutputArr, typeU16);

    vPrintArrayDataTypeBinaryHex( "u16OutputArr after endian switching: ", 
        2, u16OutputArr, 16, typeU16);

    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test of helper functions - END***");
    printf("%s \n", "----------------------------------------------------------------------------------------");
    
    
 

    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test1***");
    printf("%s \n", "Input: UNSIGNED16 variable 0xBA98, StartBit = 3, BitLen = 5, Output: UNSIGNED8 variable.");
    printf("%s \n", "Expected Output value = 0x13.");
    printf("%s \n", "----------------------------------------------------------------------------------------"); 

    UNSIGNED8 u8OutputTest1 = 0;
    UNSIGNED16 u16InputTest1 = 0xBA98;
    u16StartBit = 3;
    u16BitLen =5;

    vPrintU16BinaryHexWithDescription( "Test1: u16InputTest1: "
        , u16InputTest1);
    
    vGetBits6( &u16InputTest1, typeU16
    , /* const UNSIGNED16 u16InputArrLength */1
    , /*void* const pvOutput*/ &u8OutputTest1
    , /* const enDataType eOutputDataType */typeU8
    , /* const UNSIGNED16 u16OutputArrLength */1
    , /* const UNSIGNED16 */ u16StartBit
    , /* const UNSIGNED16 */ u16BitLen 
    , /* const BOOL_T bSwitchEndian */enFALSE);

    vPrintU8BinaryHexWithDescription("Test1 : u8OutputTest1 ", u8OutputTest1);

    vGetBits6( &u16InputTest1, typeU16
    , /* const UNSIGNED16 u16InputArrLength */1
    , /*void* const pvOutput*/ &u8OutputTest1
    , /* const enDataType eOutputDataType */typeU8
    , /* const UNSIGNED16 u16OutputArrLength */1
    , /* const UNSIGNED16 */ u16StartBit
    , /* const UNSIGNED16 */ u16BitLen 
    , /* const BOOL_T bSwitchEndian */enTRUE);

     vPrintU8BinaryHexWithDescription("Test1 with switched endian : u8OutputTest1 ", u8OutputTest1);
           
    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test2***");
    printf("%s \n", "Input: array with two items {0x9876, 0xDCBA}, StartBit = 0, BitLen = 30, Output: UNSIGNED32 variable.");
    printf("%s \n", "Expected Output value = 0x1CBA9876.");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
   
    u16StartBit = 0;
    u16BitLen = 30;
    UNSIGNED16 u16InputArrTest2[] = { 0x9876, 0xDCBA };
    UNSIGNED32 u32OutputValue = 0;

    vPrintArrayDataTypeBinaryHex("Test2: u16InputArrTest2", 
    2, u16InputArrTest2, 16, typeU16);
  
    vGetBits6( u16InputArrTest2, typeU16
    ,2/* const UNSIGNED16 u16InputArrLength */
    , /*void* const pvOutput*/ &u32OutputValue, /* const enDataType eOutputDataType */typeU32
    , /* const UNSIGNED16 u16OutputArrLength */1
    , /* const UNSIGNED16 */ u16StartBit
    , /* const UNSIGNED16 */ u16BitLen 
    , /* const BOOL_T bSwitchEndian */enFALSE);
    vPrintU32BinaryHexWithDescription("Test2: u32OutputValue "
    , u32OutputValue);

    printf("%s \n", "");
    printf("%s \n", ""); 

    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test3***");
    printf("%s \n", "Input: UNSIGNED32 variable 0xFEDCBA98, StartBit = 18, BitLen = 12, Output: UNSIGNED8 array with two items.");
    printf("%s \n", "Expected Output value = {0xB7, 0x0F}");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
    u16StartBit = 18;
    u16BitLen = 12;
    UNSIGNED32 u32InputValueTest3 = 0xFEDCBA98;
    UNSIGNED8 u8OutputArrTest3 [8]; //Array size has to be 2 x Input data type - 2 x 4Bytes!!! 

  
    vPrintU32BinaryHexWithDescription( "Test3: u32InputValueTest3: "
        ,u32InputValueTest3);
   
    vGetBits6(&u32InputValueTest3, typeU32
        , 1
        , u8OutputArrTest3, typeU8
        , 2
        , u16StartBit
        , u16BitLen
        , enFALSE);
    
    vPrintArrayDataTypeBinaryHex("Test3: u8OutputArrTest3", 
        2, u8OutputArrTest3, 8, typeU8);
        
    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test4***");
    printf("%s \n", "Input: UNSIGNED8 array with three items {0x98, 0xBA, 0xDC}, StartBit = 1, BitLen = 20, Output: UNSIGNED16 array with two items.");
    printf("%s \n", "Expected Output value = {0x5D4C, 0xE}.");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
    UNSIGNED8 u8InputArrTest4[] = { 0x98, 0xBA,0xDC };
    UNSIGNED16 u16OutputArrTest4[2] = {0}; 
    u16StartBit = 1;
    u16BitLen = 20;

    vPrintArrayDataTypeBinaryHex("Test4: u8InputArrTest4", 
    3, u8InputArrTest4, 8, typeU8);

    vGetBits5(u8InputArrTest4, typeU8
        , 3
        , u16OutputArrTest4, typeU16
        , 2
        , u16StartBit
        , u16BitLen
        , enFALSE);

    vPrintArrayDataTypeBinaryHex("Test4: u16OutputArrTest4", 
    2, u16OutputArrTest4, 16, typeU16);

    printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test6***");
    printf("%s \n", "Input: UNSIGNED16 array with 2048 items with values from 1 to 2048, StartBit = 1");
    printf("%s \n", "BitLen = 20, Output: UNSIGNED16 array with two items.");
    printf("%s \n", "Expected Output value = {0x0, 0x1,0x1,0x2 ... 0x3ff, 0x3ff, 0x400}.");
    printf("%s \n", "Only 3 first and 3 last values of the input and output arrays are printed--------------");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
    UNSIGNED16 u16InputArrTest6[2048] = {0};
    UNSIGNED16 u16OutputArrTest6[2048] = {0}; 
    u16StartBit = 1;
    u16BitLen = 32767;

    for (SIGNED16 i = 0; i < 2048; i++)
    {
        u16InputArrTest6[i]=i+1;
    }

    vPrintArrayItemBinaryHex("u16InputArrTest6", 0
    , u16InputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest6", 1
    , u16InputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest6", 2
    , u16InputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest6", 2045
    , u16InputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest6", 2046
    , u16InputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest6", 2047
    , u16InputArrTest6, 16, typeU16);
    

    vGetBits5(u16InputArrTest6, typeU16
        , 2048
        , u16OutputArrTest6, typeU16
        , 2048
        , u16StartBit
        , u16BitLen
        , enFALSE);
   

    vPrintArrayItemBinaryHex("u16OutputArrTest6", 0
    , u16OutputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest6", 1
    , u16OutputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest6", 2
    , u16OutputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest6", 3
    , u16OutputArrTest6, 16, typeU16);

    vPrintArrayItemBinaryHex("u16OutputArrTest6", 2045
    , u16OutputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest6", 2046
    , u16OutputArrTest6, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest6", 2047
    , u16OutputArrTest6, 16, typeU16);


printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test7***");
    printf("%s \n", "Input: UNSIGNED16 array with 2048 items with values from 1 to 2048, StartBit = 0");
    printf("%s \n", "BitLen = 20, Output: UNSIGNED16 array with two items.");
    printf("%s \n", "Expected Output value = all the same as input values");
    printf("%s \n", "Only 3 first and 3 last values of the input and output arrays are printed--------------");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
    UNSIGNED16 u16InputArrTest7[2048] = {0};
    UNSIGNED16 u16OutputArrTest7[2048] = {0}; 
    u16StartBit = 3;
    u16BitLen = 32765;

    for (SIGNED16 i = 0; i < 2048; i++)
    {
        u16InputArrTest7[i]=i+1;
    }

    vPrintArrayItemBinaryHex("u16InputArrTest7", 0
    , u16InputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest7", 1
    , u16InputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest7", 2
    , u16InputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest7", 2045
    , u16InputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest7", 2046
    , u16InputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest7", 2047
    , u16InputArrTest7, 16, typeU16);
    

    vGetBits3(u16InputArrTest7, typeU16
        , 2048
        , u16OutputArrTest7, typeU16
        , 2048
        , u16StartBit
        , u16BitLen
        , enFALSE);
   

    vPrintArrayItemBinaryHex("u16OutputArrTest7", 0
    , u16OutputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest7", 1
    , u16OutputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest7", 2
    , u16OutputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest7", 3
    , u16OutputArrTest7, 16, typeU16);

    vPrintArrayItemBinaryHex("u16OutputArrTest7", 2045
    , u16OutputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest7", 2046
    , u16OutputArrTest7, 16, typeU16);
    vPrintArrayItemBinaryHex("u16OutputArrTest7", 2047
    , u16OutputArrTest7, 16, typeU16);

printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test8***");
    printf("%s \n", "Input: UNSIGNED16 array with 2048 items with values from 1 to 2048, StartBit = 32767");
    printf("%s \n", "BitLen = 32, Output: UNSIGNED32 array with 1024 items.");
    printf("%s \n", "Expected Output value = sll 0");
    printf("%s \n", "Only 3 first and 3 last values of the input and output arrays are printed--------------");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
    UNSIGNED16 u16InputArrTest8[2048] = {0};
    UNSIGNED32 u32OutputArrTest8[1024] = {0}; 
    u16StartBit = 0;
    u16BitLen = 1000;

    for (SIGNED16 i = 0; i < 2048; i++)
    {
        u16InputArrTest8[i]=i+1;
    }
    
    /* vSwitchArrayEndianDataType( 2048,
     u16InputArrTest8, u16InputArrTest8, typeU16);
 */
    vPrintArrayItemBinaryHex("u16InputArrTest8", 0
    , u16InputArrTest8, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest8", 1
    , u16InputArrTest8, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest8", 2
    , u16InputArrTest8, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest8", 2045
    , u16InputArrTest8, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest8", 2046
    , u16InputArrTest8, 16, typeU16);
    vPrintArrayItemBinaryHex("u16InputArrTest8", 2047
    , u16InputArrTest8, 16, typeU16);
    

    vGetBits6(u16InputArrTest8, typeU16
        , 2048
        , u32OutputArrTest8, typeU32
        , 1024
        , u16StartBit
        , u16BitLen
        , enFALSE);
   

    vPrintArrayItemBinaryHex("u32OutputArrTest8", 0
    , u32OutputArrTest8, 32, typeU32);
    vPrintArrayItemBinaryHex("u32OutputArrTest8", 1
    , u32OutputArrTest8, 32, typeU32);
    vPrintArrayItemBinaryHex("u32OutputArrTest8", 2
    , u32OutputArrTest8, 32, typeU32);
    vPrintArrayItemBinaryHex("u32OutputArrTest8", 3
    , u32OutputArrTest8, 32, typeU32);

    vPrintArrayItemBinaryHex("u32OutputArrTest8", 1021
    , u32OutputArrTest8, 32, typeU32);
    vPrintArrayItemBinaryHex("u32OutputArrTest8", 1022
    , u32OutputArrTest8, 32, typeU32);
    vPrintArrayItemBinaryHex("u32OutputArrTest8", 1023
    , u32OutputArrTest8, 32, typeU32);


printf("%s \n", "----------------------------------------------------------------------------------------");
    printf("%s \n", "***Test9***");
    printf("%s \n", "Input: {0x02, 0x01}, Output:? ");
    printf("%s \n", "BitLen = 16, StartBit 3");
    printf("%s \n", "Expected Output value = sll 0");
    printf("%s \n", "Only 3 first and 3 last values of the input and output arrays are printed--------------");
    printf("%s \n", "----------------------------------------------------------------------------------------");
   
   
    UNSIGNED8 u8InputArrTest9[] = { 0x02, 0x01 };
    UNSIGNED8 u8OutputArrTest9[2] = { 0x0, 0x0 };
    UNSIGNED16 u16OutputTest9 = 0; 
    u16StartBit = 0;
    u16BitLen = 16;

    vPrintArrayDataTypeBinaryHex("Test9: u8InputArrTest9", 
    2, u8InputArrTest9, 8, typeU8);

    vGetBits6(u8InputArrTest9, typeU8
        , 2
        , u8OutputArrTest9, typeU8
        , 2
        , u16StartBit
        , u16BitLen
        , enFALSE);

   /*  vPrintU16BinaryHexWithDescription( "u16OutputTest9: "
        , u16OutputTest9);; */
         vPrintArrayDataTypeBinaryHex("Test9: u8OutputArrTest9", 
    2, u8OutputArrTest9, 8, typeU8);

    return 0;
}

