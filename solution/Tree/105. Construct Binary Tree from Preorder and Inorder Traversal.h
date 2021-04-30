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

    // 中序遍历 {值， 指针}
    unordered_map<int, int> index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int pre_l, int pre_r, int in_l, int in_r)
    {
        if (pre_l > pre_r)
        {
            return nullptr;
        }

        // 根节点指针
        int pre_root = pre_l;
        int in_root = index[preorder[pre_root]];

        // 建立根节点
        TreeNode* root = new TreeNode(preorder[pre_root]);

        // 子树节点个数
        int left_num = in_root - in_l;

        root->left = buildTree(preorder, inorder, pre_l+1, pre_l+left_num, in_l, in_root-1);
        root->right = buildTree(preorder, inorder, pre_l+left_num+1, pre_r, in_root+1, in_r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // {节点值， 节点指针}
        for (int i = 0; i < preorder.size(); i++)
            index[inorder[i]] = i;

        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};
