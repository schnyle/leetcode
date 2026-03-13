// Given an integer array `nums` sorted in non-decreading order, remove the
// duplicates in-place such that each unique element appears only once. The
// relative order of the elements should be kept the same. Then return the
// number of unique elements in `nums`.
// Consider the number of unique elements of `nums` to be `k`, to get accepted
// you need to do the following things:
// - Change the array `nums` such that the first `k` elements of `nums` contain
// the unique elements in the order they were present in `nums` initially. The
// remaining elements of `nums` are not important as well as the size of `nums`.
// - Return `k`.

#include <iostream>
#include <vector>
#include <limits>

class Solution
{
public:
  int removeDuplicates(std::vector<int> &nums)
  {
    int k = 1;
    int prev = nums[0];

    for (auto iter = nums.begin() + 1; iter != nums.end();)
    {
      if (*iter == prev)
      {
        iter = nums.erase(iter);
      }
      else
      {
        prev = *iter;
        ++k;
        ++iter;
      }
    }

    return k;
  }
};

int main()
{
  std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  Solution s;
  std::cout << "res:\n";
  auto res = s.removeDuplicates(nums);
  for (auto &x : nums)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  std::cout << "K: " << res << "\n";
}