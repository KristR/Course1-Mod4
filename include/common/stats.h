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
 * @file stats.h
 * @brief Header file for stats.c containing function prototypes and documentation.
 *
 * This file contains the declaration and documentation of the following functions:
 * - print_statistics()
 * - print_array()
 * - find_median()
 * - find_mean()
 * - find_maximum()
 * - find_minimum()
 * - sort_array()
 *
 * @author Kristaps Ruments
 * @date 27/05/2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

typedef unsigned char uchar;
typedef unsigned int  uint;

/**
 * @brief Prints given statistics to the terminal.
 *
 * Outputs the given integer arguments to console.
 *
 * @param med Unsigned 8-bit value - median value statistic.
 * @param mean Unsigned 8-bit value - mean value statistic.
 * @param min Unsigned 8-bit value - minimum value statistic.
 * @param max Unsigned 8-bit value - maximum value statistic.
 *
 * @return void - no data to return, only terminal output.
 */
void print_statistics(uchar med, uchar mean, uchar min, uchar max);

/**
 * @brief Prints a given array to the terminal.
 *
 * Given a pointer to array's first element and the array length,
 * the array is displayed in the terminal with its elements numbered
 * and formatted in four columns.
 *
 * @param pdata Pointer to the first element of an array.
 * @param len Unsigned integer value - length of the array.
 *
 * @return void - no data to return, only terminal output.
 */
void print_array(uchar *pdata, uint len);

/**
 * @brief Returns the median value of a given array.
 *
 * Given a pointer to the array's first element and the array length,
 * the array's median value is calculated and returned.
 *
 * @param pdata Pointer to the first element of an array.
 * @param len Unsigned integer value - length of the array.
 *
 * @return Unsigned character (8-bit)
 */
uchar find_median(uchar *pdata, uint len);

/**
 * @brief Returns the mean value of a given array.
 *
 * Given a pointer to the array's first element and the array lenght,
 * the array's mean value is calculated and returned.
 *
 * @param pdata Pointer to the first element of an array.
 * @param len Unsigned integer value - length of the array.
 *
 * @return Unsigned character (8-bit)
 */
uchar find_mean(uchar *pdata, uint len);

/**
 * @brief Returns the maximum value of a given array.
 *
 * Given a pointer to the array's first element and the array lenght,
 * the array's maximum value is calculated and returned.
 *
 * @param pdata Pointer to the first element of an array.
 * @param len Unsigned integer value - length of the array.
 *
 * @return Unsigned character (8-bit)
 */
uchar find_maximum(uchar *pdata, uint len);

/**
 * @brief Returns the minimum value of a given array.
 *
 * Given a pointer to the array's first element and the array lenght,
 * the array's minimum value is calculated and returned.
 *
 * @param pdata Pointer to the first element of an array.
 * @param len Unsigned integer value - length of the array.
 *
 * @return Unsigned character (8-bit)
 */
uchar find_minimum(uchar *pdata, uint len);

/**
 * @brief Sorts a given array into descending order.
 *
 * Given a pointer to the array's first element and the array lenght,
 * the array is sorted into descending order using 'bubble sort' algorithm.  
 *
 * @param pdata Pointer to the first element of an array.
 * @param len Unsigned integer value - length of the array.
 *
 * @return void - the array is sorted in its existing address range.
 */
void sort_array(uchar *pdata, uint len);

#endif /* __STATS_H__ */
