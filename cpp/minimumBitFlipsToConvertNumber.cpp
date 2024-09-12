// A bit flip of a number `x` is choosing a bit in the binary representation of
// `x` and flipping it from either 0 to 1 or 1 to 0.
// For example, for `x = 7`, the bianary representation is `111` and we may
// choose any bit (including any leading zeros not shown) and flip it. We can
// flip the first bit rom the right to get `110`, flip the second bit from the
// right to get `101`, flip the fifth bit from the right to get `10111`, etc.
// Given two integers `start` and `goal`, return the minimum number of bit flips
// to convert `start` to `goal`.

#include <iostream>

class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    return __builtin_popcount(start ^ goal);
  }
};

int main()
{
  int start = 10;
  int goal = 7;

  Solution s;
  int res = s.minBitFlips(start, goal);
  std::cout << res << "\n";
}
