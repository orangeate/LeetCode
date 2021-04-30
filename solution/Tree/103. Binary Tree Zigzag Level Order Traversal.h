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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        vector<int> vec;
        queue<TreeNode*> que;
        bool flag = false;

        if(root == nullptr)
            return ans;

        que.push(root);

        while(!que.empty())
        {
            vec.clear();
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* p = que.front();
                que.pop();
                vec.push_back(p->val);

                if(p->left != nullptr)
                    que.push(p->left);
                if(p->right != nullptr)
                    que.push(p->right);

            }
            if(flag)
                reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            flag = !flag;
        }

        return ans;
    }
};
