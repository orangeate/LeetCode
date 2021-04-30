#include "../global.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /* ---- 递归 ----
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int root_val = root->val;
        int p_val = p->val;
        int q_val = q->val;

        if(p_val > root_val && q_val > root_val)
            return lowestCommonAncestor(root->right, p, q);
        else if(p_val < root_val && q_val < root_val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;

    }
    */

    /* ---- 迭代 ----*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int p_val = p->val;
        int q_val = q->val;

        while(root != nullptr)
        {
            if(root->val > p_val && root->val > q_val)
                root = root->left;
            else if(root->val < p_val && root->val < q_val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};
