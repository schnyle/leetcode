// Given the head of a singly linked list and an integer k, split the linked
// list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts should
// have a size differing by more than one. This may lead to some parts being
// null.
// The parts shouldbe in the order of occurance in the input list, and parts
// occuring earlier should always have a size greater than or equal to
// parts occuring later.
// Return an array of the k parts.

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
  std::vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    size_t resLength = k;
    std::vector<ListNode *> res(resLength, nullptr);

    int listLength = getListLength(head);
    int subListMinLength = listLength / k;
    int overflow = listLength % k;

    ListNode *node = head;
    for (int i = 0; i < k; ++i)
    {
      if (node == nullptr)
      {
        break;
      }


      int subListLength = subListMinLength + (overflow ? 1 : 0);
      ListNode *subListNode = node;
      res[i] = subListNode;

      while (--subListLength)
      {
        subListNode = subListNode->next;
      }

      node = subListNode->next;
      subListNode->next = nullptr;

      if (overflow > 0)
      {
        --overflow;
      }
    }

    return res;
  }

  int getListLength(ListNode *head)
  {
    int length = 0;
    ListNode *node = head;

    while (node != nullptr)
    {
      ++length;
      node = node->next;
    }

    return length;
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

  ListNode *head = createList({1, 2, 3, 5, 4});
  printList(head);

  std::cout << s.getListLength(head) << "\n";

  auto res = s.splitListToParts(head, 2);

  std::cout << "\nres:\n";
  for (auto &x : res)
  {
    printList(x);
  }
}