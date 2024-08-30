// Given an integer `num`, repeatedly add all its digits until the result
// has only one digit, and return it

#include <iostream>

class Solution
{
public:
  int addDigits(int num)
  {
    if (num < 10)
    {
      return num;
    }

    int res = 0;

    while (num > 9)
    {
      res += num % 10;
      num /= 10;
    }

    res += num;

    return addDigits(res);
  }
};

int main()
{
  Solution s;
  int x = 38;
  std::cout << s.addDigits(38) << "\n";
}