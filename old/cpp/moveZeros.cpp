// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

#include <vector>
#include <iostream>

class Solution
{
public:
  void moveZeroes(std::vector<int> &nums)
  {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
      if (nums[i] == 0)
      {
        int j = i;
        while (j < nums.size())
        {
          if (nums[j] != 0)
          {
            nums[i] = nums[j];
            nums[j] = 0;
            break;
          };
          ++j;
        }
      }
    }
  }
};

int main()
{
  Solution s;

  std::vector<int> nums{0, 1, 0, 45, 2, 3, 0, 0, 8};

  s.moveZeroes(nums);

  for (auto &x : nums)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}