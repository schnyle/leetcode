// You are given a string `allowed` consisting of distinct characters and an
// array of strings `words`. A string is consistent if all characters in the
// string appear in the string `allowed`.
// Return the number of consistent strings in the array `words`.

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
  int countConsistentStrings(
      std::string allowed, std::vector<std::string> &words)
  {
    int count = 0;

    for (auto &w : words)
    {
      if (w.find_first_not_of(allowed) == std::string::npos)
      {
        ++count;
      }
    }

    return count;
  }
};

int main()
{
  std::string allowed {"ab"};
  std::vector<std::string> words{"ab", "bd", "aaab", "baa", "badab"};

  Solution s;
  std::cout << s.countConsistentStrings(allowed, words);
}