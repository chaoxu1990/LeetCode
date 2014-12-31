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



//Solution No.2 Using MinHeap

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
    struct cmp{
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val>b->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *> tmp;
        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode *idx = lists[i];
            while(idx != NULL)
            {
                tmp.push_back(idx);
                idx = idx -> next;
            }
        }
        
        make_heap(tmp.begin(), tmp.end(), cmp());
        
        ListNode *fakedHead = new ListNode(-1);
        ListNode *runner = fakedHead;
        while(tmp.empty() == false)
        {
            runner -> next = tmp.front();
            runner = runner -> next;
            pop_heap(tmp.begin(), tmp.end(), cmp());
            tmp.pop_back();
        }
        runner->next = NULL;        
        return fakedHead->next;
    }
};