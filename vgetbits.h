#ifndef VGETBITS_H
#define VGETBITS_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "data_types.h"


typedef enum { typeU8, typeU16, typeU32 } enDataType;

void vGetBits(void* vInput, enDataType eInputDataType
    , UNSIGNED16 u16InputArrLength
    , void* vOutput, enDataType eOutputDataType
    , UNSIGNED16 u16OutputArrLength
    , UNSIGNED16 u16StartBit
    , UNSIGNED16 u16BitLen);

void vGetBits2(void* vInput, enDataType eInputDataType
    , UNSIGNED16 u16InputArrLength
    , void* vOutput, enDataType eOutputDataType
    , UNSIGNED16 u16OutputArrLength
    , UNSIGNED16 u16StartBit
    , UNSIGNED16 u16BitLen 
    , BOOL_T bSwitchEndian );

void vPrintDataTypeBinary(const void* puNumber, SIGNED16 u16NumDigits, enDataType eDataType);
void vPrintU8Binary(const UNSIGNED8 u8Number);
void vPrintU8BinaryHex(UNSIGNED8 u8Number);
void vPrintU8BinaryHexWithDescription(const void* pu8Description, UNSIGNED8 u8Number);


//void vPrintBinary(UNSIGNED16 u16Number, SIGNED16 u16NumDigits);
void vPrintDataTypeBinary(const void* puNumber, SIGNED16 u16NumDigits, enDataType eDataType);
void vPrintU16Binary(UNSIGNED16 u16Number);
void vPrintU16BinaryHex(UNSIGNED16 u16Number);
void vPrintU16BinaryHexWithDescription(const UNSIGNED8* pu8Description
    , UNSIGNED16 u16Number);

void vPrintU32Binary(const UNSIGNED32 u32Number);
void vPrintU32BinaryHex(UNSIGNED32 u32Number);
void vPrintU32BinaryHexWithDescription(const UNSIGNED8* pu8Description
    , UNSIGNED32 u32Number);

void vPrintArrayItemBinary(const UNSIGNED8* puArrName, SIGNED16 u16Index
    , const void* pvItem, SIGNED16 u16NumDigits, enDataType eDataType);

void vPrintDataTypeBinaryHex(const void* puNumber
    , SIGNED16 u16NumDigits, enDataType eDataType);

void vPrintArrayItemBinary(const UNSIGNED8* puArrName, SIGNED16 u16ArrSize
    , const void* pvItem, SIGNED16 u16NumDigits, enDataType eDataType);
    
void vPrintArrayItemBinaryHex(const UNSIGNED8* puArrName, SIGNED16 u16Index
    , const void* pvArray, SIGNED16 u16NumDigits, enDataType eDataType);

void vPrintArrayDataTypeBinaryHex(const UNSIGNED8* puArrName, 
    SIGNED16 u16ArrSize, const void* pvArray, SIGNED16 u16NumDigits, enDataType eDataType);

void vSwitchItemEndian( const void* pvInputItem, const void* pvOutputItem
    , enDataType eDataType);

/* void vSwitchArrayDataTypeEndian(const UNSIGNED8* puArrName, 
    SIGNED16 u16ArrSize, const void* pvInputItem, const void* pvOutputItem, enDataType eDataType); */

void vSwitchArrayEndianDataType( SIGNED16 u16ArrSize
    , const void* pvInputItem, const void* pvOutputItem, enDataType eDataType);

/* void vMoveArrayToStartBit( UNSIGNED16 u16StartBit, UNSIGNED16 u16BitLen
    , SIGNED16 u16ArrSize, const void* pvInputItem
    , const void* pvOutputItem, enDataType eDataType); */

void vGetBits3( void* const pvInput, const enDataType eInputDataType
    , const UNSIGNED16 u16InputArrLength
    , void* const pvOutput, const enDataType eOutputDataType
    , const UNSIGNED16 u16OutputArrLength
    , const UNSIGNED16 u16StartBit
    , const UNSIGNED16 u16BitLen 
    , const BOOL_T bSwitchEndian );

void vGetBits4( void* const pvInput, const enDataType eInputDataType
    , const UNSIGNED16 u16InputArrLength
    , void* const pvOutput, const enDataType eOutputDataType
    , const UNSIGNED16 u16OutputArrLength
    , const UNSIGNED16 u16StartBit
    , const UNSIGNED16 u16BitLen 
    , const BOOL_T bSwitchEndian );

void vSaveBytes(void* const pvInput, const enDataType eInputDataType
    , UNSIGNED16 u8NrBytes
    , UNSIGNED8* const pvOutput );

void vGetBits5( void* const pvInput, const enDataType eInputDataType
    , const UNSIGNED16 u16InputArrLength
    , void* const pvOutput, const enDataType eOutputDataType
    , const UNSIGNED16 u16OutputArrLength
    , const UNSIGNED16 u16StartBit
    , const UNSIGNED16 u16BitLen 
    , const BOOL_T bSwitchEndian );
    
void vGetBits6( void* const pvInput, const enDataType eInputDataType
    , const UNSIGNED16 u16InputArrLength
    , void* const pvOutput, const enDataType eOutputDataType
    , const UNSIGNED16 u16OutputArrLength
    , const UNSIGNED16 u16StartBit
    , const UNSIGNED16 u16BitLen 
    , const BOOL_T bSwitchEndian );

SIGNED16 s16GetArrayLenght( const enDataType eOutputDataType
, const UNSIGNED16 u16BitLen);

#endif /* VGETBITS_H */