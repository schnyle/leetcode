// Given a string `columnTitle`

#include <string>
#include <cmath>
#include <iostream>

class Solution
{
public:
  int titleToNumber(std::string columnTitle)
  {
    int res = 0;
    for (int i = columnTitle.length() - 1; i >= 0; --i)
    {
      res += (columnTitle[i] - 'A' + 1) * std::pow(26, (columnTitle.length() - 1) - i);
    }
    return res;
  }
};

int main()
{
  Solution s;

  printf("AA: %d\n", s.titleToNumber("AA"));
}