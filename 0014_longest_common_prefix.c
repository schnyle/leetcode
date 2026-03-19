/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 * Constraints:
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters if it is non-empty.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 201

char *longestCommonPrefix(char **strs, int strs_size)
{
  char *result = calloc(sizeof(char), SIZE);
  int i = 0;
  char current_char, c;

  while (1)
  {
    current_char = strs[0][i];

    for (int j = 0; j < strs_size; ++j)
    {
      c = strs[j][i];

      if (c == '\0')
      {
        result[i++] = '\0';
        return result;
      }

      if (c != current_char)
      {
        result[i++] = '\0';
        return result;
      }
    }

    result[i++] = c;
  }

  return result;
}

// testing
int main()
{
  char *strs[3] = {"flower", "flow", "flight"};

  printf("result: %s\n", longestCommonPrefix(strs, 3));
}
