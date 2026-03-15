/**
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a
 * palindrome.
 *
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 * Constraints:
 *
 * -2^31 <= x <= 2^31 - 1
 *
 * Follow up: Could you solve it without converting the integer to a string?
 */

#include <stdbool.h>
#include <stdio.h>

// int pow(int x, int e)
// {
//   if (e == 0)
//     return 1;
//
//   int r = x;
//   for (int i = 0; i < e - 1; ++i)
//     r *= x;
//
//   return r;
// }

int ipow(int base, int exp)
{
  int result = 1;
  while (exp--)
    result *= base;
  return result;
}

bool isPalindrome(int x)
{
  if (x < 0)
    return false;

  int length = 1, x_copy = x;
  while (x_copy >= 10)
  {
    ++length;
    x_copy /= 10;
  }

  int left = 1, right = length;
  while (left < right)
  {
    int left_digit = (int)(x / ipow(10, length - left)) % 10;
    int right_digit = (int)(x / ipow(10, length - right)) % 10;
    if (left_digit != right_digit)
      return false;

    ++left;
    --right;
  }

  return true;
}

// testing
int main()
{
  int input = 121;
  printf("%s\n", isPalindrome(input) ? "true" : "false");
}
