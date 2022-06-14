#include "vgetbits.h"

/*
void vGetBits(void* vInput, enDataType eInputDataType
    , UNSIGNED16 u16InputArrLength
    , void* vOutput, enDataType eOutputDataType
    , UNSIGNED16 u16OutputArrLength
    , UNSIGNED16 u16StartBit
    , UNSIGNED16 u16BitLen) {

    UNSIGNED8* pu8Output = (UNSIGNED8*)vOutput;
    UNSIGNED16* pu16Output = (UNSIGNED16*)vOutput;
    UNSIGNED32* pu32Output = (UNSIGNED32*)vOutput;
    UNSIGNED64* pu64Output = (UNSIGNED64*)vOutput;

    //Calculate new address for input after shifting whole bytes to the right
    //StartBit is specified in bits and we need movement in bytes
    UNSIGNED8* pu8Input = (UNSIGNED8*)vInput + u16StartBit / 8u;

    UNSIGNED8 u8StartBit = u16StartBit % 8u;
    UNSIGNED16 u16StartByte = u16StartBit / 8u; //maybe not needed
    UNSIGNED16 u16ByteMask = u16BitLen / 8u; // Nr.of masked bytes i.e. bytes copied 
                                             // to destination without change

    UNSIGNED8 u8BitLen = u16BitLen % 8u;     // Nr.of bits to be masked within one byte

    UNSIGNED8 u8BitMask = (1 << u16BitLen) - 1; //Masking of bits within 1 byte -not needed?
    UNSIGNED8 u16BitMask = (1 << u16BitLen) - 1; //Masking of bits within 1 byte -not needed?
    UNSIGNED8 u32BitMask = (1 << u16BitLen) - 1; //Masking of bits within 1 byte -not needed?
 
    //UNSIGNED16 u16BitMask = (1 << u8BitLen) - 1; //Masking of bits within 1 UNSIGNED16

    UNSIGNED16 u16Buff = 0;
    UNSIGNED16 u16Mask = (1 << u16BitLen) - 1;

    //!!!!!!!!!!!!!!!!
    //u16Buff = (*pu8Input << 8U | *(pu8Input+1) & u16Mask); //asi zbytocne staci urobit v cykle
    //alebo u16Buff = (*(pu8Input +1) << 8U | *pu8Input)  & u16Mask;

    u16Buff = ((*((UNSIGNED16*)vInput)) >> u8StartBit) & u8BitMask;

    UNSIGNED8* pu8Buff = (UNSIGNED8*)&u16Buff; //matching buffer addresses

    //cycle for u16BitLen / 8u number of repeats 
    for (UNSIGNED16 i = 0; i < u16ByteMask; i++)
    {
        //u16Buff = (*pu8Input << 8U | *(pu8Input + 1) & u16Mask);
        //alebo u16Buff = (*(pu8Input +1) << 8U | *pu8Input)  & u16Mask;
        u16Buff = ((*((UNSIGNED16*)vInput)) >> u8StartBit) & u8BitMask;
        *pu8Output = *pu8Buff;
        //alebo *pu8Output = *(pu8Buff + 1);
                    
        pu8Output++;
        pu8Input++;

    }
    return;
}
*/

// void vGetBits2( void* const pvInput, const enDataType eInputDataType
//     , const UNSIGNED16 u16InputArrLength
//     , void* const pvOutput, const enDataType eOutputDataType
//     , const UNSIGNED16 u16OutputArrLength
//     , const UNSIGNED16 u16StartBit
//     , const UNSIGNED16 u16BitLen 
//     , const BOOL_T bSwitchEndian ) {

//     //SIGNED16 ernum;
//     errno = 0;

//     if(pvInput == NULL || pvOutput == NULL ){
//         //ernum = errno;  
//         perror("vInput or v Output is NULL"); 
//         return;
//     }
//     else{
    
//     //UNSIGNED16 u16SizeOfInput;
//     //UNSIGNED16 u16SizeOfOutput;

