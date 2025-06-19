#include <stdlib.h>
#include "data.h"

#include "stats.h" // TEMPORARY - for print_array()
#include <stdio.h> // TEMPORARY - for printf()

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t len = 0;
  uint8_t buf[34];
  uint8_t* pBuf = buf;
  uint8_t  bufOffset = 0;

/*
    HANDLE BASE 3 - 15 

    Use base 10 body? not sure if there's a binary way to do this.

    If using base 10, would need some way to invert the bits (bitwise OR?) after 
    convering negative input to positive int and add 1 bit to convert to 2s complement.

    Otherwise if positive num, handle like base 10 via modulo and division?
    


    Use pure bitwise operation for base 2 and 16?
    Add variables for:
    - main loop length (base2 == 32)
    - bitmask size (base2 == 1 bit increments)
    - bit offset size (bitshift) (base2 == 1 bit increments)
*/

  if( (base <= 16) &&
      (base >= 2) )
  {
    if(data < 0)
    {
      data = data * -1; // Convert negative number to positive
      *ptr = '-';       // Add '-' to the start of the output
      ptr++;            // Move onto the next 'index' in final output
    }
    while(data != 0)
    {
      *pBuf = (data % base) + '0'; // Use modulo to find the leftover value of the given base and convert the result to an ASCII character 
      if(*pBuf > 57)               // If the current digit output is bigger than ASCII '9'...
      {
        *pBuf += 7;                // ...Add 7 to the ASCII value to skip the signs in the ASCII table and instead start at the letters. 
      }
      data = data / base;          // Divide data by base number to 'remove' the base value so that modulo can get the next digit in the given base 
      pBuf++;                      // Move onto the next 'index' in buffer
      len++;                       // Increase total output length by one
    }
    uint8_t loop = len;
    for(uint8_t i = 0; i < loop; i++) // Loop through the buffer
    {
      if( *(pBuf - (i + 1)) == 48 )   // If ASCII '0' is found
      {
        bufOffset++;                  // Increase buffer offset variable by 1 to later be used when reversing the buffer into final output pointer
        len--;                        // Decrease length value by 1 as we are removing a digit from the total output
      }
      else
      {
        break;                        // Stop as soon as a non-zero value is found to prevent legitimate zeros being removed
      }
    }
  }

  // ===== Reverse buffer content into ptr array =====
  for(uint8_t i = 0; i < len; i++)
  {
    *(ptr + i) = *(pBuf - ((i + 1) + bufOffset) ); // pBuf already points to the last element so we just need to subtract the index number (i) to reverse
  }

  // ===== Final adjustments =====
  if(*(ptr - 1) == 45)   // If output starts with ASCII '-' (for negative number)
  {
    len++;            // Increase total output length by one to account for the '-' symbol as it was not recorded before 
                      // because len variable was required for loops and the additional length would have resulted in broken indexing
  }

  *(ptr + len) = '\0'; // Add null-terminator to the end of final output
  len++;               // Increase total output length by one to account for null-terminator

  return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  uint8_t result = 0;

  return result;  
}
