// Given two string `s` and `goal`, return true if and only if `s` can become `goal` after some number of shifts on `s`.
// A shift on `s` consists of moving the leftmost character of `s` to the rightmost position.

#include <iostream>
#include <string>

class Solution
{
public:
  bool rotateString(std::string s, std::string goal)
  {
    if (s.size() != goal.size())
    {
      return false;
    }
    
    s += s;
    return s.find(goal) != std::string::npos;
  }
};

int main()
{
  Solution sol;

  std::cout << sol.rotateString("abcde", "cdeab") << "\n";
  std::cout << sol.rotateString("abcde", "abced") << "\n";
}