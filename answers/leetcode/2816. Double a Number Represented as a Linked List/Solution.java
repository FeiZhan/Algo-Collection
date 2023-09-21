/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode doubleIt(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode current = dummy;

        while (current != null) {
            current.val = current.val * 2 % 10;
            if (current.next != null && current.next.val >= 5) {
                current.val += 1;
            }
            current = current.next;
        }

        return dummy.val > 0 ? dummy : dummy.next;
    }
}