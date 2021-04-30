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
    ListNode* insertionSortList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* list_p = head->next;
        head->next = nullptr;

        while(list_p != nullptr)
        {
            ListNode* newlist_pre = dummy;
            ListNode* next = list_p->next;
            while(newlist_pre->next != nullptr)
            {
                if(list_p->val > newlist_pre->next->val)
                    newlist_pre = newlist_pre->next;
                else
                {
                    list_p->next = newlist_pre->next;
                    newlist_pre->next = list_p;
                    break;
                }
            }
            if(newlist_pre->next == nullptr)
            {
                newlist_pre->next = list_p;
                list_p->next = nullptr;
            }
            list_p = next;
        }

        return dummy->next;
    }
};