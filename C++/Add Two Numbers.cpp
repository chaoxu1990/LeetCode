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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = l1, *t1 = l1, *t2 = l2;
        while(l1 && l2)
        {
            int tmp = l1->val + l2->val;
            while(tmp > 9)
            {
                tmp -= 10;
                if(l1->next)
                    l1->next->val += 1;
                else
                {
                    //ListNode *n = new ListNode(1);
                    //l1->next = n;
                    l1->next = new ListNode(1);
                }
            }

            l1->val = tmp;

            t1 = l1;
            t2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(!l1 && l2)
        {
            t1->next = l2;
            while(l2)
            {
                while(l2->val > 9)
                {
                    if(l2->next)
                        l2->next->val += 1;
                    else
                    {
                        ListNode *m = new ListNode(1);
                        l2->next = m;
                    }
                    l2->val -= 10;
                }
                l2 = l2->next;
            }
        }
        else if(l1&&!l2)
        {
            while(l1)
            {
                while(l1->val > 9)
                {
                    if(l1->next)
                        l1->next->val +=1;
                    else
                    {
                        ListNode *o = new ListNode(1);
                        l1->next = o;
                    }
                    l1->val -= 10;
                }
                l1 = l1->next;
            }
        }
        return result;
    }
};
