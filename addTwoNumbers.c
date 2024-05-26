// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode *tail = NULL;
  struct ListNode *head = NULL;

  int carry = 0;

  while (l1 != NULL || l2 != NULL || carry != 0)
  {
    int l1Val = l1 ? l1->val : 0;
    int l2Val = l2 ? l2->val : 0;
    int sum = l1Val + l2Val + carry;
    int newVal = sum % 10;
    carry = sum / 10;

    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = newVal;
    newNode->next = NULL;

    if (!head)
    {
      head = newNode;
    }
    else
    {
      tail->next = newNode;
    }

    tail = newNode;

    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;
  }

  return head;
}
