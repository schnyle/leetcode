#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
  bool isPalindrome(std::string s)
  {
    s.erase(
        std::remove_if(
            s.begin(), s.end(),
            [](char c)
            { return !std::isalnum(c); }),
        s.end());

    std::transform(s.begin(), s.end(), s.begin(),
                   [](char c)
                   { return std::tolower(c); });

    std::string sr(s);
    std::reverse(sr.begin(), sr.end());

    return s == sr;
  }
};

int main()
{
  std::string s = "A man, a plan, a canal: Panama";
  // std::string s = "ha";
  Solution sol;

  std::cout << sol.isPalindrome(s) << "\n";
}