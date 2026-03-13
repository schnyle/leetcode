// You are given an integer array prices where prices[i] is the price of the ith item in a shop. There is a special
// discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j]
// where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount
// at all. Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop,
// considering the special discount.

#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  std::vector<int> finalPrices(std::vector<int> &prices)
  {
    for (size_t i = 0; i < prices.size(); ++i)
    {
      const auto it = std::find_if(prices.cbegin() + i + 1, prices.cend(), [&](int x)
                                   { return x <= prices[i]; });
      if (it != prices.cend())
      {
        prices[i] -= *it;
      }
    }

    return prices;
  }
};

int main()
{
  Solution s;

  // example 1
  std::vector<int> i1{8, 4, 6, 2, 3};
  std::vector<int> o1{4, 2, 4, 2, 3};
  auto r1 = s.finalPrices(i1);
  std::cout << "Example 1:\n"
            << "\tExpected: ";
  for (auto &x : o1)
  {
    std::cout << x << " ";
  }
  std::cout << "\n\tResult: ";
  for (auto &x : r1)
  {
    std::cout << x << " ";
  }
  std::cout << "\n\n";

  // example 2
  std::vector<int> i2{1, 2, 3, 4, 5};
  std::vector<int> o2{1, 2, 3, 4, 5};
  auto r2 = s.finalPrices(i2);
  std::cout << "Example 2:\n"
            << "\tExpected: ";
  for (auto &x : o2)
  {
    std::cout << x << " ";
  }
  std::cout << "\n\tResult: ";
  for (auto &x : r2)
  {
    std::cout << x << " ";
  }
  std::cout << "\n\n";

  // example 3
  std::vector<int> i3{10, 1, 1, 6};
  std::vector<int> o3{9, 0, 1, 6};
  auto r3 = s.finalPrices(i3);
  std::cout << "Example 3:\n"
            << "\tExpected: ";
  for (auto &x : o3)
  {
    std::cout << x << " ";
  }
  std::cout << "\n\tResult: ";
  for (auto &x : r3)
  {
    std::cout << x << " ";
  }
  std::cout << "\n\n";
}