/* file is bit_functions.c 
Purpose: helper functions for bit manipulation

*/

#include "bit_functions.h"

/*
Purpose: checks if bit in position bitNum of the character c is set to 1 
input:
c - a character upon
bitNum - the bit position

return
1 if the bits is set
0 is the bit is not set

*/
unsigned char isBitSet(unsigned char c, int bitNum) 
{
  return (c & (1 << bitNum) ) >> bitNum;
}

/*
Purpose: sets bit in position bitNum of the character c to 1 
input:
c - a character upon
bitNum - the bit position

return
the modified character

*/
unsigned char setBit(unsigned char c, int bitNum) 
{
  c = c | (1 << bitNum);
  return c;
}

/*
Purpose: clears bit in position bitNum of the character c 
input:
c - a character upon
bitNum - the bit position

return
the modified character

*/
unsigned char clearBit(unsigned char c, int bitNum) 
{
  c = c & (~(1 << bitNum));
  return c;
}

/*
Purpose: prints the bits of the the character 
input:
c - a character upon

return
none

*/
void printBitsIterative(unsigned char c) 
{
  int i;

  // Start at the leftmost bit (7) and work towards the right
  for (i = 7; i > -1; i--) {

    // Use isBitSet to get the value of the ith bit
    printf("%d", isBitSet(c, i));
  }

  printf("\n");
  return;
}

/*
Purpose: prints the bits of the the character 
input:
c - a character upon

return
none

*/
void printBitsRecursive(unsigned char c) 
{
  // Always print the leftmost bit
  printf("%d", isBitSet(c, 7));

  // Bitshift one to the left since we don't need that bit anymore
  // ex. 1101 becomes 1010
  c = c << 1;

  // Check base case before recursing.
  // Stop when we have 0000 0000
  if (c == 0) {
    printf("\n");
    return;
  }

  // Recurse with the new modified c
  printBitsRecursive(c);
}

/*
Purpose: flips the bit at position bitNum of the character
input:
c - a character
bitNum - the bit position

return
the modified character

*/
unsigned char flipBit(unsigned char c, int bitNum){
  // Same as setBit but using XOR operator instead of OR operator
  c = c ^ (1 << bitNum);
  return c;
}