//     //UNSIGNED8 u8StartBit = u16StartBit % 8u;
//     //UNSIGNED16 u16ByteMask = u16BitLen / 8u; // Nr.of masked bytes i.e. bytes copied 
     
//     //UNSIGNED16 u16Buff = 0u; 
//     UNSIGNED8* pu8In = (UNSIGNED8*)pvInput;
//     UNSIGNED8* pu8Out = (UNSIGNED8*)pvOutput; 
//     //UNSIGNED32 u32Buff = 0u;
//     //UNSIGNED64 u64Buff = 0u;

//     UNSIGNED16 u16NrInBytes = 0u;

//     UNSIGNED8 u8InArray[u16InputArrLength];
//     UNSIGNED16 u16InArray[u16InputArrLength];
//     UNSIGNED32 u32InArray[u16InputArrLength];

//     UNSIGNED8 u8OutArray[u16OutputArrLength];
//     //UNSIGNED16 u16OutArray[u16OutputArrLength];
//     //UNSIGNED32 u32OutArray[u16OutputArrLength];

//     UNSIGNED8 u8BitMask = (UNSIGNED8)((1 << u16BitLen) - 1);
//     UNSIGNED8 u8InverseBitMask = ~(UNSIGNED8)u8BitMask;

//     //UNSIGNED16 u16BitMask = (UNSIGNED16)((1 << u16BitLen) - 1); //Masking of bits within 1 UNSIGNED16
//     //UNSIGNED16 u16InverseBitMask = ~(UNSIGNED16)u16BitMask;

//     //UNSIGNED32 u32BitMask = (UNSIGNED32)((1 << u16BitLen) - 1); //Masking of bits within 1 UNSIGNED32
//     //UNSIGNED32 u32InverseBitMask = ~(UNSIGNED32)u32BitMask;

//     //UNSIGNED64 u64BitMask = (UNSIGNED64)((1 << u16BitLen) - 1); //Masking of bits within 1 UNSIGNED64
//     //UNSIGNED64 u64InverseBitMask = ~(UNSIGNED64)u64BitMask;
    
//     UNSIGNED8 u8ArrayItemRightByte = u8InArray[u16InputArrLength - 1];
//     UNSIGNED8 u8ArrayItemLeftByte = u8InArray[u16InputArrLength - 2];

 
//     //Go trough the input array from left to right
//     for (size_t i = u16InputArrLength; i > 0; i--)
//     {
//         switch (eInputDataType)
//         {
//         case typeU8:
//             u8InArray[i - u16InputArrLength] = (UNSIGNED8) (*( ( (UNSIGNED8*)pvInput)+(i-u16InputArrLength) ) );
            
//             u16NrInBytes = sizeof u8InArray;
//             if (i == 1)
//             {
//                 u16NrInBytes = sizeof u8InArray;
//                 //pu8Buff = (UNSIGNED8*) u8InArray;
               
//                 u8ArrayItemRightByte = u8InArray[u16InputArrLength - 1];
//                 if (u16InputArrLength == 1)
//                 {
//                     u8ArrayItemLeftByte = 0u;
//                 }
//                 else
//                 {
//                     u8ArrayItemLeftByte = u8InArray[u16InputArrLength - 2];
//                 }
//                 u16Buff = (u8ArrayItemRightByte & u8BitMask) | ((u8ArrayItemLeftByte & u8InverseBitMask) << 8); 
//             }                         
//             continue;
            
//         case typeU16:
//             u16InArray[i - u16InputArrLength] = (UNSIGNED32) (*( ( (UNSIGNED16*)pvInput)+(i-u16InputArrLength) ) );
//             u16NrInBytes = sizeof u16InArray;
//             if (i == 1)
//             {
//                 u16NrInBytes = sizeof u16InArray;
//                 //pu8Buff = (UNSIGNED8*) u16InArray;
//             }

//             continue;
            
//         case typeU32:
//             //u32InArray[i] = (UNSIGNED32) (*( ( (UNSIGNED32*)vInput)+i));
//             u32InArray[i - u16InputArrLength] = (UNSIGNED32) (*( ( (UNSIGNED16*)pvInput)+(i-u16InputArrLength) ) );
            
