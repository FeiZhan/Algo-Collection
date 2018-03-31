/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = new ListNode(-1);
        ListNode current = head;
        while (l1 != null || l2 != null) {
            current.next = new ListNode(-1);
            current = current.next;
            current.val = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
            carry = current.val / 10;
            current.val %= 10;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        while (carry > 0) {
            current.next = new ListNode(-1);
            current = current.next;
            current.val = carry % 10;
            carry /= 10;
        }
        return head.next;
    }
}