// Given the head of a linked list and a integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

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
  ListNode *removeElements(ListNode *head, int val)
  {
    if (head == nullptr)
    {
      return head;
    }

    while (head->val == val)
    {
      if (head->next == nullptr)
      {
        return nullptr;
      }
      head = head->next;
    }

    ListNode *prev = head;
    ListNode *curr = head->next;
    while (curr != nullptr)
    {
      if (curr->val == val)
      {
        prev->next = curr->next;
        auto temp = curr;
        curr = curr->next;
        delete temp;
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