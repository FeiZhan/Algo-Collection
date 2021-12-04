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
    public ListNode removeZeroSumSublists(ListNode head) {
        int sum = 0;
        ListNode dummy = new ListNode(-100000, head);
        ListNode current = dummy;
        Map<Integer, ListNode> sumMap = new HashMap<>();

        while (current != null) {
            sum += current.val;
            if (sumMap.containsKey(sum)) {
                ListNode previous = sumMap.get(sum);
                int tempSum = sum;
                ListNode temp = previous.next;
                while (temp != current) {
                    tempSum += temp.val;
                    sumMap.remove(tempSum);
                    temp = temp.next;
                }
                previous.next = current.next;
            } else {
                sumMap.put(sum, current);
            }
            current = current.next;
        }

        return dummy.next;
    }
}
//Runtime: 2 ms, faster than 76.24% of Java online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
//Memory Usage: 38.8 MB, less than 65.44% of Java online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