//             u16NrInBytes = sizeof u32InArray;
//             if (i == 1)
//             {
//                 u16NrInBytes = sizeof u32InArray;
//                 //pu8In = (UNSIGNED8*) u32InArray;
//             }
//             continue;

//         default:
//             break;
//         }
//     }
    
//     for ( size_t i = 0; i < u16NrInBytes; i++)
//     {
//         u16Buff = (UNSIGNED16)0u;
        
//         UNSIGNED8 u8HigherByte = (UNSIGNED8)(*(pu8In+1));
//         u8HigherByte =( (UNSIGNED8)(u8HigherByte >> u16StartBit) ) & u8InverseBitMask;
           
//         UNSIGNED8 u8LowwerByte = ( (UNSIGNED8)(((*pu8In)) >> u16StartBit) ) & u8BitMask ;

//         u8HigherByte |= u8LowwerByte;   

//         //not used    
//         //u16Buff = u8HigherByte | u8LowwerByte;

//         ((*pu8Out)) = u8HigherByte;       

//         pu8Out++;
//         pu8In++;
//         //anther posibility - to start from end, to move to the left by two bytes
//         //
//     }

//     for (size_t i = 0; i < u16OutputArrLength;  i++)
//     {
//         switch (eOutputDataType)
//         {
//         case typeU8:
//             u8OutArray[i] = (UNSIGNED8) ( *( ( (UNSIGNED8*)pvOutput)+i) );            
//             continue;
            
//         case typeU16:
//             u16OutArray[i] = (UNSIGNED16) (*( ( (UNSIGNED16*)pvOutput)+i));
//             continue; 
    
//         case typeU32:
//             u32InArray[i] = (UNSIGNED32) (*( ( (UNSIGNED32*)pvOutput)+i));
//             continue;
//         default:
//             break;
//         }
//     }
//     return;
//     }
// } //vGetBits2

/* void vPrintBinary(UNSIGNED16 u16Number, SIGNED16 u16NumDigits){
    SIGNED16 u16Digit;
    SIGNED16 count = 1;
    for(u16Digit = u16NumDigits - 1; u16Digit >= 0; u16Digit--) {
        printf("%c", u16Number & (1<< u16Digit) ? '1': '0');
        if ( (count % 4 == 0)) 
        {
            printf("%c", ' ');
        }
        count++;       
    }
} */ 

void vPrintDataTypeBinary(const void* puNumber, SIGNED16 u16NumDigits, enDataType eDataType){
    SIGNED16 u16Digit;
    SIGNED16 count = 1;

    for(u16Digit = u16NumDigits - 1; u16Digit >= 0; u16Digit--) {
        switch (eDataType)
        {
        case typeU8:
            printf("%c", *((UNSIGNED8*)puNumber) & (1<< u16Digit) ? '1': '0');
            break;
        case typeU16:
            printf("%c", *((UNSIGNED16*)puNumber) & (1<< u16Digit) ? '1': '0');
            break;
        case typeU32:
            printf("%c", *((UNSIGNED32*)puNumber) & (1<< u16Digit) ? '1': '0');
            break;                       
        default:
            break;
        }
        if ( (count % 4 == 0)) 
        {
            printf("%c", ' ');
        }
        count++;
    }        
} //vPrintDataTypeBinary

void vPrintDataTypeBinaryHex(const void* puNumber, SIGNED16 u16NumDigits, enDataType eDataType){
    //SIGNED16 u16Digit;
    //SIGNED16 count = 1;

    switch (eDataType)
    {
    case typeU8:
        vPrintU8BinaryHex(*((UNSIGNED8*)puNumber));
        break;
    case typeU16:
        vPrintU16BinaryHex(*((UNSIGNED16*)puNumber));
        break;
    case typeU32:
        vPrintU32BinaryHex(*((UNSIGNED32*)puNumber));
        break;                       
    default:
        break;
    }
            
} //vPrintDataTypeBinaryHex

