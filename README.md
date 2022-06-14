# movebits

Function **vGetBits** for reading a sequence of bits from provided input and returning them to the provided output.

Function accepts input and output objects in form of a simple variable address or arrayname. Following data types are supported:
UNSIGNED8 - unsigned char,
UNSIGNED16 - unsigned short,
UNSIGNED32 - unsigned long.

The test application verifies inputs and outputs in various formats - as variables with a maximum length of 32 bits or as fields with different lengths containing different data types (UNSIGNED8, UNSIGNED16, UNSIGNED32). Before transforming data from input to output, endian of input data is switched when the parameter *bSwitchEndian* is set to enTRUE.  For each test, a separate calculation is performed within the test application, as well as a test using the function

```c
void vGetBits (void *vInput, enDataType eInputDataType
     , UNSIGNED16 u16InputArrLength
     , void *vOutput, enDataType eOutputDataType
     , UNSIGNED16 u16OutputArrLength
     , UNSIGNED16 u16StartBit
     , UNSIGNED16 u16BitLen
     , BOOL_T bSwitchEndian );
```

The result of the function processing is passed via the *vOutput* pointer.  The test application shows how it is possible to transform such a result into an array and at the same time show a match between the processing result in the application and in the function.

*StartBit* specifies the position of a first bit in the Input from which the bit sequence shall be read. 0 = lowest significant bit in the Input. StartBit should support range 0 - 32767.

*BitLen* specifies the number of bits that shall be read counting from the start bit. BitLen should support range 1 - 32767.

The function does not provide memory allocation. It has to be provided in calling function e.g. as provided in the main function in testgetbits.c.

The test application contains set of helper functions for displaying input and output arrays and variables in binary and hexadecimal format as well as function for switching of endian. 



# How to overtake and test the project

1. Go to [https://github.com/vpalacka/movebits](https://github.com/vpalacka/movebits)
2. Download movebits-main.zip
3. Unpack content of the zip to a directory
4. Switch to the directory where you copied it.
5. Call *make* from the directory
6. Call executable  *./testvgetbits*

You can also clone project using:

 *git clone* [*https://github.com/vpalacka/movebits.git*](https://github.com/vpalacka/movebits.git)


