// You are given a string `s` consisting of lowercase English letters, and an
// integer `k`.
// First, convert `s` into an integer by replacing each letter with its position
// in the alphabet (i.e., replace `a` with `1`, `b` with `2`, ..., `z` with 26).
// Then, transform the integer by replacing it with the sum of its digits.
// Repeat the transform operation `k` times in total.
// Return the resulting integer after performing the operations described above.

#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <limits>

class Solution
{
public:
  int getLucky(std::string s, int k)
  {
    s.reserve(s.size() * 2);

    auto iter = s.cbegin();
    while (iter != s.cend())
    {
      std::string newChars = std::to_string(*iter - 'a' + 1);
      s.replace(iter, iter + 1, newChars);
      iter += newChars.size();
    }

    auto transform = [](std::string s) -> std::string 
    {
      int resInt = 0;

      auto iter = s.cbegin();
      while (iter != s.cend())
      {
        resInt += *iter - '0';
        ++iter;
      }

      return std::to_string(resInt);
    };

    while (k--)
    {
      s = transform(s);
    }

    return std::stoi(s);
  }
};

int main()
{
  std::string s = "fleyctuuajsr";
  int k = 2;

  Solution sol;
  std::cout << sol.getLucky(s, k) << "\n";
}