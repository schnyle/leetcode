#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
  bool isValid(std::string s)
  {
    std::vector<char> v;
    for (auto &c : s)
    {
      switch (c)
      {
      case '(':
      case '[':
      case '{':
        v.push_back(c);
        break;
      case ')':
        if (!v.size() || v.back() != '(')
          return false;
        v.pop_back();
        break;
      case ']':
        if (!v.size() || v.back() != '[')
          return false;
        v.pop_back();
        break;
      case '}':
        if (!v.size() || v.back() != '{')
          return false;
        v.pop_back();
        break;
      }
    }

    if (!v.size())
      return true;
    else
      return false;
  }
};

int main()
{
  const std::string test = "]";
  Solution s;

  std::cout << (s.isValid(test) ? "t" : "f") << "\n";
}