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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode dummy = new ListNode(-1, head);
        ListNode swap0 = dummy;
        for (int i = 0; i + 1 < k; i++) {
            if (swap0 != null) {
                swap0 = swap0.next;
            }
        }

        ListNode tail = dummy;
        for (int i = 0; i <= k; i++) {
            if (tail != null) {
                tail = tail.next;
            }
        }
        ListNode swap1 = dummy;
        while (tail != null) {
            tail = tail.next;
            swap1 = swap1.next;
        }

        if (swap0 != null & swap1 != null) {
            ListNode temp = swap0.next;
            swap0.next = swap1.next;
            swap1.next = temp;
            if (swap0.next != null && swap1.next != null) {
                temp = swap0.next.next;
                swap0.next.next = swap1.next.next;
                swap1.next.next = temp;
            }
        }

        return dummy.next;
    }
}