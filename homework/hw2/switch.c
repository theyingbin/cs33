// @nd Edition Problem 2.59

int switch_prob(int x, int n)
{
  int result = x;
 
  switch(n) {
 
  /* Fill in code here */
  case 0x32:
  case 0x34:
    result=result<<2;
    break;
  case 0x35:
    result=result>>2;
    break;
  case 0x36:
    result=result+2*result;
    /* Falls through */
  case 0x37:
    result*=result;
    /* Falls through */
  default:
    result+=10;    
  }
  return result;
}
