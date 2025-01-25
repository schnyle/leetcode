// You are given two integer arrays `nums1` and `nums2`, sorted in non-decreading order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be sorted inside the array nums1.
// To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be
// merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include <vector>
#include <iostream>

class Solution
{
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
  {
    if (m == 0)
    {
      nums1 = nums2;
      return;
    }

    int idx1 = 0, idx2 = 0;
    for (; idx2 < n; ++idx2)
    {
      while (idx1 < m + idx2 && nums2[idx2] >= nums1[idx1])
      {
        ++idx1;
      }

      for (int i = m + idx2; i > idx1; --i)
      {
        nums1[i] = nums1[i - 1];
      }

      nums1[idx1] = nums2[idx2];
    }
  }
};

int main()
{
  Solution s;

  std::vector<int> n1(6, 0);
  n1[0] = 1;
  n1[1] = 2;
  n1[2] = 3;

  std::vector<int> n2{2, 5, 6};

  s.merge(n1, 3, n2, 3);

  for (const auto &x : n1)
  {
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}