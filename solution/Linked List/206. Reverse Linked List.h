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
    /* ---- list 头插法 ----
    ListNode* reverseList(ListNode* head)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* p = head;
        while(p != nullptr)
        {
            ListNode* q = p->next;
            p->next = dummy->next;
            dummy->next = p;

            p = q;
        }
        return dummy->next;
    }
    */
    /*---- 递归 ----*/
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};