// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// Example 1:
// Input: x = 123
// Output: 321
// Example 2:
// Input: x = -123
// Output: -321
// Example 3:
// Input: x = 120
// Output: 21
// Constraints:
// -231 <= x <= 231 - 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int intLength(int x)
{
  if (x == INT_MIN)
  {
    return 10;
  }

  x = abs(x);
  if (x < 10)
    return 1;
  return 1 + intLength(x / 10);
}

int reverse(int x)
{
  int res = 0;

  int length = intLength(x);

  for (int i = 0; i < length; i++)
  {
    int value = x / pow(10, i);
    int digit = value % 10;
    res += (digit * pow(10, length - i - 1));
  }

  int xIsPositive = (x > 0);
  int resIsPositive = (res > 0);

  if (xIsPositive != resIsPositive)
  {
    return 0;
  }

  if (res == INT_MIN)
  {
    return 0;
  }

  printf("reversed: %d\n", res);
  return res;
}

int main()
{
  reverse(115);

  return 0;
}
