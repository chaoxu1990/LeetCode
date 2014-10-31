/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next) return head;
        ListNode *fakedHead = new ListNode(-1);
        fakedHead->next = head;
        ListNode *prev = fakedHead, *cur = head, *tmp_head;
        while(cur && cur->val < x)
        {
            prev = cur;
            cur = cur->next;
        }
        tmp_head = prev;

        //if(!cur) return head;
        while(cur)
        {
            if(cur->val < x)
            {
                ListNode *tmp = cur;
                prev->next = cur->next;
                cur = cur->next;
                tmp->next = tmp_head->next;
                tmp_head->next = tmp;
                tmp_head = tmp;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return fakedHead->next;
    }
};



//Solution No.2 from LeetCode.pdf

// LeetCode, Partition List
// 时间复杂度 O(n),空间复杂度 O(1)
class Solution {
public:
ListNode* partition(ListNode* head, int x) { ListNode left_dummy(-1); // 头结点 ListNode right_dummy(-1); // 头结点
          auto left_cur = &left_dummy;
          auto right_cur = &right_dummy;
          for (ListNode *cur = head; cur; cur = cur->next) {
              if (cur->val < x) {
                  left_cur->next = cur;
                  left_cur = cur;
              } else {
                  right_cur->next = cur;
                  right_cur = cur;
              }
}
          left_cur->next = right_dummy.next;
          right_cur->next = nullptr;
          return left_dummy.next;
      }
};
