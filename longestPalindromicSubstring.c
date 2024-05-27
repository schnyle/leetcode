// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:
// Input: s = "cbbd"
// Output: "bb"
// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s)
{
  int sLength = strlen(s);

  if (sLength == 1)
  {
    return s;
  }

  char *result = malloc((sLength + 1) * sizeof(char));
  int resultLength = 0;

  for (int i = 0; i < sLength; i++)
  {
    int left = i - 1;
    int right = i + 1;
    char *substring = malloc(sLength * sizeof(char));
    memset(substring, ' ', sLength * sizeof(char));

    // odd palindrome
    substring[i] = s[i];
    int substringLength = 1;

    // even palidrome
    if (right < sLength && s[i] == s[right])
    {
      substring[right] = s[right];
      substringLength++;
      right++;
    }

    while (left >= 0 && right < sLength)
    {
      char sLeft = s[left];
      char sRight = s[right];

      if (sLeft == sRight)
      {
        substring[left] = s[left];
        substring[right] = s[right];
        substringLength += 2;
      }
      else
      {
        break;
      }

      left--;
      right++;
    }

    if (substringLength > resultLength)
    {
      resultLength = substringLength;
      memcpy(result, substring, (resultLength + 1) * sizeof(char));
      result[sLength - 1] = '\0';
    }

    free(substring);
  }

  // trim result
  char *ans = malloc((resultLength + 1) * sizeof(char));
  int ansIndex = 0;
  for (int i = 0; i < sLength; i++)
  {
    char c = result[i];
    if (c != ' ')
    {
      ans[ansIndex] = c;
      ansIndex++;
    }
  }
  ans[resultLength] = '\0';

  return ans;
}

int main()
{
  char *s = "bbb";
  char *res = longestPalindrome(s);

  int n = strlen(res);

  printf("res: ");
  for (int i = 0; i < n; i++)
  {
    printf("%c", res[i]);
  }
  printf("\n");

  return 0;
}