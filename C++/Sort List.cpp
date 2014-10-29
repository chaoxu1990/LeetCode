/*

Sort a linked list in O(n log n) time using constant space complexity.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//Solution No.1 using recursion O(nlogn), actually
//it's not constant space because recursion also costs the space.

class Solution {
public:
    ListNode *sortList(ListNode *head) {
     if(!head || !(head->next)) return head;

     ListNode *fast = head, *slow = head;
     //while(fast->next->next && fast->next)
     //This will cause segmentation fault.
     //Should always check next first then next->next.
     while(fast->next && fast->next->next)
     {
         fast = fast->next->next;
         slow = slow->next;
     }
     fast = slow->next;
     slow->next = NULL;

     ListNode *l1 = sortList(head);
     ListNode *l2 = sortList(fast);

     return merge(l1,l2);
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *fakeHead = new ListNode(-1);
        ListNode *cur = fakeHead;

        while(l1&&l2)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(!l1&&l2) cur->next = l2;
        else if(l1&&!l2) cur->next = l1;

        return (*fakeHead).next;
    }
};
