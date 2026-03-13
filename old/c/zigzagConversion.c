// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string s, int numRows);
// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"
// Constraints:
// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

// P   A
// A P L S
// Y   I

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
  int sLength = strlen(s);
  if (numRows == 1)
  {
    return s;
  }

  int numCharsInColDiag = 2 * (numRows - 1);
  char *res = malloc((sLength + 1) * sizeof(char));
  res[sLength] = '\0';
  int resIndex = 0;

  // top row
  int i = 0;
  while (i < sLength)
  {
    res[resIndex++] = s[i];
    i += numCharsInColDiag;
  }

  // middle rows
  for (i = 1; i < numRows - 1; i++)
  {
    int j = i;
    while (j < sLength)
    {
      res[resIndex++] = s[j];

      int toDiag = 2 * (numRows - i - 1);
      if (j + toDiag < sLength)
      {
        res[resIndex++] = s[j + toDiag];
      }
      j += numCharsInColDiag;
    }
  }

  // bottom row
  i = numRows - 1;
  while (i < sLength)
  {
    res[resIndex++] = s[i];
    i += numCharsInColDiag;
  }

  return res;
}

int main()
{
  char *s = "PAYPALISHIRING";

  char *res1 = convert(s, 3);
  printf("%s\n", res1);

  char *res2 = convert(s, 4);
  printf("%s\n", res2);

  return 0;
}