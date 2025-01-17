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
    int minDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(left != nullptr && right != nullptr)
            return min(left, right) + 1;
        else
            return left + right +1;

    }
};
