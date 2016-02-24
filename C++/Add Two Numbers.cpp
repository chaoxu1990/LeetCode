/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *fakedHead = new ListNode(-1);
        ListNode *result = fakedHead, *tmp1 = l1, *tmp2 = l2;
        int carry = 0;
        while(tmp1 != NULL || tmp2 != NULL || carry != 0)
        {
            int sum = (tmp1 == NULL?0:tmp1->val) + (tmp2 == NULL?0:tmp2->val) + carry;
            carry = sum/10;
            sum = sum%10;
            result->next = new ListNode(sum);
            result = result->next;
            tmp1 = tmp1 == NULL?NULL:tmp1->next;
            tmp2 = tmp2 == NULL?NULL:tmp2->next;
        }
        
        return fakedHead->next;
    }
};
