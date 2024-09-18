// Given a list of non-negative integers `nums`, arrange them such that they
// form the largest number and return it.
// Since the result may be very large, so you need to return a string instead
// of an integer.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution
{
public:
  std::string largestNumber(std::vector<int> &nums)
  {
    std::vector<std::string> numsString;
    numsString.reserve(nums.size());

    std::transform(nums.cbegin(), nums.cend(), std::back_inserter(numsString), toString);

    auto compare = [](std::string a, std::string b)
    {
      return (a + b) > (b + a);
    };

    std::sort(numsString.begin(), numsString.end(), compare);

    std::string res = std::accumulate(numsString.cbegin(), numsString.cend(), std::string());

    if (res[0] == '0')
    {
      return "0";
    }

    return res;
  }

  static std::string toString(int x)
  {
    return std::to_string(x);
  }
};

int main()
{
  std::vector<int> nums{3, 30, 5, 9};
  // std::vector<int> nums{432, 43243};

  Solution s;
  std::string res = s.largestNumber(nums);
  std::cout << "ans: " << res << "\n";
}