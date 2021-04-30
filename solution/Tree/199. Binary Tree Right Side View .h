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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        queue<TreeNode*> que;

        if(root == nullptr)
            return ans;

        bool isOrderLeft = false;
        auto p = root;
        que.push(p);

        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                p = que.front();
                que.pop();

                if(p->left != nullptr)
                    que.push(p->left);
                if(p->right != nullptr)
                    que.push(p->right);
            }
            ans.push_back(p->val);
        }
        return ans;
    }
};
