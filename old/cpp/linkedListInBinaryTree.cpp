// Given a binary tree `root` and a linked list with `head` as the first node.
// Return True if all the elements in the linked list starting from the `head`
// correspond to some downward path connected in the binary tree otherwise
// return False.
// In this context downward path means a path that starts at some node and
// goes downwards.

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isSubPath(ListNode *head, TreeNode *root)
  {
    if (!root)
    {
      return false;
    }

    std::queue<TreeNode *> q;
    q.push(root);

    TreeNode *treeNode = root;
    while (!q.empty())
    {
      treeNode = q.front();
      q.pop();

      if (helper(treeNode, head))
      {
        return true;
      }

      if (treeNode->left)
      {
        q.push(treeNode->left);
      }
      if (treeNode->right)
      {
        q.push(treeNode->right);
      }
    }

    return false;
  }

  bool helper(TreeNode *treeNode, ListNode *listNode)
  {
    if (!listNode)
    {
      return true;
    }

    if (!treeNode)
    {
      return false;
    }

    if (treeNode->val != listNode->val)
    {
      return false;
    }

    return helper(treeNode->left, listNode->next) || helper(treeNode->right, listNode->next);
  }
};

int main()
{
}