void vPrintU8Binary(const UNSIGNED8 u8Number){
   
    vPrintDataTypeBinary(&u8Number, 8u, typeU8);
}//vPrintU8Binary

void vPrintU8BinaryHex(UNSIGNED8 u8Number){
    vPrintU8Binary(u8Number);
    printf("%s%x \n", " Hex: ", u8Number);
} //vPrintU8BinaryHex

void vPrintU8BinaryHexWithDescription(const void* pu8Description
    , UNSIGNED8 u8Number){
    printf("%s ", (char*)pu8Description);
    vPrintU8Binary(u8Number);
    printf("%s%x \n", " Hex: ", u8Number);
} //vPrintU8BinaryHexWithDescription


////////////U16/////////////////////////////////
void vPrintU16Binary(const UNSIGNED16 u16Number){
   
    vPrintDataTypeBinary(&u16Number, 16u, typeU16);
} //vPrintU16Binary

void vPrintU16BinaryHex(UNSIGNED16 u16Number){
    vPrintU16Binary(u16Number);
    printf("%s%x \n", " Hex: ", u16Number);
} //vPrintU16BinaryHex

void vPrintU16BinaryHexWithDescription(const UNSIGNED8* pu8Description
    , UNSIGNED16 u16Number){
    printf("%s ", pu8Description);
    vPrintU16Binary(u16Number);
    printf("%s%x \n", " Hex: ", u16Number);
} //vPrintU16BinaryHexWithDescription

/////////////////U32////////////////////////////
void vPrintU32Binary(const UNSIGNED32 u32Number){  
    vPrintDataTypeBinary(&u32Number, 32u, typeU32);
} //vPrintU32Binary

void vPrintU32BinaryHex(UNSIGNED32 u32Number){
    vPrintU32Binary(u32Number);
    printf("%s%lx \n", " Hex: ", u32Number);
} //vPrintU32BinaryHex

void vPrintU32BinaryHexWithDescription(const UNSIGNED8* pu8Description
    , UNSIGNED32 u32Number){
    printf("%s ", pu8Description);
    vPrintU32Binary(u32Number);
    printf("%s%lx \n", " Hex: ", u32Number);
} //

/////////////Array/////////////////////////
void vPrintArrayItemBinaryHex(const UNSIGNED8* puArrName, SIGNED16 u16Index
    , const void* pvArray, SIGNED16 u16NumDigits, enDataType eDataType) {

       printf("%s%s%d%s ", puArrName, "[", u16Index,"]: "); 
       
       if ( eDataType == typeU8)
       {
           vPrintDataTypeBinaryHex(pvArray+u16Index, u16NumDigits, eDataType); 
       }
       else if (eDataType == typeU16)
       {
           vPrintDataTypeBinaryHex(pvArray + 2*u16Index, u16NumDigits, eDataType);
       }
       else if (eDataType == typeU32)
        {
           vPrintDataTypeBinaryHex(pvArray + 4*u16Index, u16NumDigits, eDataType);
       }
       
}

void vPrintArrayDataTypeBinaryHex(const UNSIGNED8* puArrName, 
    SIGNED16 u16ArrSize, const void* pvArray, SIGNED16 u16NumDigits, enDataType eDataType){
   
    printf("%s", "----------------------------------------------\n" );
    printf("%s%s%s", "Array: *** ", puArrName, " ***\n" );
    printf("%s", "----------------------------------------------\n" );
    for (SIGNED16 i = 0; i < u16ArrSize; i++)
    {
        vPrintArrayItemBinaryHex(puArrName, i, 
            pvArray, u16NumDigits, eDataType);
    }
}

