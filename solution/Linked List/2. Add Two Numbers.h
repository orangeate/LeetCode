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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1->val == 0 && (l1->next == nullptr)) return l2;
        if(l2->val == 0 && (l2->next == nullptr)) return l1;

        ListNode *ans = new ListNode(0);
        ListNode *p = ans;
        int carry = 0;

        while(l1 || l2)
        {
            int v1 = l1? l1->val : 0;
            int v2 = l2? l2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;

            p->next = new ListNode(sum % 10);
            p = p->next;

            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }
        if(carry != 0)
            p->next = new ListNode(1);

        return ans->next;
    }
};