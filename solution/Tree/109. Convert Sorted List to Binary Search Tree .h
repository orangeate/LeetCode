#include "../global.h"
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
class Solution {
public:

    ListNode* getMid(ListNode* left, ListNode* right)
    {
        ListNode* slow = left;
        ListNode* fast = left;

        while(fast != right && fast->next != right)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    TreeNode* buildTree(ListNode* left, ListNode* right)
    {
        if(left == right)
            return nullptr;

        ListNode* mid = getMid(left, right);

        TreeNode* tree = new TreeNode(mid->val);

        tree->left = buildTree(left, mid);
        tree->right = buildTree(mid->next, right);

        return tree;

    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        return buildTree(head, nullptr);
    }
};
