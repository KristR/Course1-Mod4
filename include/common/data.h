/**
 * @file data.h
 * @brief [brief]
 *
 * [desc]
 *
 * @author Kristaps Ruments
 * @date June 16 2025
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h> // for uint*_t types


/**
 * @brief Converts a signed 32-bit integer to an ASCII character string encoded in base 2 to 16.
 *
 * Converts a signed 32-bit integer to an ASCII character string. The base in which the output
 * number is to be represented in should be provided in parameter 'base'. 
 * Bases 2 to 16 (inclusive) are supported. Resulting string is written into a buffer
 * starting at the given memory address (param. 'ptr').
 *
 * @param data - signed 32-bit integer to be converted
 * @param ptr - starting address of buffer to write the result to
 * @param base - base number to represent the integer in
 *
 * @return len - total length of ASCII string (inluding the null-terminator and minus sign for negatives)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts a given ASCII string of base 2 to 16 number to a signed 32-bit integer.
 *
 * Converts a given ASCII string of base 2 to 16 number to a signed 32-bit integer.
 * The base in which the input number is represented should be given in parameter 'base'.
 * The string will be read starting from the memory address given in parameter 'ptr'.
 * Bases 2 to 16 (inclusive) are supported. Resulting decoded integer will be returned
 * as a signed 32-bit integer. 
 *
 * @param ptr - starting memory address of string buffer
 * @param digits - number of digits in the ASCII string
 * @param base - base in which the ASCII string is represented in 
 *
 * @return result - decoded result as a signed 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
