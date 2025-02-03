// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of
// the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

#include <iostream>
#include <vector>

class Solution
{
public:
  int maxArea(std::vector<int> &height)
  {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
      const int currArea = (right - left) * std::min(height[left], height[right]);
      maxArea = std::max(maxArea, currArea);

      if (height[left] < height[right])
      {
        ++left;
      }
      else
      {
        --right;
      }
    }

    return maxArea;
  }
};

int main()
{
  Solution s;
  // std::vector<int> h{1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::vector<int> h{1, 1};
  printf("%d\n", s.maxArea(h));
}