// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
  char *res = (char *)malloc(sizeof(char));
  int resLength = 0;
  *res = '\0';

  int i = 0;
  while (1)
  {
    const char newChar = strs[0][i];
    if (newChar == '\0')
    {
      break;
    }

    int match = 1;
    for (int j = 1; j < strsSize; j++)
    {
      if (strs[j][i] != newChar)
      {
        match = 0;
        break;
      }
    }

    if (!match)
    {
      printf("res %s\n", res);
      return res;
    }

    resLength++;
    res = (char *)realloc(res, (resLength + 1) * sizeof(char));
    res[resLength] = '\0';
    res[resLength - 1] = newChar;

    i++;
  }

  return res;
}

int main()
{
  char *strs[] = {"flower", "flow", "floight"};
  int strsSize = 3;

  char *res = longestCommonPrefix(strs, strsSize);
  printf("res: %s\n", res);

  return 0;
}