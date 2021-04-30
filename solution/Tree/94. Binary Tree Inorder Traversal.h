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
    /* ---- 递归 ----
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root == nullptr)
            return;

        inorder(root->left, ans);
        // visit
        ans.push_back(root->val);

        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    */
    /* ---- 非递归 ----*/
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root == nullptr)
            return ans;

        TreeNode* p = root;
        while(p != nullptr || !st.empty())
        {
            if(p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                p = st.top();
                st.pop();
                // visit p
                ans.push_back(p->val);
                p = p->right;
            }
        }

        return ans;
    }
};
