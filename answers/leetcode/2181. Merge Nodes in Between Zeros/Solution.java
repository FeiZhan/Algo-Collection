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
    public ListNode mergeNodes(ListNode head) {
        int sum = 0;
        ListNode current = head.next;
        ListNode dummy = new ListNode(-1);
        ListNode currentResult = dummy;
        while (current != null) {
            if (current.val == 0) {
                ListNode next = new ListNode(sum);
                currentResult.next = next;
                currentResult = next;
                sum = 0;
            } else {
                sum += current.val;
            }
            current = current.next;
        }

        return dummy.next;
    }
}