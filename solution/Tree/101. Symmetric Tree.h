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

    bool is_mirror(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        if(left->val == right->val &&
           is_mirror(left->right, right->left) &&
           is_mirror(right->left, left->right))
            return true;
        else
            return false;

    }

    bool isSymmetric(TreeNode* root)
    {
        return is_mirror(root, root);
    }
};
