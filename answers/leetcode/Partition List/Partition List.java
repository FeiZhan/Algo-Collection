/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode lessHead = new ListNode(-2);
        ListNode less = lessHead;
        ListNode greaterHead = new ListNode(-3);
        ListNode greater = greaterHead;
        ListNode current = dummy;
        while (current.next != null) {
            if (current.next.val < x) {
                less.next = current.next;
                less = less.next;
            } else {
                greater.next = current.next;
                greater = greater.next;
            }
            current = current.next;
        }
        less.next = greaterHead.next;
        greater.next = null;
        return lessHead.next;
    }
}