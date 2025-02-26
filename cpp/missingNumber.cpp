// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is
// missing from the array.

#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:
  int missingNumber(std::vector<int> &nums)
  {
    const int n = nums.size();
    const int expectedTotal = n * (n + 1) / 2;
    const int actualTotal = std::accumulate(nums.cbegin(), nums.cend(), 0);
    return expectedTotal - actualTotal;
  }
};