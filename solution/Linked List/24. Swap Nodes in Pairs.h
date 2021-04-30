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
    ListNode* swapPairs(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        p->next = head;
        while(p->next != nullptr && p->next->next != nullptr)
        {
            swap(p);
            p=p->next->next;
        }
        return dummy->next;
    }

    void swap(ListNode* pre)
    {
        ListNode* p = pre->next;
        ListNode* q = pre->next->next;

        pre->next = q;
        p->next = q->next;
        q->next = p;
    }
};