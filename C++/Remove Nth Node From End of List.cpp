/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fakedHead = new ListNode(-1);
        ListNode *fast = fakedHead, *slow = fakedHead;
        fakedHead->next = head;
        for(int i = 0; i<n; ++i)
            fast = fast->next;

            while(fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }

            ListNode *tmp = slow->next;
            slow->next = tmp?tmp->next:NULL;
            free(tmp);

        return fakedHead->next;
    }
};
