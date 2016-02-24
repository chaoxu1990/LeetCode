/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode fakedHead = new ListNode(-1);
        ListNode tmp = fakedHead, tmp1 = l1, tmp2 = l2;
        int carry = 0;
        
        while(tmp1 != null || tmp2 != null || carry != 0)
        {
            int sum = (tmp1 == null?0:tmp1.val) + (tmp2 == null?0:tmp2.val) + carry;
            carry = sum / 10;
            sum = sum %10;
            tmp.next = new ListNode(sum);
            tmp = tmp.next;
            tmp1 = tmp1 == null?null:tmp1.next;
            tmp2 = tmp2 == null?null:tmp2.next;
        }
        return fakedHead.next;
    }
}