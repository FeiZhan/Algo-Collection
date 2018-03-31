/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode current = dummy;
        while (current != null && current.next != null && current.next.next != null) {
            ListNode temp = current.next;
            current.next = current.next.next;
            temp.next = temp.next.next;
            current.next.next = temp;
            current = current.next.next;
        }
        return dummy.next;
    }
}