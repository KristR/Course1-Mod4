/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h> // for uint*_t types
#include <stdlib.h> // for size_t type and memory management functions (malloc)

#include "platform.h" // for PRINTF 		----- temporary -----

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a given number of bytes from src to dst memory address regardless of address overlap.
 *
 * Moves a number of bytes (param. 'length') from src to dst memory address while avoiding data corruption in
 * the event of memory address overlap between source and destination.
 *
 * @param src - pointer to source memory address
 * @param dst - pointer to destination memory address
 * @param length - number of bytes to be moved
 *
 * @return dst - pointer to destination memory address
 */
uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Moves a given number of bytes from src to dst memory address.
 *
 * Moves a number of bytes (param. 'length') from src to dst memory address. Does not check for memory address
 * overlap. May result in corrupted data.
 *
 * @param src - pointer to source memory address
 * @param dst - pointer to destination memory address
 * @param length - number of bytes to be moved
 *
 * @return dst - pointer to destination memory address
 */
uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Sets a given number of bytes to given value starting at src memory address.
 *
 * Sets a given number of bytes (param. 'length') to given value (param. 'value') starting at src memory address.
 *
 * @param src - pointer to memory address to begin from 
 * @param length - number of bytes to be set
 * @param value - value to set the bytes to
 *
 * @return src - pointer to memory address
 */
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value);

/**
 * @brief Sets a given number of bytes to zero value starting at src memory address.
 *
 * Sets a given number of bytes (param. 'length') to given value (0) starting at src memory address.
 *
 * @param src - pointer to memory address to begin from 
 * @param length - number of bytes to be set
 *
 * @return src - pointer to memory address
 */
uint8_t* my_memzero(uint8_t* src, size_t length);

/**
 * @brief Reverses the order of values for a given range in memory.
 *
 * Reverses the order of values for a given range in memory.
 *
 * @param src - pointer to memory address to begin from (indicating start of memory range)
 * @param length - number of bytes to be reversed (indicating end of memory range based on src start)
 *
 * @return src - pointer to memory address to begin from
 */
uint8_t* my_reverse(uint8_t* src, size_t length);

/**
 * @brief Allocates given number of words in heap memory.
 *
 * Allocates a number of words (param. 'length') to heap memory using malloc() and
 * returns the pointer to the start of the allocated memory range. 
 *
 * @param length - numer of words to allocate
 *
 * @return int32_t* - pointer to the start of the allocated memory range.
 */
int32_t* reserve_words(size_t length);

/**
 * @brief Unallocates heap memory range starting at given memory address.
 *
 * Unallocates heap memory range starting at given memory address (param. 'src').
 * 
 * @param src - pointer to the first address in memory range.
 * 
 * @return void
 */
void free_words(uint32_t* src);

#endif /* __MEMORY_H__ */
