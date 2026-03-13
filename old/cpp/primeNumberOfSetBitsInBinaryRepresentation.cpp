// Given two integers left and right, return the count of numbers in the inclusive range [left, right]
// having a prime number of set bits in their binary representation.

#include <cmath>

class Solution
{
public:
  int countPrimeSetBits(int left, int right)
  {
    int res = 0;
    for (int n = left; n <= right; ++n)
    {
      int nSetBits = 0;
      for (int i = 0; i < 32; ++i)
      {
        nSetBits += ((1 << i) & n) >> i;
      }

      bool isPrime = true;
      for (int x = 2; x <= std::sqrt(nSetBits); ++x)
      {
        if (nSetBits % x == 0)
        {
          isPrime = false;
          break;
        }
      }
      if (nSetBits == 1)
      {
        isPrime = false;
      }

      res += isPrime ? 1 : 0;
    }
    return res;
  }
};