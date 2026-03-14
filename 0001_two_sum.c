/**
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time
 * complexity?
 */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// with 10 000 items, a map size of 20 000 gives a load factor of 0.5
// next largest prime is 20011
#define HASH_MAP_SIZE 20011

typedef struct Node
{
  int value;
  int index;
  struct Node *next;
} Node;

int hash(int value) { return abs(value) % HASH_MAP_SIZE; }

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  Node **map = calloc(HASH_MAP_SIZE, sizeof(Node *));

  for (int i = 0; i < numsSize; ++i)
  {
    int complement = target - nums[i];
    int complement_hash = hash(complement);

    // look for complement in hash map
    Node *node = map[complement_hash];
    while (node != NULL)
    {
      if (node->value == complement)
      {
        break;
      }
      node = node->next;
    }

    // if found, return
    if (node != NULL)
    {
      int *res = malloc(sizeof(int) * 2);
      res[0] = node->index;
      res[1] = i;
      *returnSize = 2;
      return res;
    }

    // if not found, add to hash map
    Node *new_node = malloc(sizeof(Node));
    int h = hash(nums[i]);
    new_node->value = nums[i];
    new_node->index = i;
    new_node->next = map[h];
    map[h] = new_node;
  }

  *returnSize = 0;
  return NULL;
}
