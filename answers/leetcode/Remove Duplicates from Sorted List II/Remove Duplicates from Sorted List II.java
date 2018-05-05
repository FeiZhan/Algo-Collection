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
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        int count = 0;
        ListNode left = dummy;
        ListNode right = head;
        while (true) {
            if (right != null && left.next.val == right.val) {
                count++;
            } else if (count > 1) {
                count = 1;
                left.next = right;
            } else {
                count = 1;
                left = left.next;
            }
            if (right == null) {
                break;
            }
            right = right.next;
        }
        return dummy.next;
    }
}