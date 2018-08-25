/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode left = head;
        ListNode right = head;
        while (right != null && right.next != null && right.next.next != null) {
            left = left.next;
            right = right.next;
            if (right != null) {
                right = right.next;
            }
        }
        right = left.next;
        left.next = null;
        right = this.sortList(right);
        left = this.sortList(head);
        
        ListNode dummy = new ListNode(-1);
        ListNode current = dummy;
        while (left != null || right != null) {
            if (right == null || (left != null && right != null && left.val < right.val)) {
                current.next = left;
                left = left.next;
            } else {
                current.next = right;
                right = right.next;
            }
            current = current.next;
        }
        return dummy.next;
    }
}