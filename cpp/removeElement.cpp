// Given an integer array `nums` and an integer `val`, remove all occurences of
// `val` in `nums` in-place. The order of the elements may be changed. Then
// return the number of elements in `nums` which are not equal to `val`.

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int> &nums, int val) {
    auto erase_begin = std::partition(nums.begin(), nums.end(),
                                      [val](int x) { return x != val; });
    nums.erase(erase_begin, nums.end());
    return nums.size();
  }
};

int main() {
  std::vector<int> nums{3, 2, 2, 3};
  int val{3};

  Solution sol;
  auto res = sol.removeElement(nums, val);
  std::cout << res << "\n";
  for (auto x : nums) {
    std::cout << x;
  }
  std::cout << "\n";
}