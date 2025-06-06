// We are given a list nums of integers representing a list compressed with run-length encoding.
// Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).
// For each such pair, there are freq elements with value val concatenated in a sublist.
// Concatenate all the sublists from left to right to generate the decompressed list.
// Return the decompressed list.

#include <vector>

class Solution
{
public:
  std::vector<int> decompressRLElist(std::vector<int> &nums)
  {
    std::vector<int> res;

    int i = 0;

    while (i < nums.size())
    {
      int count = nums[i];
      int value = nums[i + 1];
      res.insert(res.end(), count, value);
      i += 2;
    }

    return res;
  }
};