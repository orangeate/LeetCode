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

    TreeNode* postorder(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr) return root;

        auto left = postorder(root->left, p, q);
        auto right = postorder(root->right, p, q);

        if(left != nullptr && right != nullptr)
            return root;
        if(root == p) return p;
        if(root == q) return q;

        return left == nullptr ? right : left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return postorder(root, p, q);
    }
};
