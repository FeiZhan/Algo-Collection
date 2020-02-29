/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        int result = 0;
        ListNode current = head;
        while (current != null) {
            result = result * 2 + current.val;
            current = current.next;
        }
        return result;
    }
}