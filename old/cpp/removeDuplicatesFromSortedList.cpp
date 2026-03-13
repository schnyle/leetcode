// Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.

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
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == nullptr)
    {
      return head;
    }

    ListNode *node = head->next;
    ListNode *lastNode = head;

    while (node != nullptr)
    {
      if (node->val == lastNode->val)
      {
        lastNode->next = node->next;
        auto temp = node;
        node = node->next;
        delete temp;
      }
      else
      {
        lastNode = node;
        node = lastNode->next;
      }
    }

    return head;
  }
};