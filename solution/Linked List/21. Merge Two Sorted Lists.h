#include "../global.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;

        ListNode* ans = new ListNode();
        ListNode* p = ans;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }
        }
        while(l1 != nullptr)
        {
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            p->next = new ListNode(l2->val);
            p = p->next;
            l2 = l2->next;
        }
        return ans->next;

    }
};