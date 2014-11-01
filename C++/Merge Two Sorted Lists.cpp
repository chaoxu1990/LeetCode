/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/


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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *c1 = l1, *c2 = l2, *cur;
        ListNode *h1 = new ListNode(-1);
        cur = h1;
        while(c1&&c2)
        {
            if(c1->val <= c2->val)
            {
                cur->next = c1;
                cur = cur->next;
                c1 = c1->next;
            }

            else if (c1->val > c2->val)
            {
                cur->next = c2;
                cur = cur->next;
                c2 = c2->next;
            }
        }

        if(c1&&!c2) cur->next = c1;
        else if(!c1&&c2) cur->next = c2;

        return h1->next;
    }
};
