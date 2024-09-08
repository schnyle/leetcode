// Given two binary strings a and b, return their sum as a binary string.
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
// Constraints:
// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b)
{
  char *res;
  int c = 0;
  int al = strlen(a);
  int bl = strlen(b);
  int l = al < bl ? bl : al;
  l++;

  res = malloc((l + 1) * sizeof(char));
  res[l] = '\0';

  while (--l >= 0)
  {
    c += --al >= 0 ? a[al] - '0' : 0;
    c += --bl >= 0 ? b[ bl] - '0' : 0;

    res[l] = c % 2 + '0';
    c /= 2; 
  }

  if (res[0] == '0')
    return res + 1;
  return res;
}

int main(int argc, char *argv[])
{
  char *a, *b;
  a = argv[1];
  b = argv[2];

  // printf("a: %s\n", a);
  // printf("b: %s\n", b);

  addBinary(a, b);

  return 0;
}