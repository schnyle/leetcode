// You are given an array of integers `nums` and the `head` of a linked list.
// Return the `head` of the modified linked list after removing all nodes from
// the linked list that have a value that exists in `nums`.

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

#include <algorithm>
#include <iostream>
#include <unordered_set>
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
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head)
  {
    if (!head)
    {
      return head;
    }

    std::unordered_set<int> toRemove(nums.cbegin(), nums.cend());

    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr)
    {
      if (toRemove.find(curr->val) != toRemove.end())
      {
        if (prev == nullptr)
        {
          head = curr->next;
        }
        else
        {
          prev->next = curr->next;
        }
        curr = curr->next;
      }
      else
      {
        prev = curr;
        curr = curr->next;
      }
    }

    return head;
  }
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

void printList(ListNode *head)
{
  ListNode *node = head;

  std::cout << "[";
  while (node != nullptr)
  {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << "]\n";
}

int main()
{
  Solution s;
  ListNode *head = createList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> nums{1, 2, 3, 5, 8};

  printList(head);

  ListNode *res = s.modifiedList(nums, head);

  printList(res);
}