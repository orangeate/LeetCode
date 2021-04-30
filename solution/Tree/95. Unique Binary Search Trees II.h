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

    /*
        二叉搜索树: 【节点的值】> 左子树所有节点的值，< 右子树所有节点的值
    */
    vector<TreeNode*> generateTrees(int start, int end)
    {
        if(start > end)
            return {nullptr};

        vector<TreeNode*> allTrees;

        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> left = generateTrees(start, i-1);
            vector<TreeNode*> right = generateTrees(i+1, end);

            for(auto l : left)
                for(auto r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    allTrees.push_back(root);
                }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        if(n == 0)
            return {nullptr};
        return generateTrees(1, n);
    }
};
