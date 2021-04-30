#include "../global.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root == nullptr)
            return root;

        queue<Node*> que;
        que.push(root);

        Node* dummy = new Node();

        while(!que.empty())
        {
            int size = que.size();
            Node* pre = dummy;
            for(int i = 0; i < size; i++)
            {
                auto p = que.front();
                que.pop();

                if(p->left != nullptr) que.push(p->left);
                if(p->right != nullptr) que.push(p->right);

                pre->next = p;
                pre = p;
            }
            pre->next = nullptr;
        }

        return root;
    }
};
