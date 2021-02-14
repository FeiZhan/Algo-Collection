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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode dummy = new ListNode(-1, list1);
        ListNode current = dummy;
        for (int i = 0; i < b + 2; i++) {
            if (current != null) {
                current = current.next;
            }
        }
        ListNode tail2 = list2;
        while (tail2 != null && tail2.next != null) {
            tail2 = tail2.next;
        }
        if (tail2 != null) {
            tail2.next = current;
        }

        current = dummy;
        for (int i = 0; i < a; i++) {
            if (current != null) {
                current = current.next;
            }
        }
        if (current != null) {
            current.next = list2;
        }

        return dummy.next;
    }
}