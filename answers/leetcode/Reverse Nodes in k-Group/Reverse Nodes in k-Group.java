/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode current = head;
        for (int i = 1; i < k && current != null; i++) {
            current = current.next;
        }
        if (current != null) {
            current = head;
            for (int i = 1; i < k; i++) {
                dummy.next = head.next;
                head.next = head.next.next;
                dummy.next.next = current;
                current = dummy.next;
            }
            head.next = this.reverseKGroup(head.next, k);
        }
        return dummy.next;
    }
}