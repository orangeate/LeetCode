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

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail)
    {
        ListNode* dummy = new ListNode();

        ListNode* p = head;
        while(p != tail)
        {
            ListNode* next = p->next;
            p->next = dummy->next;
            dummy->next = p;

            p = next;
        }

        head->next = tail;
        return {dummy->next, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* dummy = new ListNode();

        ListNode* p = head;

        ListNode* pre = dummy;
        while(p != nullptr)
        {
            ListNode* local_head = p;
            ListNode* local_tail = p;

            for(int i = 0; i < k; i++)
            {
                if(local_tail == nullptr)
                    return dummy->next;
                local_tail = local_tail->next;
            }

            auto result = reverse(local_head, local_tail);
            local_head = result.first;
            local_tail = result.second;

            pre->next = local_head;
            pre = local_tail;

            p = pre->next;
        }
        return dummy->next;
    }
};