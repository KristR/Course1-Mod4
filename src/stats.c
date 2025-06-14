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
 * @file stats.c
 * @brief Processes and displays statistics on an array of numbers.
 *
 * Given an array of unsigned 8-bit integers, this program calculates the
 * median, mean, maximum and minimum value of the array before sorting the
 * array into a descending order and displaying the results in the terminal.
 *
 * This file contains the definition and use of the following functions:
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

#include <stdio.h>
#include <stdbool.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  uchar median = find_median(test, SIZE);
  uchar mean = find_mean(test, SIZE);
  uchar min = find_minimum(test, SIZE);
  uchar max = find_maximum(test, SIZE);

  print_statistics(median, mean, min, max);

  printf("\n==== Unsorted dataset ====\n");
  print_array(test, SIZE);

  sort_array(test, SIZE);
  
  printf("\n==== Sorted dataset ====\n");
  print_array(test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(uchar med, uchar mean, uchar min, uchar max)
{
  printf("\n==== Dataset statistics ====\n"
         "Median: %d\nMean: %d\nMinimum: %d\nMaximum: %d\n", med, mean, min, max);
}

void print_array(uchar *pdata, uint len)
{
	if( (pdata != NULL) &&
	    (len > 0) )
	{
	  for( uchar index = 0; index < len; index++ )
	  {
	    if( (index == 0) ||
	        (index % 4 == 0) )
	    {
	      printf("%d) %d", index + 1, *(pdata + index));
	    }
	    else
	    {
	      printf("\t\t%d) %d", index + 1, *(pdata + index));
	    }

	    if( (index + 1) % 4 == 0 )
	    {
	      printf("\n");
	    }
	  }

	  printf("\n");
	}
}

uchar find_median(uchar *pdata, uint len)
{
	if( (pdata != NULL) &&
	    (len > 0) )
	{
	  uchar medianArray[len];

	  for( uchar index = 0; index < len; index++ )
	  {
	    medianArray[index] = *(pdata + index);
	  }

	  sort_array(medianArray, len);

	  uchar middle;

	  if( len % 2 == 0 )
	  {
	    middle = len / 2;
	  }
	  else
	  {
	    middle = (len + 1) / 2;
	  }

	  return medianArray[middle];
	}
}

uchar find_mean(uchar *pdata, uint len)
{
	if( (pdata != NULL) &&
	    (len > 0) )
	{
	  uint result = 0;

	  for( uchar index = 0; index < len; index++ )
	  {
	    result += *(pdata + index);
	  }

	  return result / len;
	}
}

uchar find_maximum(uchar *pdata, uint len)
{
	if( (pdata != NULL) &&
	    (len > 0) )
	{
	  uchar result = 0;

	  for( uchar index = 0; index < len; index++ )
	  {
	    if( *(pdata + index) > result )
	    {
	      result = *(pdata + index);
	    }
	  }

	  return result;
	}
}

uchar find_minimum(uchar *pdata, uint len)
{
	if( (pdata != NULL) &&
	    (len > 0) )
	{
	  uchar result = *pdata; // Take the first array element for comparison

	  for( uchar index = 0; index < len; index++ )
	  {
	    if( *(pdata + index) < result )
	    {
	      result = *(pdata + index);
	    }
	  }

	  return result;
	}
}

void sort_array(uchar *pdata, uint len)
{
	if( (pdata != NULL) &&
	    (len > 0) )
	{
	  uchar buffer;
	  bool swapFlag = true;

	  while( swapFlag == true )
	  {
	    swapFlag = false;

	    /* Parameter 'len' in the conditional expression is offset by 1 so
	       that we do not index outside of the array. */
	    for( uchar index = 0; index < len - 1; index++ )
	    {
	      uchar *pCurrent = pdata + index;
	      uchar *pNext = pdata + index + 1;

	      if( *pCurrent > *pNext )
	      {
	        swapFlag  = true;
	        buffer    = *pCurrent;
	        *pCurrent = *pNext;
	        *pNext    = buffer;
	      }
	    }
	  }
	}
}
