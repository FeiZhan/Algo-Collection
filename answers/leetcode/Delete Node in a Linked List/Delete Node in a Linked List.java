/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        if (null == node) {
            return;
        } else if (null == node.next) {
            node = null;
        } else {
            node.val = node.next.val;
            node.next = node.next.next;
        }
    }
}