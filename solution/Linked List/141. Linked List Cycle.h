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
    bool hasCycle(ListNode *head)
    {
        ListNode* p = head;
        unordered_set<ListNode*> my_set;

        while(p != nullptr)
        {
            if(my_set.find(p) == my_set.end())
                my_set.insert(p);
            else
                return true;

            p = p->next;
        }
        return false;
    }
};