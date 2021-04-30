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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* p = head;
        ListNode* q = p;

        for (int i = 0; i < n; i++)
            q = q->next;

        if(q == nullptr)
            return p->next;

        while(q->next != nullptr)
        {
            p = p->next;
            q = q->next;
        }

        q = p->next;
        p->next = p->next->next;

        delete q;

        return head;

    }
};