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
    /*  ---- 递归 ----
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if(root == nullptr)
            return;

        // visit
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    */
    /*  ---- 非递归 --- */
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(root == nullptr)
            return {};

        stack<TreeNode*, vector<TreeNode*>> st;
        vector<int> ans;
        TreeNode* p = root;

        st.push(p);

        while(!st.empty())
        {
            p = st.top();
            st.pop();

            //visit
            ans.push_back(p->val);

            if(p->right)
                st.push(p->right);
            if(p->left)
                st.push(p->left);
        }
        return ans;
    }
};
