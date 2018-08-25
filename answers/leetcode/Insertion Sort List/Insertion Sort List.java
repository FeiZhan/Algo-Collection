/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode sorted = new ListNode(-1);
        while (dummy.next != null) {
            ListNode current = dummy.next;
            dummy.next = dummy.next.next;
            ListNode target = sorted;
            while (target.next != null && current.val > target.next.val) {
                target = target.next;
            }
            current.next = target.next;
            target.next = current;
        }
        return sorted.next;
    }
}