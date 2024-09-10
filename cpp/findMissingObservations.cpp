// You have observations of `m + n` 6-sided dice rolls with each face numbered
// from 1 to 6. `n` of the observations went missing, and you only have the
// observations of `m` rolls. Fortunately, you have also calculated the
// average value of the `n + m` rolls.
// You are given an integer array `rolls` of length `m` where `rolls[i]` is the
// value of the ith observation. You are also given the two integers
// `mean` and `n`.
// Return an array of length n containing the missing observations such that the
// average value of the `n + m` rolls is exactly the mean. If there are multiple
// valid answers, return any of them. If no such array exists, return an empty
// array.

#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:
  std::vector<int> missingRolls(std::vector<int> &rolls, int mean, int n)
  {
    int m = rolls.size();
    int sumOfGivenRolls = std::accumulate(rolls.cbegin(), rolls.cend(), 0);
    int sumOfMissingRolls = mean * (n + m) - sumOfGivenRolls;

    std::cout << sumOfGivenRolls << " " << sumOfMissingRolls << "\n";

    std::vector<int> res;

    if (sumOfMissingRolls < n || (6 * n) < sumOfMissingRolls)
    {
      return res;
    }

    res = std::vector(n, 1);
    int currentSumOfMissingRolls = n;
    int currentResIdx = 0;
    while (currentSumOfMissingRolls < sumOfMissingRolls)
    {
      if (res[currentResIdx] == 6)
      {
        ++currentResIdx;
      }

      ++res[currentResIdx];
      ++currentSumOfMissingRolls;
    }

    return res;
  }
};

int main()
{
  std::vector<int> rolls{3, 2, 4, 3};
  int mean = 4;
  int n = 2;

  Solution s;
  std::vector<int> res = s.missingRolls(rolls, mean, n);
  for (auto &x : res)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}