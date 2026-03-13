// Given an integer array nums and an integer k, return true if there are two 
// distinct indices i and j in the array such that nums[i] == nums[j] and 
// abs(i - j) <= k.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  int i, j;

  for (i = 0; i < numsSize - 1; i++)
  {
    for (j = i + 1; j < numsSize; j++)
    { 
      if (abs(i - j) <= k)
        if (nums[i] == nums[j])
          return true;  
    }
  }
  return false;
}

int main()
{
  int nums1[] = {1, 2, 3, 1};
  int k1 = 3;
  printf("%s\n", containsNearbyDuplicate(nums1, 4, k1) ? "true" : "false");

  int nums2[] = {1, 0, 1, 1};
  int k2 = 1;
  printf("%s\n", containsNearbyDuplicate(nums2, 4, k2) ? "true" : "false");

  int nums3[] = {1, 2, 3, 1, 2, 3};
  int k3 = 2;
  printf("%s\n", containsNearbyDuplicate(nums3, 6, k3) ? "true" : "false");

  return 0;
}