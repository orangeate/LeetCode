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
/* 路径的长度为该路径经过的节点数减一，所以求直径（即求路径长度的最大值）等效于求路径经过节点数的最大值减一。*/
class Solution {
public:
    int length;
    int dfs(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int left_num = dfs(root->left);
        int right_num = dfs(root->right);
        length = max(length, left_num + right_num + 1);
        return max(left_num, right_num) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        length = 1;
        dfs(root);
        return length-1;
    }
};
