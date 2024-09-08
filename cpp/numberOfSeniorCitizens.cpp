#include <string>
#include <vector>
#include <iostream>
#include <numeric>

class Solution
{
public:
  int countSeniors(std::vector<std::string> &details)
  {
    return std::accumulate(details.begin(), details.end(), 0, [](int acc, std::string &d) {
      std::string age_str = d.substr(11, 2);
      int age = std::stoi(age_str);
      return acc + (age > 60 ? 1 : 0);
    });
  }
};

int main()
{
  const std::string hi = "hello";

  std::cout << hi.substr(2, 2) << "\n";
}