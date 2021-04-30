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
    ListNode* oddEvenList(ListNode* head)
    {

        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();

        ListNode* ans = odd;
        ListNode* dummy_even = even;

        while(head!= nullptr && head->next != nullptr)
        {
            odd->next = head;
            even->next = head->next;

            odd = odd->next;
            even = even->next;
            head = head->next->next;
        }
        even->next = nullptr;

        if(head != nullptr)
        {
            odd->next = head;
            odd = odd->next;
        }
        odd->next = dummy_even->next;

        return ans->next;
    }
};