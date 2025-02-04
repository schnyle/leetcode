// Given an integer, convert it to a Roman numeral.

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

class Solution
{
public:
  std::string intToRoman(int num)
  {
    static std::unordered_map<int, std::string> charMap{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    int orderedNums[13]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string res = "";
    for (int i = 0; i < 13; ++i)
    {
      int n = orderedNums[i];
      while (n <= num)
      {
        res += charMap.at(n);
        num -= n;
      }
    }

    return res;
  }
};

int main()
{
  Solution s;
  for (int i = 0; i < 20; ++i)
  {
    printf("%d: %s\n", i, (s.intToRoman(i)).c_str());
  }
}