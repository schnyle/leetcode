// You are given an integer array `nums` of size `n`.
// Consider a non-empty subarray from `nums` that has the maximum possible
// bitwise AND.
// Return the length of the longest such subarray.

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  int longestSubarray(std::vector<int> &nums)
  {
    auto iter = std::max_element(nums.cbegin(), nums.cend());
    auto maxEle = *iter;

    int currentLength = 0;
    int maxLength = 1;

    for (; iter != nums.cend(); ++iter)
    {
      if (*iter == maxEle)
      {
        ++currentLength;
        maxLength = std::max(maxLength, currentLength);
      }
      else
      {
        currentLength = 0;
      }
    }

    return maxLength;
  }
};

int main()
{
  std::vector<int> nums{1, 2, 3, 3, 2, 2};

  Solution s;
  std::cout << s.longestSubarray(nums) << "\n";
}