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

    int get_height(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int left = get_height(root->left);              //left
        int right = get_height(root->right);            //right
        return max(left, right) + 1;                    //visit
    }

    bool isBalanced(TreeNode* root)
    {
        if(root == nullptr)
            return true;

        int left = get_height(root->left);
        int right = get_height(root->right);

        return abs(left - right) <= 1 ? isBalanced(root->left) && isBalanced(root->right) : false;

    }
};
