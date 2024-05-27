// Given a string s, find the length of the longest substring without repeating characters.
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 128

int lengthOfLongestSubstring(char *s)
{
  int result = 0;
  int left = 0;
  int strLength = strlen(s);

  int charIndexes[MAX_CHAR];
  memset(charIndexes, -1, sizeof(charIndexes));

  for (int right = 0; right < strLength; right++)
  {
    char c = s[right];
    int cLastIndex = charIndexes[(int)c];
    if (cLastIndex != -1 && cLastIndex >= left)
    {
      left = cLastIndex + 1;
    }
    charIndexes[(int)c] = right;
    
    int length = right - left + 1;
    result = (length > result) ? length : result;
  }

  return result;
}

int main()
{
  char *s = "abcabcbb";
  int x = lengthOfLongestSubstring(s);
  printf("res: %d\n", x);

  return 0;
}