void vSwitchItemEndian( const void* pvInputItem, const void* pvOutputItem
    , enDataType eDataType) {
         
    if (eDataType == typeU16)
    {
    *((UNSIGNED16*)pvOutputItem) = (*((UNSIGNED16*)pvInputItem) >>8) | (*((UNSIGNED16*)pvInputItem)<<8);
    //UNSIGNED16 temp = *((UNSIGNED16*)pvOutputItem);
    }
    else if (eDataType == typeU32)
    {
        *((UNSIGNED32*)pvOutputItem) = (*((UNSIGNED32*)pvInputItem) >>8) | (*((UNSIGNED16*)pvInputItem)<<8);
    //UNSIGNED16 temp = *((UNSIGNED16*)pvOutputItem);

    *((UNSIGNED32*)pvOutputItem) = ((*((UNSIGNED32*)pvInputItem)>>24) & 0xff) | // move byte 3 to byte 0
            ((*((UNSIGNED32*)pvInputItem) << 8) & 0xff0000) | // move byte 1 to byte 2
            ((*((UNSIGNED32*)pvInputItem) >> 8) & 0xff00) |   // move byte 2 to byte 1
            ((*((UNSIGNED32*)pvInputItem)<<24) & 0xff000000); // byte 0 to byte 3
    }          
}

void vSwitchArrayEndianDataType( SIGNED16 u16ArrSize
    , const void* pvInputItem, const void* pvOutputItem, enDataType eDataType){   
       
    for (SIGNED16 i = 0; i < u16ArrSize; i++)
    {
        if (eDataType == typeU16)
        {
            vSwitchItemEndian( pvInputItem, pvOutputItem
                , eDataType);
            pvInputItem +=2;
            pvOutputItem +=2;
        }
        else if (eDataType == typeU32)
        {
           vSwitchItemEndian( pvInputItem, pvOutputItem
                , eDataType);
            pvInputItem +=4;
            pvOutputItem += 4;
        }
        else { //U8    
            pvInputItem +=1;
            pvOutputItem +=1;
        }             
    }
}

void vGetBits3( void* const pvInput, const enDataType eInputDataType
    , const UNSIGNED16 u16InputArrLength
    , void* const pvOutput, const enDataType eOutputDataType
    , const UNSIGNED16 u16OutputArrLength
    , const UNSIGNED16 u16StartBit
    , const UNSIGNED16 u16BitLen 
    , const BOOL_T bSwitchEndian ){ 

    
    errno = 0;

    if(pvInput == NULL || pvOutput == NULL ){
        /* SIGNED16 ernum;
        ernum = errno;   */
        perror("vInput or v Output is NULL"); 
        return;
    }

    UNSIGNED16 u16ItemCounter = 0;

    UNSIGNED8 u8BitMask = (UNSIGNED8)((1 << ( u16BitLen % 8)) - 1);
    UNSIGNED16 u16BitMask = (UNSIGNED16)((1 << (u16BitLen % 16)) - 1);
    UNSIGNED32 u32BitMask = (UNSIGNED32)((1 << (u16BitLen % 32)) - 1);
    UNSIGNED32 u32BitItem = 0;
    
    //u16InputArrLength is length of the input array that 
    //has items with different length. In one cycle can be 
    //processed 1, 2 or 4 bytes acording to data type
    //of the array item 
    for (SIGNED16 i = (SIGNED16)u16InputArrLength; i > 0; i--)
    {
       if ( eInputDataType == typeU8)
       {
           *((UNSIGNED8*)(pvOutput +i -1)) =
           
            (u16ItemCounter == 0u) ? 
            ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8)) & u8BitMask :
            ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8));
            u16ItemCounter++;
       }
       else if (eInputDataType == typeU16)
       {
           *((UNSIGNED16*)(pvOutput + (i -1)*2)) = 
            (u16ItemCounter == 0u) ?
                ( (*((UNSIGNED16*)(pvInput + (i -1)*2))) >> (u16StartBit % 16) ) & u16BitMask :
                ( (*((UNSIGNED16*)(pvInput + (i -1)*2))) >> (u16StartBit % 16) );
            u16ItemCounter++;
       }
       else if (eInputDataType == typeU32)
       {
            u32BitItem =
            (u16ItemCounter == 0u) ?
            ((*((UNSIGNED32*)(pvInput + (i -1)*4))) >> (u16StartBit % 32)) & u32BitMask :
            ((*((UNSIGNED32*)(pvInput + (i -1)*4))) >> (u16StartBit % 32));

            *((UNSIGNED32*)(pvOutput + (i -1)*4 )) = u32BitItem;
            u16ItemCounter++;      
       }
    }
}

