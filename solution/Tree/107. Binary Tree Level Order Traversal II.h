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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if (root == nullptr)
            return {};
        vector <vector<int>> ans;
        stack<vector<int>> st;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            vector<int> vec;
            for (int i = 0; i < n; ++i)
            {
                TreeNode* node = q.front();
                q.pop();

                vec.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            st.push(vec);
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
