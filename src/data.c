#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "stats.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t loop = 0;
  uint8_t len = 0;
  uint8_t buf[30];
  uint8_t* pBuf = buf;

  // Convert int32 to ASCII string (base 10)
  if(base == 10)
  {
    if(data < 0)
    {
      data = data * -1; // Convert negative number to positive
      *ptr = '-';       // Add '-' to the start of the output
      ptr++;            // Move onto the next 'index' in final output
      len++;            // Increase total output length by one
    }
    while(data != 0)
    {
      *pBuf = (data % 10) + '0'; // Store least-significant digit at given memory address as a string character
      data = data / 10;          // 'Remove' least-significant digit from data integer
      pBuf++;                    // Move onto the next 'index' in buffer
      loop++;                    // Increase loop counter by one;
      len++;                     // Increase total output length by one;
    }
  }

  // Reverse buffer content into ptr array
  for(uint8_t i = 0; i < loop; i++)
  {
    printf("yahoo\n");
    *(ptr + i) = *(pBuf - (i + 1) );
  }
  *(ptr + loop) = '\0'; // Add null-terminator to the end of final output
  len++;                // Increase total output length by one;

  return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  uint8_t result = 0;

  return result;  
}
