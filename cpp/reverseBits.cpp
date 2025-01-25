// Reverse bits of a given 32 bits unsigned integer.

#include <cstdint>
#include <iostream>
#include <bitset>

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    int res = 0;
    for (int i = 0; i < 32; ++i)
    {
      res += ((1 << i & n) >> i) << (32 - i - 1);
    }
    return res;
  }
};

int main()
{
  Solution s;
  printf("expected: %d, actual: %d\n", 964176192, s.reverseBits(43261596));
}