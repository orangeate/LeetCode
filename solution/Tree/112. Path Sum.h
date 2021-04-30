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
    /* ---- 递归 ----*/
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return false;

        if(root->val == sum  && root->left == nullptr && root->right == nullptr)
            return true;

        return hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum - root->val);
    }
};