//with endian switching
void vGetBits5( void* const pvInput, const enDataType eInputDataType
, const UNSIGNED16 u16InputArrLength
, void* const pvOutput, const enDataType eOutputDataType
, const UNSIGNED16 u16OutputArrLength
, const UNSIGNED16 u16StartBit
, const UNSIGNED16 u16BitLen 
, const BOOL_T bSwitchEndian )

{
    //SIGNED16 ernum;
    errno = 0;

    if(pvInput == NULL || pvOutput == NULL ){//TODO Test other arguments 
        SIGNED16 ernum = errno;  
        perror("vInput or v Output is NULL"); 
    return;
    }

    UNSIGNED16 u16ItemCounter = 0;

    UNSIGNED8 u8BitMask = (UNSIGNED8)((1 << ( u16BitLen % 8)) - 1);
    UNSIGNED16 u16BitMask = (UNSIGNED16)((1 << (u16BitLen % 16)) - 1);
    UNSIGNED32 u32BitMask = (UNSIGNED32)((1 << (u16BitLen % 32)) - 1);
    
    //u16InputArrLength is length of the input array that 
    //has items with different length. In one cycle  
    //processed 1, 2 or 4 bytes can be processed acording to data type
    //of the array item 
    for (SIGNED16 i = (SIGNED16)u16InputArrLength; i > 0; i--)
    {
       if ( eInputDataType == typeU8)
       {
           *((UNSIGNED8*)(pvOutput +i -1)) =
           
            (u16ItemCounter == 0u) ? 
            ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8)) & u8BitMask :
            ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8));
           
       }
       else if (eInputDataType == typeU16)
       {
            UNSIGNED16 u16Buff = 0;
            if (bSwitchEndian) {      
                vSwitchItemEndian( (UNSIGNED16*)(pvInput + (i -1)*2), &u16Buff
                , eInputDataType);
            }
            else {
                u16Buff = (*((UNSIGNED16*)(pvInput + (i -1)*2)));
            }

            *((UNSIGNED16*)(pvOutput + (i -1)*2)) = 
            (u16ItemCounter == 0u) ?
                ( u16Buff >> (u16StartBit % 16) ) & u16BitMask :
                ( u16Buff >> (u16StartBit % 16) ); 
       }
       else if (eInputDataType == typeU32)
       {
            UNSIGNED16 u32Buff = 0;
            if (bSwitchEndian) {      
                vSwitchItemEndian( (UNSIGNED32*)(pvInput + (i -1)*4), &u32Buff
                , eInputDataType);
            }
            else {
                u32Buff = (*((UNSIGNED32*)(pvInput + (i -1)*4)));
            }

            *((UNSIGNED32*)(pvOutput + (i -1)*4)) = 
            (u16ItemCounter == 0u) ?
                ( u32Buff >> (u16StartBit % 32) ) & u32BitMask :
                ( u32Buff >> (u16StartBit % 32) );
                 
       }
        u16ItemCounter++;
    }
    return;
}

//with endian switching
void vGetBits6( void* const pvInput, const enDataType eInputDataType
, const UNSIGNED16 u16InputArrLength
, void* const pvOutput, const enDataType eOutputDataType
, const UNSIGNED16 u16OutputArrLength
, const UNSIGNED16 u16StartBit
, const UNSIGNED16 u16BitLen 
, const BOOL_T bSwitchEndian )

