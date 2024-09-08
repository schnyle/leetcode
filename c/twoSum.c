// 1. Two Sum
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]
// Constraints:
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int index;
  int value;
} HashMapItem;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// two pass solution
int *twoSumOld(int *nums, int numsSize, int target, int *returnSize)
{
  HashMapItem *hashMap = (HashMapItem *)malloc(numsSize * sizeof(HashMapItem));
  int *result = (int *)malloc(2 * sizeof(int));

  for (int i = 0; i < numsSize; i++)
  {
    int complement = target - nums[i];
    HashMapItem hashMapItem;

    hashMap[i].index = i;
    hashMap[i].value = complement;
  }

  for (int i = 0; i < numsSize; i++)
  {
    int complement = target - nums[i];

    for (int j = i + 1; j < numsSize; j++)
    {
      if (hashMap[j].value == nums[i])
      {
        result[0] = i;
        result[1] = hashMap[j].index;
        *returnSize = 2;
        return result;
      }
    }
  }

  free(hashMap);

  return NULL;
}

// one pass solution
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  HashMapItem *hashMap = (HashMapItem *)malloc(numsSize * sizeof(HashMapItem));
  int *result = (int *)malloc(2 * sizeof(int));

  for (int i = 0; i < numsSize; i++)
  {
    int complement = target - nums[i];
    for (int j = 0; j < i; j++)
    {
      if (hashMap[j].value == nums[i])
      {
        result[0] = hashMap[j].index;
        result[1] = i;
        *returnSize = 2;
        return result;
      }
    }

    hashMap[i].index = i;
    hashMap[i].value = complement;
  }

  free(hashMap);

  return NULL;
}

int main()
{
  int nums[] = {3, 2, 4};
  int numsSize = 3;
  int target = 6;
  // int nums[] = {2, 7, 11, 15};
  // int numsSize = 4;
  // int target = 9;
  int returnSize = 0;

  int *result = twoSum(nums, numsSize, target, &returnSize);

  if (result != NULL)
  {
    printf("Indices: %d, %d\n", result[0], result[1]);
    free(result);
  }
  else
  {
    printf("No solution found.\n");
  }

  return 0;
}