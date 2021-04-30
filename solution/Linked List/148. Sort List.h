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
    /* ---- 归并排序 ---- */
    ListNode* merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(0, nullptr);
        ListNode *p = dummy;
        while(head1 != nullptr && head2 != nullptr)
        {
            if(head1->val <= head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 != nullptr)
            p->next = head1;
        if(head2 != nullptr)
            p->next = head2;

        return dummy->next;
    }

    // [)
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if(head == nullptr)
            return head;

        if(head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        // 找到中间节点
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;

        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }
};