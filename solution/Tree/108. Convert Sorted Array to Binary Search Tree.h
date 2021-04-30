#include "../global.h"
/*
    方法一：中序遍历，总是选择中间位置左边的数字作为根节点
    方法二：中序遍历，总是选择中间位置右边的数字作为根节点
    方法三：中序遍历，选择任意一个中间位置数字作为根节点
 */
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
    TreeNode* get_mid(vector<int>& nums, int begin, int end)
    {
        if( !(begin < end) )
            return nullptr;

        int mid = begin + (end-begin)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = get_mid(nums, begin, mid);
        node->right = get_mid(nums, mid+1, end);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return get_mid(nums, 0, nums.size());
    }
};
