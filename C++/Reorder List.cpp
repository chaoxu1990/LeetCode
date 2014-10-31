/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    void reorderList(ListNode *head) {
        if(!head||!head->next||!head->next->next) return;

        ListNode *result = new ListNode(-1);
        ListNode *fast = head, *slow = head, *prev;

        while(fast&&fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = NULL;
        slow = reverseList(slow);
        fast = head;
        prev = result;
        //merge two lists together

        while(fast&&slow)
        {
            prev->next = fast;
            fast = fast->next;
            prev = prev->next;
            prev->next = slow;
            slow = slow->next;
            prev = prev->next;
        }

        if(fast&&!slow) prev->next = fast;
        else if(!fast&&slow) prev->next = slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        if(!head||!head->next) return head;
        ListNode* fakedHead = new ListNode(-1);
        fakedHead->next = head;

        for(ListNode *prev = head, *cur = head->next;cur;cur = prev->next)
        {
            prev->next = cur->next;
            cur->next = fakedHead->next;
            fakedHead->next = cur;
        }
        return fakedHead->next;
    }



};
