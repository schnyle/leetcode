// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.
// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:
// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
// Constraints:
// 1 <= s.length <= 104
// s consists of only English letters and spaces ' '.
// There will be at least one word in s.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char *s)
{
  int sLen = strlen(s);
  int res = 0;
  int readingWord = 0;

  for (int i = sLen - 1; i >= 0; i--)
  {
    char c = s[i];

    if (c == ' ' && !readingWord)
    {
      continue;
    }

    if (!readingWord && c != ' ')
    {
      readingWord = 1;
    }

    if (c != ' ' && readingWord)
    {
      res++;
    }

    if (c == ' ' && readingWord)
    {
      break;
    }
  }

  return res;
}

int main()
{
  char *s = "   fly me   to   the moon  ";

  int res = lengthOfLastWord(s);

  printf("res: %d\n", res);

  return 0;
}