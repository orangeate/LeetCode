#include "../global.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return {};
        vector <vector<int>> ans;

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
            ans.push_back(vec);
        }

        return ans;
    }
};
