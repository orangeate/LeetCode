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
    /* ----  深度优先搜索 ---- */
    void pre_order(TreeNode* root, vector<string>& ans, string path)
    {
        if(root == nullptr)
            return;
        path = path + "->" + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }
        pre_order(root->left, ans, path);
        pre_order(root->right, ans, path);
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        stack<TreeNode*> st;
        string path = "";
        if(root ==nullptr)
            return ans;
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
            return ans;
        }
        pre_order(root->left, ans, path);
        pre_order(root->right, ans, path);

        return ans;
    }
};
