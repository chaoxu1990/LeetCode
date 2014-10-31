/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
       ListNode *fakedHead = new ListNode(-1);
       fakedHead -> next = head;
       ListNode *prev = fakedHead;
       for(int i = 0; i<m-1; i++)
       {
           prev = prev->next;
       }

       ListNode* head2 = prev;
       prev = head2->next;
       ListNode *cur = prev->next;
       for(int i = m; i<n; i++)
       {
           prev->next = cur->next;
           cur->next = head2->next;
           head2->next = cur;
           cur = prev->next;
       }
       return fakedHead->next;
    }
};
