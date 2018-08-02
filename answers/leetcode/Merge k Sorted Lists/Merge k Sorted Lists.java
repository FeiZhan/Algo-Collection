/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        PriorityQueue<ListNode> queue = new PriorityQueue<>(lists.length, (a, b) -> a.val - b.val);
        for (ListNode list : lists) {
            if (list != null) {
                queue.add(list);
            }
        }
        ListNode head = new ListNode(-1);
        ListNode current = head;
        while (!queue.isEmpty()) {
            ListNode next = queue.remove();
            if (next.next != null) {
                queue.add(next.next);
            }
            current.next = next;
            current = current.next;
        }
        return head.next;
    }
}