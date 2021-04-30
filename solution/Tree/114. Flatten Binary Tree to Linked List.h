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
    void flatten(TreeNode* root)
    {
        if(root == nullptr)
            return ;
        stack<TreeNode*> st;
        preoreder(root, st);
    }

    void preoreder(TreeNode* root, stack<TreeNode*> st)
    {
        auto p = root;
        st.push(p);
        while(!st.empty())
        {
            //visit p
            p = st.top();
            st.pop();
            if(p->right != nullptr)
                st.push(p->right);
            if(p->left != nullptr)
                st.push(p->left);

            if(p->left == nullptr && p->right == nullptr && !st.empty())
                p->right = st.top();
            else if(p->left != nullptr)
                p->right = p->left;
            else
                ;
            p->left = nullptr;
        }
    }
};
