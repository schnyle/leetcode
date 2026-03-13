// Given an array `arr` of integers, check if there exist two indices `i` and `j` such that:
//   - i != j
//   - 0 <= i, j < arr.length
//   - arr[i] == 2 * arr[j]

#include <iostream>
#include <vector>
#include <set>

class Solution
{
public:
  bool checkIfExist(std::vector<int> &arr)
  {
    std::set<int> s;

    for (const auto ele : arr)
    {
      if (s.find(ele) != s.cend())
      {
        return true;
      }

      s.insert(2 * ele);
      if (ele % 2 == 0)
      {
        s.insert(ele / 2);
      }
    }

    return false;
  }
};

int main()
{
  Solution s;

  // example 1
  std::vector<int> i1{10, 2, 5, 3};
  std::cout << "example 1:\n";
  std::cout << "expected: true, actual: " << (s.checkIfExist(i1) ? "true" : "false") << "\n";
  std::cout << "\n";

  // example 2
  std::vector<int> i2{3, 1, 7, 11};
  std::cout << "example 2:\n";
  std::cout << "expected: false, actual: " << (s.checkIfExist(i2) ? "true" : "false") << "\n";
  std::cout << "\n";
}