// Given an integer x, return true if x is a palindrome, and false otherwise.
// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Constraints:
// -231 <= x <= 231 - 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int intLength(int x)
{
  if (x == INT_MIN)
  {
    return 10;
  }

  x = abs(x);
  if (x < 10) return 1;
  return 1 + intLength(x / 10);
}

bool isPalindrome(int x)
{
  if (x < 0)
  {
    return false;
  }

  int xReverse = 0;
  int xLength = intLength(x);

  int p = 0;
  while (1)
  {
    int value = x / pow(10, p);
    int digit = value % 10;

    if (digit == 0 && p > xLength)
    {
      break;
    }

    xReverse += digit * pow(10, xLength - (p + 1));

    p++;

  }

  if (x == xReverse)
  {
    return true;
  }
  return false;
}

int main()
{
  bool res = isPalindrome(1001);

  char *msg = res ? "true" : "false";
  printf("%s\n", msg);

  return 0;
}