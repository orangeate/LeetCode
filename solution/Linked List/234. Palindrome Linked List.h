#include "../global.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> vec;
        ListNode* p = head;
        while(p != nullptr)
        {
            vec.push_back(p->val);
            p = p->next;
        }

        int n = vec.size() - 1;
        for(int i = 0; i < vec.size() / 2; i++)
        {
            if(vec[i] != vec[n-i])
                return false;
        }
        return true;

    }
};