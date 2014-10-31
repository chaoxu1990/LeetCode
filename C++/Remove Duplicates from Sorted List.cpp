/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head||!head->next) return head;
        ListNode* cur = head;
        int value = head->val;

        while(cur->next)
        {
            if(cur->next->val == value)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                free(tmp);
            }
            else
            {
                cur = cur->next;
                value = cur->val;
            }
        }

        return head;
    }
};
