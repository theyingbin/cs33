int switch_prob(int x, int n)
{
  int result = x;
 
  switch(n) {
 
  /* Fill in code here */
  case 0x32:
  case 0x34:
    x=x<<2;
    break;
  case 0x35:
    x=x>>2;
    break;
  case 0x36:
    x=x+2*x;
    /* Falls through */
  case 0x37:
    x*=x;
    /* Falls through */
  default:
    x+=10;    
  }
  return result;
}
