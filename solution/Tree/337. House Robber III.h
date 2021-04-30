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

    /*
        f: 当前节点偷取后金额
        g: 当前节点不偷金额
    */
    unordered_map<TreeNode*, int> f, g;


    void dfs(TreeNode* p)
    {
        if(p == nullptr)
            return;
        dfs(p->left);
        dfs(p->right);
        //visit
        f[p] = p->val + g[p->left] + g[p->right];
        g[p] = max(f[p->left], g[p->left]) + max(f[p->right], g[p->right]);
    }

    int rob(TreeNode* root)
    {
        dfs(root);
        return max(f[root], g[root]);
    }
};
