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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return null;
        }

        int length = 1;
        ListNode rear = head;
        while (rear.next != null) {
            length++;
            rear = rear.next;
        }
        k %= length;

        ListNode right = head;
        for (int i = 0; i < k; i++) {
            right = right.next;
        }

        ListNode left = head;
        while (right.next != null) {
            left = left.next;
            right = right.next;
        }

        rear.next = head;
        ListNode newHead = left.next;
        left.next = null;

        return newHead;
    }
}
//Runtime: 0 ms, faster than 100.00% of Java online submissions for Rotate List.
//Memory Usage: 38.1 MB, less than 96.91% of Java online submissions for Rotate List.
