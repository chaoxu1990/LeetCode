/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head || !head->next) return head;
        int cnt = 0;
        ListNode *fakedHead = new ListNode(-1);
        fakedHead->next = head;
        ListNode *prev = head, *cur = fakedHead, *tmpHead = fakedHead;
        while(cur)
        {
            for(cnt = 0; cnt<k&&cur; cnt++)
                cur = cur->next;
            if(cnt==k&&cur)
            {
                cur = prev->next;
                for(int i = 0; i<k-1; ++i)
                {
                    prev->next = cur->next;
                    cur->next = tmpHead->next;
                    tmpHead->next = cur;
                    cur = prev->next;
                }

                if(cur&&cur->next)
                {
                    tmpHead = prev;
                    prev = cur;
                    cur = tmpHead;
                }
                else break;
            }
            else break;
        }

        return fakedHead->next;
    }
};
