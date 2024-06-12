// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.
// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]
// Constraints:
// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

#include <stdio.h>

void swap(int *px, int *py)
{
  int temp = *px;
  *px = *py;
  *py = temp;
}

// bubble sort
void sortColors(int *nums, int numsSize)
{
  int i, j;
  for (i = 0; i < numsSize - 1; i++)
  {
    for (j = 0; j < numsSize - i - 1; j++)
    {
      if (nums[j] > nums[j + 1])
        swap(&nums[j], &nums[j + 1]);
    }
  }
}

int main()
{
  // int nums[3] = {2, 0, 1};
  // int numsSize = 3;

  int nums[6] = {2, 0, 2, 1, 1, 0};
  int numsSize = 6;

  sortColors(nums, numsSize);

  printf("[");
  for (int i = 0; i < numsSize; i++)
  {
    printf("%d", nums[i]);
    if (i != numsSize - 1)
      printf(", ");
  }
  printf("]\n");

  return 0;
}