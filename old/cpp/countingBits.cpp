// Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i`, ans[i] is the number of 1's
// in the binary representation of i.

#include <vector>

class Solution
{
public:
  std::vector<int> countBits(int n)
  {
    std::vector<int> ans(n + 1);
    ans[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
      ans[i] = ans[i >> 1] + (i % 2 == 0 ? 0 : 1);
    }

    return ans;
  }
};