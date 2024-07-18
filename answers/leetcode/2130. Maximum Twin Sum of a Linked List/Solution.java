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
    public int pairSum(ListNode head) {
        ListNode dummy0 = new ListNode(-1, head);
        ListNode left = dummy0;
        ListNode right = dummy0;
        while (right != null && right.next != null) {
            left = left.next;
            right = right.next.next;
        }

        ListNode dummy1 = new ListNode(-1, left.next);
        left.next = null;
        right = dummy1.next;
        dummy1.next = null;
        while (right != null) {
            ListNode temp = right.next;
            right.next = dummy1.next;
            dummy1.next = right;
            right = temp;
        }

        left = dummy0;
        right = dummy1;
        int result = 0;
        while (left != null && right != null) {
            result = Math.max(result, left.val + right.val);
            left = left.next;
            right = right.next;
        }

        return result;
    }
}