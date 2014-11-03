/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode *fakedHead = new RandomListNode(-1);
        RandomListNode* cur = head;

        while(cur)
        {
            RandomListNode* tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        cur = head;

        while(cur)
        {
            if(cur->random != NULL)
            cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        fakedHead->next = cur->next;
        while(cur)
        {
            RandomListNode* tmp = cur->next;
            cur->next = tmp->next;
            cur = cur->next;
            if(cur)
                tmp->next = cur->next;
        }
        return fakedHead->next;
    }
};
