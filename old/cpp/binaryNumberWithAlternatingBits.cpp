// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have
// different values.

#include <iostream>

class Solution
{
public:
  bool hasAlternatingBits(int n)
  {
    long nxor = n ^ (n >> 1);
    return (nxor & (nxor + 1)) == 0;
  }
};

int main()
{
  Solution s;

  int x = 5;
  printf("%d: %s\n", x, s.hasAlternatingBits(x) ? "true" : "false");

  int y = 7;
  printf("%d: %s\n", y, s.hasAlternatingBits(y) ? "true" : "false");

  int z = 11;
  printf("%d: %s\n", z, s.hasAlternatingBits(z) ? "true" : "false");
}