/*

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return NULL;

        ListNode*p;
        while(lists.size() > 1)
        {
            ListNode *p1 = lists.back();
            lists.pop_back();
            ListNode *p2 = lists.back();
            lists.pop_back();

            p = mergeTwoLists(p1,p2);
            lists.insert(lists.begin(), p);
        }

        return lists[0];
    }


    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *cur = new ListNode(-1);
        ListNode *head = cur;

        while(l1||l2)
        {
            int val1 = l1 == nullptr?INT_MAX:l1->val;
            int val2 = l2 == nullptr?INT_MAX:l2->val;
            if(val1 < val2)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return head->next;
    }
};
