/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode left = dummy;
        for (int i = 1; i < m && left != null; i++) {
            left = left.next;
        }
        ListNode previous = left.next;
        for (int i = m; i < n; i++) {
            ListNode target = previous.next;
            previous.next = target.next;
            target.next = left.next;
            left.next = target;
        }
        return dummy.next;
    }
}