/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head||k==0) return head;

        ListNode *end = head;
        int total_cnt = 1, cur_cnt = 0;

        while(end->next) {end = end->next; total_cnt++;}
        end->next = head;

        k %= total_cnt;
        cur_cnt = total_cnt - k;

        while(cur_cnt--) end = end->next;
        head = end->next;
        end->next = NULL;

        return head;

    }
};
