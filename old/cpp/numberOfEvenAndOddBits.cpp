// You are given a positive integer `n`.
// Let `even` denote the number of even indices in the binary representation of `n` with value 1.
// Let `odd` denote the number of odd indices in the binary representation of `n` with value 1.
// Note that bits are indexed from right to left in the binary representation of a number.
// Return the array [even, odd].

#include <vector>

class Solution
{
public:
  std::vector<int> evenOddBit(int n)
  {
    int even = 0, odd = 0;
    for (int i = 0; i < 32; ++i)
    {
      const int val = ((1 << i) & n) >> i;
      if (i % 2 == 0)
      {
        even += val;
      }
      else
      {
        odd += val;
      }
    }
    return {even, odd};
  }
};