{
    //SIGNED16 ernum;
    errno = 0;

    if(pvInput == NULL || pvOutput == NULL ){//TODO test function arguments
        SIGNED16 ernum = errno;  
        perror("vInput or v Output is NULL"); 
    return;
    }

    UNSIGNED16 u16ItemCounter = 0;

    UNSIGNED8 u8BitMask = ( u16BitLen % 8) == 0 ? 0xff : (UNSIGNED8)((1 << ( u16BitLen % 8)) - 1);
    UNSIGNED16 u16BitMask = ( u16BitLen % 16) == 0 ? 0xffff :(UNSIGNED16)((1 << (u16BitLen % 16)) - 1);
    UNSIGNED32 u32BitMask = ( u16BitLen % 32) == 0 ? 0xffffffff : (UNSIGNED32)((1 << (u16BitLen % 32)) - 1);
    
    //If StartBit is bigger than item length then some items
    //have to be skiped 
    UNSIGNED16 u16BajtMask = (UNSIGNED16)(u16StartBit / 8);
    /* if (u16BajtMask * 8 < u16StartBit)
    {
        u16BajtMask++;
    } */

    UNSIGNED16 u16TwoBajtMask = (UNSIGNED16)(u16StartBit / 16);
    /* if (u16TwoBajtMask * 16 < u16StartBit)
    {
        u16TwoBajtMask++;
    } */
    UNSIGNED16 u16FourBajtMask = (UNSIGNED16)(u16StartBit / 32);
    /* if (u16FourBajtMask * 32 < u16StartBit)
    {
        u16FourBajtMask++;
    } */

   /*  if (eOutputDataType == typeU16){
        UNSIGNED16 j = u16BitLen/16;}

    pu8OutputEnd =  u16BitLen/8 
 */
    UNSIGNED8* pu8OutputEnd = (UNSIGNED8*)(pvOutput + u16BitLen/8 + ((u16BitLen%8 == 0) ? 0:1)) ;
    UNSIGNED16* pu16OutputEnd = (UNSIGNED16*)(pvOutput + u16BitLen/16 + ((u16BitLen%16 == 0) ? 0:1));
    UNSIGNED32* pu32OutputEnd = (UNSIGNED32*)(pvOutput + u16BitLen/32 + ((u16BitLen%32 == 0) ? 0:1));

    //u16InputArrLength is length of the input array that 
    //has items with different length. In one cycle can be 
    //processed 1, 2 or 4 bytes acording to data type
    //of the array item 
    for (SIGNED16 i = (SIGNED16)u16InputArrLength; i > 0; i--)
    {
       if ( eInputDataType == typeU8)
       {
            //if StartBit is > then length of input array in bytes
            // then u16BajtMask bytes from back can be skiped and so 
            // processing starts on pvInput +i - u16BajtMask
                          
            //take two bytes to move bits from next item to the previous
            if (i-2 >= 0)
            {
                UNSIGNED16 u16Buff =
                    (UNSIGNED16)((*((UNSIGNED16*)(pvInput + i - u16BajtMask - 2))) >> (u16StartBit % 8));
                UNSIGNED8 u8Buff1 = ((UNSIGNED8)(u16Buff & 0x00ff));
                // UNSIGNED8 u8Buff1 = ((UNSIGNED8)(u16Buff & 0x00ff)) & u8BitMask;
                UNSIGNED8 u8Buff2 = (UNSIGNED8)(u16Buff >> 8) ;
                *((UNSIGNED8*)(pu8OutputEnd -2)) = u8Buff1; 
                //if there is not more bytes then it is not possible to transferr 
                //bytes from next byte and so only copy the second byte   
                if ((i-2)==0)
                {
                    // *((UNSIGNED8*)(pu8OutputEnd-1)) = u8Buff2 & u8BitMask;
                     *((UNSIGNED8*)(pu8OutputEnd-1)) = u8Buff2;
                     pu8OutputEnd--; 
                }
                   
                pu8OutputEnd--;
            }
            else
            {
               /*  *((UNSIGNED8*)(pu8OutputEnd-1)) =  (u16ItemCounter == 0u) ? 
                    ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8)) & u8BitMask :
                    ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8)); */
                 //*((UNSIGNED8*)(pvOutput +i -1)) =
                *((UNSIGNED8*)(pu8OutputEnd-1)) =
                    (u16ItemCounter == 0u) ? 
                    ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8)) & u8BitMask :
                    ((*((UNSIGNED8*)(pvInput +i -1))) >> (u16StartBit % 8));
            
                pu8OutputEnd--;
            }      
       }
       else if (eInputDataType == typeU16)
       {
           //take 4 bytes to move bits from next item to the previous
            if (i-4 >= 0)
            {
                UNSIGNED32 u32Buff = 
                    (UNSIGNED32)((*((UNSIGNED32*)(pvInput +i - 4 - u16TwoBajtMask))) >> (u16StartBit % 16));
                UNSIGNED16 u16Buff1 = (UNSIGNED16)(u32Buff & 0x0000ffff) & u16BitMask ;
                UNSIGNED16 u16Buff2 = (UNSIGNED8)(u32Buff >> 16) ;
                *((UNSIGNED16*)(pu16OutputEnd -4)) = u16Buff1; 
                //if there is not more items then it is not possible to transferr 
                //bits from next item and so copy only the second item   
                if ((i-4)==0)
                    *((UNSIGNED16*)(pu16OutputEnd-2)) = u16Buff2 & u16BitMask; 
                pu16OutputEnd -= 2;
            }
            else
            {
                UNSIGNED16 u16Buff = 0;
                if (bSwitchEndian) {      
                    vSwitchItemEndian( (UNSIGNED16*)(pvInput + (i -1)*2), &u16Buff
                    , eInputDataType);
                }
                else {
                    u16Buff = (*((UNSIGNED16*)(pvInput + (i -1)*2)));
                }

                *((UNSIGNED16*)(pvOutput + (i -1)*2)) = 
                (u16ItemCounter == 0u) ?
                    ( u16Buff >> (u16StartBit % 16) ) & u16BitMask :
                    ( u16Buff >> (u16StartBit % 16) );  
            }
            
           
       }
       else if (eInputDataType == typeU32)
       {
           //take 8 bytes to move bits from next item to the previous
            if (i-8 >= 0)
            {
                UNSIGNED64 u64Buff = 
                    (UNSIGNED64)((*((UNSIGNED64*)(pvInput +i - 8 - u16FourBajtMask))) >> (u16StartBit % 32));
                UNSIGNED32 u32Buff1 = (UNSIGNED32)(u64Buff & 0x00000000ffffffff) & u32BitMask ;
                UNSIGNED32 u32Buff2 = (UNSIGNED8)(u64Buff >> 32) ;
                *((UNSIGNED16*)(pu32OutputEnd -2)) = u32Buff1;//TODO error?
                //if there is not more items then it is not possible to transferr 
                //bits from next item and so only copy the second item to output array  
                if ((i-8)==0)
                    *((UNSIGNED16*)(pu32OutputEnd-2)) = u32Buff2 & u32BitMask; 
                pu32OutputEnd -= 4;
            }
            else
            {
                UNSIGNED32 u32Buff = 0;
                if (bSwitchEndian) {      
                    vSwitchItemEndian( (UNSIGNED32*)(pvInput + (i -1)*4), &u32Buff
                    , eInputDataType);
                }
                else {
                    u32Buff = (*((UNSIGNED32*)(pvInput + (i -1)*4)));
                }

                *((UNSIGNED32*)(pvOutput + (i -1)*4)) = 
                (u16ItemCounter == 0u) ?
                    ( u32Buff >> (u16StartBit % 32) ) & u32BitMask :
                    ( u32Buff >> (u16StartBit % 32) );
            }
       }
        u16ItemCounter++; //asi netreba
    }
    return;
}


SIGNED16 s16GetArrayLenght( const enDataType eOutputDataType
, const UNSIGNED16 u16BitLen) {
    if (eOutputDataType == typeU8)
    {
        return (SIGNED16)
            ((u16BitLen%8 == 0) ? u16BitLen / 8 : (u16BitLen / 8 + 1));
      
    }
    else if (eOutputDataType == typeU16)
    {
         return (SIGNED16)
            ((u16BitLen%16 == 0) ? u16BitLen / 16 : (u16BitLen / 16 + 1));
    }
    else
    {
        return (SIGNED16)
            ((u16BitLen%32 == 0) ? u16BitLen / 32 : (u16BitLen / 32 + 1));
    }   
}


    






