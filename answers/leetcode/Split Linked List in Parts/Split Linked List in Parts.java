/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        int size = 0;
        ListNode old = root;
        while (old != null) {
            size++;
            old = old.next;
        }
        int splitSize = size / k;
        int remainder = size % k;
        ListNode[] nodes = new ListNode[k];
        ListNode dummy = new ListNode(-1);
        old = root;
        for (int i = 0; i < k; i++) {
            ListNode current = dummy;
            for (int j = 0; j < splitSize + (i < remainder ? 1 : 0); j++) {
                current.next = old;
                current = current.next;
                old = old.next;
            }
            current.next = null;
            nodes[i] = dummy.next;
            dummy.next = null;
        }
        return nodes;
    }
}