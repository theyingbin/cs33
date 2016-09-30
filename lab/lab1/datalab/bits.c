/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * Ying Bin Wu 104485521
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* To compute the number of bits needed, we do two things:
   * 1. Bit smearing - changing all bits after the most significant bit into a one
   * 2. Bit counting - count the number of one's after the most significant bit
   * To do this, we use shifts and use masks to find the sum of the number of ones logarithmically
   */
  // Declare Masks
  // Declared this way to prevent overflow when shifting
  int mask1 = 0x55; // 0x55555555
  int mask2;        // ~mask1
  int mask3 = 0x33; // 0x33333333
  int mask4;        // ~mask3
  int mask5 = 0x0F; // 0x0F0F0F0F
  int mask6;        // ~mask5
  int mask7 = 0xFF; // 0x00FF00FF
  int mask8;        // ~mask7
  int mask9 = 0xFF; //0x0000FFFF
  int mask10;       // ~mask9
  
  x = x ^ (x >> 31); // If x is negative, x = -x + 1. The added one is so we don't have overflow

  // Bit Smearing
  x = x | x >> 16;
  x = x | x >> 8;
  x = x | x >> 4;
  x = x | x >> 2;
  x = x | x >> 1;

  // Create Masks
  mask1 = (mask1 << 8) + mask1;
  mask1 = (mask1 << 16) + mask1;
  mask2 = ~mask1;
  mask3 = (mask3 << 8) + mask3;
  mask3 = (mask3 << 16) + mask3;
  mask4 = ~mask3;
  mask5 = (mask5 << 8) + mask5;
  mask5 = (mask5 << 16) + mask5;
  mask6 = ~mask5;
  mask7 = (mask7 << 16) + mask7;
  mask8 = ~mask7;
  mask9 = (mask9 << 8) + mask9;
  mask10 = ~mask9;

  // Bit counting
  x = (x&mask1) + ((x&mask2)>>1);
  x = (x&mask3) + ((x&mask4)>>2);
  x = (x&mask5) + ((x&mask6)>>4);
  x = (x&mask7) + ((x&mask8)>>8);
  x = (x&mask9) + ((x&mask10)>>16);

  return x+1;  // Add one for the sign bit
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /* To change from sign & magnitude notation to 2's complement, 
   * extract the sign bit to check if it is negative
   * if it's negative, we can invert all the other bits and add one to get the right answer
   * otherwise, return the original x
   */
  int MSB_MASK = (~0) << 31;
  int otherBitsMask = ~MSB_MASK;
  int isNegative = x>>31;
  return (isNegative&(~(otherBitsMask&x)+1)) | (~isNegative&x); 
}
/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  /* Extract the sign bit and check if it's a 1 or a 0 */
  return !(x&((~0)<<31));
}

/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
  /* Extract the bottom n bits and right shift them.
   * then extract the top 32-n bits and left shift them
   * add the two results 
   */
  int mask = ~((~0)<<(31 + ~n + 1)<<1);
  return ((x>>n)&mask)|(x<<(31 + ~n + 1)<<1);
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* Check the sign bit to see if x is negative
   * if x is negative, shift x+2^n-1 by n (mathmatical property) and return
   * otherwise return x
   */
  int isNegative = x >> 31;
  return ((isNegative&(x+(1<<n)+~0))|(~isNegative&x)) >> n;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* Create a mask to extract all the odd bits
   * all the odd bits are set off if the result of the extraction is equal to the mask
   */
  int mask = 0x55;
  mask = (mask<<8) + mask;
  mask = (mask<<16) + mask;
  mask = ~mask;
  return !((x&mask)^mask);
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* XOR is simply OR combined with not AND
   * to get OR, we use DeMorgan's Law
   * then we combine the two functions
   */
  return (~(~x&~y))&(~(x&y));
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  /* One property that TMin has is that -TMin = TMin
   * make use of this property to check if the input is TMin
   * Also check that it is not zero since TMin shares this property with zero
   */
  return (!((~x+1)^x))&(!!x); 
}
