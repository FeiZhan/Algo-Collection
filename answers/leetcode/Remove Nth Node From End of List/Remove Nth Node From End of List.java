/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode right = dummy;
        for (int i = 0; i <= n && right != null; i++) {
            right = right.next;
        }
        ListNode left = dummy;
        while (right != null) {
            left = left.next;
            right = right.next;
        }
        if (left != null && left.next != null) {
            left.next = left.next.next;
        }
        return dummy.next;
    }
}