// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// Example 1:
// Input: nums = [2,2,1]
// Output: 1
// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:
// Input: nums = [1]
// Output: 1
// Constraints:
// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.

#include <stdio.h>

int singleNumber(int *nums, int numsSize)
{
  int res = 0;

  for (int i = 0; i < numsSize; i++)
  {
    res ^= nums[i];
  }

  return res;
}

void pArr(int n, int *nums)
{
  printf("[");
  for (int i = 0; i < n; i++)
  {
    printf("%d", nums[i]);
    if (i != n - 1)
      printf(", ");
  }
  printf("]\n");
}

int main()
{
  int nums1[3] = {2, 2, 1};
  int nums1Size = 3;
  int res1 = singleNumber(nums1, nums1Size);

  pArr(nums1Size, nums1);
  printf("%d\n", res1);
}