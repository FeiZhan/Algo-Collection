/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode left = head;
        ListNode right = head;
        while (right != null && right.next != null) {
            left = left.next;
            right = right.next.next;
        }
        ListNode reversed = new ListNode(-1);
        while (left.next != null) {
            ListNode temp = reversed.next;
            reversed.next = left.next;
            left.next = left.next.next;
            reversed.next.next = temp;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        left = dummy.next;
        right = reversed.next;
        ListNode current = dummy;
        while (left != null || right != null) {
            if (left != null) {
                current.next = left;
                current = current.next;
                left = left.next;
            }
            if (right != null) {
                current.next = right;
                current = current.next;
                right = right.next;
            }
        }
        head = dummy.next;
    }
}