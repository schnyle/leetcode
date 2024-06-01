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
  int sLen = strlen(s);

  int start = 0;
  int maxLen = 1;

  void getLongestPalindromeAtIndex(int left, int right)
  {
    while (left >= 0 && right < sLen && s[left] == s[right])
    {
      left--;
      right++;
    }

    int len = right - left - 1;
    if (len > maxLen)
    {
      maxLen = len;
      start = left + 1;
    }
  }

  for (int i = 0; i < sLen; i++)
  {
    getLongestPalindromeAtIndex(i, i);
    if (i < sLen - 1 && s[i] == s[i + 1])
    {
      getLongestPalindromeAtIndex(i, i + 1);
    }
  }

  char *result = malloc((maxLen + 1) * sizeof(char));
  strncpy(result, s + start, maxLen);
  result[maxLen] = '\0';

  return result;
}

int main()
{
  char *s = "rrr";
  char *res = longestPalindrome(s);

  int n = strlen(res);

  printf("res: %s\n", res);

  printf("res: ");
  for (int i = 0; i < n; i++)
  {
    printf("%c", res[i]);
  }
  printf("\n");

  return 0;
}