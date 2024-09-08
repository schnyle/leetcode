#include <stdio.h>

int mySqrt(int x)
{
  long int res = 0;
  while (res * res <= x)
  {
    res++;
  }
  return res - 1;
}

int main()
{

  int res = mySqrt(2147395600);
  printf("%d\n", res);

  return 0;
}