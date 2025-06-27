#include <stdlib.h>
#include "data.h"

uint32_t my_pow(uint32_t base, uint32_t exponent)
{
  uint32_t result = base;
  for(uint32_t i = 0; i < exponent - 1; i++)
  {
    result *= base;
  }
  return result;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t  len = 0;
  uint8_t  buf[34];
  uint8_t* pBuf = buf;
  uint8_t  bufOffset = 0;

  if( (base <= 16) &&
      (base >= 2) )
  {
    // ===== Convert int32 to base N and load to buffer =====
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
  }

  return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  digits--; // Reduce digit count because we do not want to count the null terminator
  int32_t result = 0;
  uint8_t negFlag = 0;

  if( (base <= 16) && // Basic check if base is valid
      (base >= 2) )
  {
    // ===== Handle negative values =====
    if(*ptr == '-')   // If value at given pointer (first element of string) is equal to ASCII minus... 
    {
      negFlag = 1;    // Set flag to later turn the result back to negative value
      digits--;       // Reduce digit count because we no longer are counting the minus character
      ptr++;          // Ignore the minus character by moving the pointer onto the next address (hopefully pointing to an ASCII digit)
    }
    // ===== Convert ASCII string to base N integer (int32) =====
    for(uint8_t i = 0; i < digits; i++)     // Loop through given string
    {
      uint8_t uintDigit = *(ptr + i) - '0'; // Convert character at current pointer from ASCII to uint and store as uintDigit
      if( (base > 10) &&
          (uintDigit > 9) )                 // If dealing in base 11 or above (using A-F characters), and current decoded digit is above 9...
      {
        uintDigit -= 7;                     // ...Subtract 7 since ASCII encoded values must jump 7 positions to get from '9' to 'A' due to symbol characters. 
      }
      uint32_t weight = my_pow(base, (digits - i)); // Find the current digit's position's weight (e.g. weight 8 for the 4th bit in base 2)
      result += (uintDigit * weight);       // Multiply current digit by weight and add to total result
    }
    result /= base;                         // After processing all digits, divide total result by base number to get the final decoded value

    // ===== Correct the conversion if input was negagtive =====
    if(negFlag == 1)  // If input indicated that the string was of a negative number...
    {
        result *= -1; // Convert result back to negative value as the above process was carried out ignoring the minus sign
    }
  }

  return result;  
}
