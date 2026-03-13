// You are given two integers `m` and `n`, which represent the dimensions of a matrix.
// You are also given the `head` of a linked list of integers.
// Generate an `m x n` matrix that contains the integers in the linked list
// presented in spiral order (clockwise), starting from the top-left of the
// matrix. If there are remaining empty spaces, fill them with `-1`.
// Return the generated matrix.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode *head)
  {
    std::vector<std::vector<int>> res(m, std::vector<int>(n, -1));

    Direction dir = Direction::Right;

    ListNode *node = head;
    res[0][0] = node->val;
    node = node->next;

    int i = 0;
    int j = 0;
    while (node)
    {
      switch (dir)
      {
      case Direction::Up:
        if (i - 1 >= 0 && res[i - 1][j] == -1)
        {
          res[--i][j] = node->val;
        }
        else
        {
          dir = Direction::Right;
          continue;
        }
        break;
      case Direction::Down:
        if (i + 1 < m && res[i + 1][j] == -1)
        {
          res[++i][j] = node->val;
        }
        else
        {
          dir = Direction::Left;
          continue;
        }
        break;
      case Direction::Left:
        if (j - 1 >= 0 && res[i][j - 1] == -1)
        {
          res[i][--j] = node->val;
        }
        else
        {
          dir = Direction::Up;
          continue;
        }
        break;
      case Direction::Right:
        if (j + 1 < n && res[i][j + 1] == -1)
        {
          res[i][++j] = node->val;
        }
        else
        {
          dir = Direction::Down;
          continue;
        }
        break;
      }

      node = node->next;
    }

    for (auto &v : res)
    {
      std::cout << "[";
      for (auto &i : v)
      {
        if (i >= 0 && i <= 9)
        {
          std::cout << " ";
        }
        std::cout << i << " ";
      }
      std::cout << "]\n";
    }
    return res;
  }
  enum class Direction
  {
    Up,
    Down,
    Left,
    Right,
  };
};

ListNode *createList(std::vector<int> v)
{
  if (v.empty())
  {
    return nullptr;
  }

  ListNode *head = new ListNode(v[0]);
  ListNode *last = head;

  for (const auto &x : std::vector(v.cbegin() + 1, v.cend()))
  {
    ListNode *newNode = new ListNode(x);
    last->next = newNode;
    last = newNode;
  }

  return head;
}

int main()
{
  Solution s;

  ListNode *head = createList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

  s.spiralMatrix(5, 4, head);
}