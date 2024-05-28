// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.
// Example 1:
// Input: s = "42"
// Output: 42
// Explanation:
// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)
//            ^
// Example 2:
// Input: s = " -042"
// Output: -42
// Explanation:
// Step 1: "   -042" (leading whitespace is read and ignored)
//             ^
// Step 2: "   -042" ('-' is read, so the result should be negative)
//              ^
// Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
//                ^
// Example 3:
// Input: s = "1337c0d3"
// Output: 1337
// Explanation:
// Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
//              ^
// Example 4:
// Input: s = "0-1"
// Output: 0
// Explanation:
// Step 1: "0-1" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
//           ^
// Example 5:
// Input: s = "words and 987"
// Output: 0
// Explanation:
// Reading stops at the first non-digit character 'w'.
// Constraints:
// 0 <= s.length <= 200
// s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define ASCII_MAX_DIGIT 57
#define ASCII_MIN_DIGIT 48
#define ASCII_SPACE 32
#define ASCII_ZERO 48
#define ASCII_PLUS 43
#define ASCII_MINUS 45

int myAtoi(char *s)
{
  int sLength = strlen(s);
  int isReading = 0;
  int isLeadingZero = 1;
  int sign = 1;

  int resArr[10] = {-1};
  int resIdx = 0;
  for (int i = 0; i < 10; i++)
  {
    resArr[i] = -1;
  }

  printf("\n%s\n", s);
  for (int i = 0; i < sLength; i++)
  {
    char c = s[i];

    if (!isReading && (c == ASCII_SPACE))
    {
      continue;
    }

    if (!isReading && (c == ASCII_PLUS || c == ASCII_MINUS))
    {
      isReading = 1;
      sign = (int)c == ASCII_MINUS ? -1 : 1;
      continue;
    }

    if (ASCII_MIN_DIGIT <= c && c <= ASCII_MAX_DIGIT)
    {
      if (resIdx > 9)
      {
        if (sign == 1)
        {
          return INT_MAX;
        }
        else
        {
          return INT_MIN;
        }
      }

      if (c == ASCII_ZERO && isLeadingZero) {
        isReading = 1;
        continue;
      }
      isLeadingZero = 0;

      if (!isReading)
      {
        isReading = 1;
      }

      resArr[resIdx++] = c - '0';
      continue;
    }
    else
    {
      break;
    }
  }

  int res = 0;
  for (int i = 0; i < resIdx; i++)
  {
    res += sign * resArr[i] * pow(10, resIdx - i - 1);
  }
  if (res < 0 && sign == 1)
  {
    res = INT_MAX;
  }

  return res;
}

int main()
{

  char *s1 = "42";
  int res1 = myAtoi(s1);

  char *s2 = " -042";
  int res2 = myAtoi(s2);

  char *s3 = "1337c0d3";
  int res3 = myAtoi(s3);

  char *s4 = "0-1";
  int res4 = myAtoi(s4);

  char *s5 = "words and 987";
  int res5 = myAtoi(s5);

  char *s6 = "-3000000000";
  int res6 = myAtoi(s6);

  char *s7 = "-2147483648";
  int res7 = myAtoi(s7);

  printf("\nresults:\n");
  printf("%s: %d\n", s1, res1);
  printf("%s: %d\n", s2, res2);
  printf("%s: %d\n", s3, res3);
  printf("%s: %d\n", s4, res4);
  printf("%s: %d\n", s5, res5);
  printf("%s: %d\n", s6, res6);
  printf("%s: %d\n", s7, res7);

  return 0;
}