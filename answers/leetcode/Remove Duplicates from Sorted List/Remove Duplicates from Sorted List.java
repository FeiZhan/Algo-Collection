/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (null == head) {
            return head;
        }
        ListNode parent = head;
        ListNode current = head.next;
        while (current != null) {
            if (parent.val == current.val) {
                parent.next = current.next;
                current = current.next;
            } else {
                parent = parent.next;
                current = current.next;
            }
        }
        return head;
    }
}