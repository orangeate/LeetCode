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
    /* ---- 使用 dummy node ----*/
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head == nullptr)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* p = dummy;

        while(p != nullptr && p->next != nullptr)
        {
            if(p->next->val == val)
            {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
                p = p->next;
        }
        return dummy->next;
    }
};