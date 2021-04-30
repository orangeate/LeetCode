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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *p = head;
        while(p != nullptr && p->next != nullptr)
        {
            if(p->val != p->next->val)
            {
                p = p->next;
            }
            else
            {
                ListNode* del = p->next;
                p->next = p->next->next;
                delete(del);
            }
        }
        return head;
    }
};