// You are given a 0-indexed 1-dimensional (1D) integer array `original`, and
// two integers, `m` and `n`. You are tasked with creating a 2-dimesional (2D)
// array with `m` rows and `n` columns using all the elements from `original`.
// The elements from indices `0` to `n - 1` (inclusive) of `orignal` should form
// the first row of the constructed 2D array, the elements from indices `n` to
// `2 * n - 1` (inclusive) should form the second row of the constructed 2D
// array, and so on.
// Return an `m x n` 2D array constructed according to the above procedure, or
// an empty 2D array if it is impossible.

#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> construct2DArray(std::vector<int> &original, int m, int n)
  {
    if (original.size() != m * n)
    {
      return {};
    }

    std::vector<std::vector<int>> res(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
      std::copy(original.cbegin() + i * n, original.cbegin() + (i + 1) * n, res[i].begin());
    }

    return res;
  }
};