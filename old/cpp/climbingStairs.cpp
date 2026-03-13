// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <iostream>

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;

    int prev1 = 1;
    int prev2 = 2;

    for (int i = 3; i <= n; i++)
    {
      int curr = prev1 + prev2;
      prev1 = prev2;
      prev2 = curr;
    }
    return prev2;
  }
};

int main()
{
  Solution s;
  for (int i = 1; i <= 6; ++i)
  {
    printf("%d: %d\n", i, s.climbStairs(i));
  }
}