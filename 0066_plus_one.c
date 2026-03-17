/**
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the
 * integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer
 * does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 *
 * Example 1:
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 * Example 2:
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 * Example 3:
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 * Constraints:
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 *digits does not contain any leading 0's.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digits_size, int *return_size)
{
  int *result = malloc(sizeof(int) * (digits_size + 1));
  memcpy(result + 1, digits, sizeof(int) * digits_size);

  int val = 1;
  for (int i = digits_size - 1; i >= 0; --i)
  {
    int new_digit = digits[i] + val;
    if (new_digit == 10)
    {
      val = 1;
      result[i + 1] = 0;
    }
    else
    {
      result[i + 1] = new_digit;
      val = 0;
      break;
    }
  }

  if (val == 1)
  {
    result[0] = 1;
    *return_size = digits_size + 1;
    return result;
  }
  else
  {
    *return_size = digits_size;
    return result + 1;
  }
}

// testing

#define SIZE 1

int main()
{
  int return_size;
  // int input[SIZE] = {4, 3, 2, 1};
  int input[SIZE] = {9};
  printf("input:\n");
  for (int i = 0; i < SIZE; ++i)
  {
    printf("%d ", input[i]);
  }
  printf("\n\n");

  int *output = plusOne(input, SIZE, &return_size);
  printf("output:\n");
  printf("result size: %d\n", return_size);
  for (int i = 0; i < return_size; ++i)
  {
    printf("%d ", output[i]);
  }
  printf("\n");
}
