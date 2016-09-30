// 2nd Edition
// Problem 3.56

long loop(long x, int n){
  long result = 0;
  long mask;
  for(mask = 1; mask != 0; mask = mask<<((0xFF)&n)){
    result ^= (x&mask);
  }
  return result;
}

/*
 * A. x is held in %rdi.
 *    n is held in %esi.
 *    result is held in %eax.
 *    mask is held in %edx.
 * B. The inital value of result and mask are 0 and 1 respectively.
 * C. The conditional test for mask is mask != 0.   
 * D. mask gets updates by being shifted over by the lower order 8 bits of n.
 * E. result gets xor'ed with x & mask
 * F. Done
 */