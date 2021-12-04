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
    public void reorderList(ListNode head) {
        ListNode left = head;
        ListNode right = head;
        while (right != null && right.next != null && right.next.next != null) {
            left = left.next;
            right = right.next.next;
        }

        ListNode current = left.next;
        left.next = null;
        ListNode dummy = new ListNode(-1);

        while (current != null) {
            ListNode next = current.next;
            current.next = dummy.next;
            dummy.next = current;
            current = next;
        }

        left = head;
        right = dummy.next;
        while (right != null) {
            ListNode next0 = left.next;
            ListNode next1 = right.next;
            left.next = right;
            right.next = next0;
            left = next0;
            right = next1;
        }
    }
}
//Runtime: 1 ms, faster than 99.92% of Java online submissions for Reorder List.
//Memory Usage: 41.6 MB, less than 74.66% of Java online submissions for Reorder List.
