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
class BSTIterator {
public:

    vector<int> val;
    int index;

    void inorder(TreeNode* root)
    {
        if(root == nullptr)
            return;

        inorder(root->left);
        //visit
        val.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode* root)
    {
        index = 0;
        inorder(root);
    }

    int next()
    {
        return val[index++];
    }

    bool hasNext()
    {
        return index < val.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
