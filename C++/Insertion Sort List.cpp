/*

Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        if(!head) return NULL;
        ListNode *helper = new ListNode(-1);
        ListNode *cur = head;
        while(cur)
        {
            ListNode *tmp = helper;
            while(tmp->next && tmp->next->val <= cur->val)
                tmp = tmp->next;
            ListNode *next = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            cur = next;
        }
        return helper->next;
    }
};
