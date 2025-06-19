# University of Colorado Boulder
## Introduction to Embedded Systems Software and Development Environments

### Peer-Assessed Coursework - C1M4
By Kristaps Ruments


In this peer-assessed assignment, I write more C-programming code to expand on the [Module 1](https://github.com/KristR/Course1-Mod1) work, and integrate code with a build system made in [Module 2](https://github.com/KristR/Course1-Mod2).


The requirements for this assignment are listed below along with the file/function those requirements apply to.

At the end, a list of assumptions for the requirements is also provided to help with interpreting some of the design choices.

## Requirements

### stats.c/stats.h Requirements

You need to modify your **print_array()** function in stats.c so that you can enable/disable debug printing with a compile time switch. This compile time switch should be enabled with a VERBOSE flag in the makefile ( -DVERBOSE ). If enabled, the print_array function should print as normal. If not defined, nothing should print. Additionally, you need to modify your use of printf to use the PRINTF macro defined in platform.h


### memory.c/memory.h Requirements

This file should already have some basic memory movement options. Now we will add some memory manipulation functions.



**uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);**

- This function takes two byte pointers (one source and one destination) and a length of bytes to move from the source location to the destination.

- The behavior should handle overlap of source and destination. Copy should occur, with no data corruption.

- All operations need to be performed using pointer arithmetic, not array indexing

- Should return a pointer to the destination (dst).



**uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);**

- This function takes two byte pointers (one source and one destination) and a length of bytes to copy from the source location to the destination.

- The behavior is undefined if there is overlap of source and destination. Copy should still occur, but will likely corrupt your data.

- All operations need to be performed using pointer arithmetic, not array indexing

- Should return a pointer to the destination (dst).



**uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);**

- This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.

- All operations need to be performed using pointer arithmetic, not array indexing

- Should return a pointer to the source (src).

- You should NOT reuse the set_all() function



**uint8_t * my_memzero(uint8_t * src, size_t length);**

- This should take a pointer to a memory location, a length in bytes and zero out all of the memory.

- All operations need to be performed using pointer arithmetic, not array indexing

- Should return a pointer to the source (src).

- You should NOT reuse the clear_all() function



**uint8_t * my_reverse(uint8_t * src, size_t length);**

- This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.

- All operations need to be performed using pointer arithmetic, not array indexing

- Should return a pointer to the source.



**int32_t * reserve_words(size_t length);**

- This should take number of words to allocate in dynamic memory

- All operations need to be performed using pointer arithmetic, not array indexing

- Should return a pointer to memory if successful, or a Null Pointer if not successful



**void free_words(int32_t * src);**

- Should free a dynamic memory allocation by providing the pointer src to the function

- All operations need to be performed using pointer arithmetic, not array indexing



### data.c/data.h Requirements

**uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)**

- Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.

- All operations need to be performed using pointer arithmetic, not array indexing

- The number you wish to convert is passed in as a signed 32-bit integer.

- You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).

- Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)

- The signed 32-bit number will have a maximum string size (Hint: Think base 2).

- You must place a null terminator at the end of the converted c-string

- Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).

- This function needs to handle signed data.

- You may not use any string functions or libraries



**int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)**

- ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.

- All operations need to be performed using pointer arithmetic, not array indexing

- The character string to convert is passed in as a uint8_t * pointer (ptr).

- The number of digits in your character set is passed in as a uint8_t integer (digits).

- You should be able to support bases 2 to 16.

- The converted 32-bit signed integer should be returned.

- This function needs to handle signed data.

- You may not use any string functions or libraries



## Assumptions

 - (for my_itoa() function) A minus sign is only shown for the output of negative base 10 numbers. The output of negative numbers which are not in base 10 is represented in 2's complement.

 - (for my_itoa() function) No leading zeros are allowed in the final output 

 - (for my_itoa() function) The null terminator and the minus sign for negative numbers are both to be counted towards the total length output.
