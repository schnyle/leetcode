// Given an integer `n`, return all the numbers in the range [1, n] sorted in
// lexicographical order.
// You must write an algorithm that runs in O(n) time and uses O(1) extra space.

#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> lexicalOrder(int n)
  {
    std::vector<int> res;
    res.reserve(n);
    int x = 1;

    for (int i = 0; i < n; ++i)
    {
      res.push_back(x);

      if (x * 10 <= n)
      {
        x *= 10;
      }
      else
      {
        if (x >= n || x % 10 == 9)
        {
          while (x % 10 == 9 || x + 1 > n)
          {
            x /= 10;
          }
        }
        x++;
      }
    }

    return res;
  }
};

int main()
{
  int n = 105;

  Solution s;
  auto res = s.lexicalOrder(n);
  std::cout << "res:\n";
  for (auto &x : res)
  {
    std::cout << x << " ";
  }
  std::cout << "\nend res\n";
}