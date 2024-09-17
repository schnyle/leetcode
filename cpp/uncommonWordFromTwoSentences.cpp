// A sentence is a string of single-space separated words where each word
// consists of only lowercase letters.
// A word is uncommon if it appears exactly once in one of the sentences, and
// does not appear in the other sentence.
// Given two sentences `s1` and `s2`, return a list of all the uncommon words.
// You may return the answer in any order.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

class Solution
{
public:
  std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2)
  {
    std::stringstream stream(s1 + " " + s2);
    std::string word;
    std::unordered_map<std::string, int> wordMap;

    while (stream >> word)
    {
      ++wordMap[word];
    }

    std::vector<std::string> res;
    res.reserve(wordMap.size());
    for (const auto &keyVal : wordMap)
    {
      if (keyVal.second == 1)
      {
        res.push_back(keyVal.first);
      }
    }

    return res;
  }
};

int main()
{
  std::string s1{"this apple is sweet"};
  std::string s2{"this apple is sour"};

  Solution s;
  std::vector res = s.uncommonFromSentences(s1, s2);
  for (auto &w : res)
  {
    std::cout << w << " ";
  }
  std::cout << "\n";
}