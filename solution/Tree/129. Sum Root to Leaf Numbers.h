#include "../global.h"
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
    int dfs(TreeNode* p, int sum)
    {
        if (p == nullptr)
            return 0;

        sum = sum * 10 + p->val;
        if (p->left == nullptr && p->right == nullptr)
        {
            return sum;
        }

        return dfs(p->left, sum) + dfs(p->right, sum);
    }
    int sumNumbers(TreeNode* root)
    {
        return dfs(root, 0);
    }
};
