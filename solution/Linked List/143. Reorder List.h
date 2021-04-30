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
    void reorderList(ListNode* head)
    {
        deque<ListNode*> deq;
        ListNode* dummy = new ListNode();
        bool seq = true;

        while(head != nullptr)
        {
            deq.push_back(head);
            head = head->next;
        }

        ListNode* p = dummy;
        while(!deq.empty())
        {
            if(seq == true)
            {
                p->next = deq.front();
                deq.pop_front();
            }
            else
            {
                p->next = deq.back();
                deq.pop_back();
            }
            p = p->next;
            seq = !seq;
        }

        p->next = nullptr;
    }
};