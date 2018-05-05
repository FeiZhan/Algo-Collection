/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode tail = dummy;
        int length = 0;
        while (tail != null && tail.next != null) {
            length++;
            tail = tail.next;
        }
        if (length == 0) {
            return head;
        }
        tail.next = head;
        k %= length;

        for (int i = 0; i < length - k; i++) {
            dummy = dummy.next;
        }
        head = dummy.next;
        dummy.next = null;
        return head;
    }
}