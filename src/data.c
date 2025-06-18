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

  // ===== Convert int32 to ASCII string (base 2) =====
  if(base == 2)
  {
    uint32_t bitmask = (uint32_t) 0x1; // Bit mask of 1 bit
    uint8_t  byteValue;
    uint8_t  bitOffset = 0;

    for(uint8_t i = 0; i < 32; i++)
    {
      byteValue = (uint8_t)((data & bitmask) >> bitOffset); // Apply bitmask to input data. Then bitshift to the right to bring the masked values to the LSB side. 
      *pBuf = byteValue + '0';                              // Convert the binary digit to ASCII character
      // if(*pBuf > 57)                                        // If the current digit output is bigger than ASCII '9'...
      // {
      //   *pBuf += 7;                                         // ...Add 7 to the ASCII value to skip the signs in the ASCII table and instead start at the letters. 
      // }
      bitmask = bitmask << 1; // Update the mask to move onto the next bit in the input
      bitOffset += 1;         // Update bit offset to make sure the masked data gets moved to LSB position correctly
      pBuf++;                 // Move onto the next 'index' in buffer
      len++;                  // Increase total output length by one
    }
    // To remove leading zeros in hex final value...
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
  // ===== Convert int32 to ASCII string (base 10) =====
  else if(base == 10)
  {
    if(data < 0)
    {
      data = data * -1; // Convert negative number to positive
      *ptr = '-';       // Add '-' to the start of the output
      ptr++;            // Move onto the next 'index' in final output
    }
    while(data != 0)
    {
      *pBuf = (data % base) + '0'; // Store least-significant digit at given memory address as a string character
      data = data / base;          // 'Remove' least-significant digit from data integer
      pBuf++;                      // Move onto the next 'index' in buffer
      len++;                       // Increase total output length by one
    }
  }
  // ===== Convert int32 to ASCII string (base 16) =====
  else if(base == 16)
  {
    uint32_t bitmask = (uint32_t) 0xF; // Bit mask of 4 bits
    uint8_t  byteValue;
    uint8_t  bitOffset = 0;

    for(uint8_t i = 0; i < 8; i++)
    {
      byteValue = (uint8_t)((data & bitmask) >> bitOffset); // Apply bitmask to input data. Then bitshift to the right to bring the masked values to the LSB side. 
      *pBuf = byteValue + '0';                              // Convert the hex digit to ASCII character
      if(*pBuf > 57)                                        // If the current digit output is bigger than ASCII '9'...
      {
        *pBuf += 7;                                         // ...Add 7 to the ASCII value to skip the signs in the ASCII table and instead start at the letters. 
      }
      bitmask = bitmask << 4; // Update the mask to move onto the next 4 bits in the input
      bitOffset += 4;         // Update bit offset to make sure the masked data gets moved to LSB position correctly
      pBuf++;                 // Move onto the next 'index' in buffer
      len++;                  // Increase total output length by one
    }
    // To remove leading zeros in hex final value...
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
  print_array(buf,34);

  // ===== Reverse buffer content into ptr array =====
  for(uint8_t i = 0; i < len; i++)
  {
    *(ptr + i) = *(pBuf - ((i + 1) + bufOffset) ); // pBuf already points to the last element so we just need to subtract the index number (i) to reverse
  }

  // ===== Final adjustments =====
  if( (base == 10) &&
      (*ptr == 45))   // If output from base 10 calculation starts with ASCII '-' (for negative number)
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
