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
    public ListNode removeNodes(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        head = this.revert(head);
        ListNode left = head;
        ListNode right = left.next;
        while (right != null) {
            if (left.val <= right.val) {
                left = right;
                right = right.next;
            } else {
                right = right.next;
                left.next = right;
            }
        }
        head = this.revert(head);

        return head;
    }

    private ListNode revert(ListNode head) {
        ListNode left = head;
        ListNode right = head.next;
        head.next = null;
        while (right != null) {
            ListNode temp = left;
            left = right;
            right = right.next;
            left.next = temp;
        }

        return left;
    }
}