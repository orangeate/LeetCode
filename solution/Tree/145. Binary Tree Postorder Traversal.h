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
    void postorder(TreeNode* root, vector<int>& ans)
    {
        if(root == nullptr)
            return;

        postorder(root->left, ans);
        postorder(root->right, ans);

        //visit
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        postorder(root, ans);

        return ans;
    }
    */
    /* ---- 非递归 ----*/
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(root == nullptr)
            return {};

        stack<TreeNode*, vector<TreeNode*>> st1;
        stack<TreeNode*, vector<TreeNode*>> st2;
        vector<int> ans;
        TreeNode* p = root;

        st1.push(p);

        while(!st1.empty())
        {
            p = st1.top();
            st1.pop();

            st2.push(p);

            if(p->left)
                st1.push(p->left);
            if(p->right)
                st1.push(p->right);
        }

        while(!st2.empty())
        {
            p = st2.top();
            st2.pop();

            ans.push_back(p->val);
        }
        return ans;
    }
};
