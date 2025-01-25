// Given a positive integer n, write a function that returns the number of set bits in its binary representation.

#include <bitset>
#include <algorithm>

class Solution
{
public:
  int hammingWeight(int n)
  {
    int res = 0;
    for (int i = 0; i < 32; ++i)
    {
      res += (1 << i & n) >> i;
    }
    return res;
  }
};