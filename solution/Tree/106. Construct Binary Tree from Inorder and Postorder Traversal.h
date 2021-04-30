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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        int in_l, int in_r, int post_l, int post_r)
    {
        if (in_l > in_r)
        {
            return nullptr;
        }

        // 根节点指针
        int post_root = post_r;
        int in_root = index[postorder[post_root]];

        // 建立根节点
        TreeNode* root = new TreeNode(postorder[post_r]);

        // 右子树节点个数
        int right_num = in_r - in_root;

        root->right = buildTree(inorder, postorder, in_root+1, in_r, post_r - right_num, post_r-1);
        root->left = buildTree(inorder, postorder, in_l, in_root-1, post_l, post_r - right_num-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        for (int i = 0; i < postorder.size(); i++)
            index[inorder[i]] = i;

        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
