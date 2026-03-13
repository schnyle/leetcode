// Given the head of a linked list `head`, in which each  node contains an
// integer value.
// Between every pair of adjacent nodes, insert a new node with a value equal
// to the greatest common divisor of them.
// Return the linked list after insertion.

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
  ListNode *insertGreatestCommonDivisors(ListNode *head)
  {
    if (!head)
    {
      return nullptr;
    }

    ListNode *node = head;
    while (node)
    {
      if (!node->next)
      {
        break;
      }
      int newVal = gcd(node->val, node->next->val);

      ListNode *newNode = new ListNode(newVal, node->next);
      node->next = newNode;

      node = node->next->next;
    }

    return head;
  }

  int gcd(int a, int b)
  {
    while (b != 0)
    {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
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
  ListNode *head = createList({18, 6, 10, 3});
  printList(head);

  Solution s;
  ListNode *res = s.insertGreatestCommonDivisors(head);
  printList(res);
}