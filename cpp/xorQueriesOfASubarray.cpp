// You are given an array `arr` of positive integers. You are also given the
// array `queries` where `queries[i] = [left_i, right_i]`.
// For each query `i` compute the XOR of elements from `left_i` to `right_i`
// (that is, `arr[left_i] XOR arr[left_i + 1] XOR ... XOR arr[right_i]`).
// Return an array `answer` where `answer[i]` is the answer to the ith query.

#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> xorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries)
  {
    std::vector<int> res;
    res.reserve(arr.size());

    for (int i = 1; i < arr.size(); ++i)
    {
      arr[i] ^= arr[i - 1];
    }

    for (auto &lr : queries)
    {
      auto left = lr[0];
      auto right = lr[1];

      if (left == 0)
      {
        res.push_back(arr[right]);
      }
      else
      {
        res.push_back(arr[right] ^ arr[left - 1]);
      }
    }
    return res;
  }
};

int main()
{
  // std::vector<int> arr{1, 3, 4, 8};
  // std::vector<std::vector<int>> queries{
  //     std::vector{0, 1},
  //     std::vector{1, 2},
  //     std::vector{0, 3},
  //     std::vector{3, 3},
  // };

  std::vector<int> arr{16};
  std::vector<std::vector<int>> queries{
      std::vector{0, 0},
      std::vector{0, 0},
      std::vector{0, 0},
      std::vector{0, 0},
  };

  Solution s;
  for (auto &x : s.xorQueries(arr, queries))
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}