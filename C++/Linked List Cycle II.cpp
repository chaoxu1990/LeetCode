/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
         ListNode *fast = head, *slow = head;

         while(fast&&fast->next)
         {
             fast = fast->next->next;
             slow = slow->next;
             if(fast == slow)
             {
                 ListNode *slow2 = head;
                 while(slow2!=slow)
                 {
                     slow = slow->next;
                     slow2 = slow2->next;
                 }
                 return slow;
             }

         }
         return NULL;
    }
};
