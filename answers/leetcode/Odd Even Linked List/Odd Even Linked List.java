/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = head;
        ListNode dummy = new ListNode(-1);
        ListNode even = dummy;
        while (odd != null && odd.next != null) {
            even.next = odd.next;
            odd.next = odd.next.next;
            even = even.next;
            even.next = null;
            if (odd.next != null) {
                odd = odd.next;
            }
        }
        if (odd != null) {
            odd.next = dummy.next;
        }
        return head;
    }
}