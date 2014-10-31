/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
        ListNode *cur = head, *fakedHead = new ListNode(-1), *prev;
        fakedHead->next = head;
        prev = fakedHead;
        int value = head->val;
        while(cur&&cur->next)
        {
            value = cur->val;
            if(cur->next->val == value)
            {
                while(cur->next && cur->next->val == value)
                {
                    ListNode *tmp = cur;
                    cur = tmp->next;
                    prev->next = cur;
                    tmp->next = NULL;
                    free(tmp);
                }

                ListNode* tmp = cur;
                cur = tmp->next;
                prev->next = cur;
                tmp->next = NULL;
                free(tmp);
            }
            else
            {
                prev = cur;
                cur = cur->next;
                value = cur->val;
            }
        }

        return fakedHead->next;

    }
};
