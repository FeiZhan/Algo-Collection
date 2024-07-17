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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] result = new int[]{Integer.MAX_VALUE, -1};
        if (head != null && head.next != null) {
            int index = 0;
            int first = -1;
            int previousIndex = -1;
            ListNode previous = head;
            while (previous.next.next != null) {
                int previousValue = previous.val;
                int currentValue = previous.next.val;
                int nextValue = previous.next.next.val;
                if ((previousValue < currentValue && currentValue > nextValue) || (previousValue > currentValue && currentValue < nextValue)) {
                    if (first < 0) {
                        first = index;
                    } else {
                        result[1] = Math.max(result[1], index - first);
                    }
                    if (previousIndex >= 0) {
                        result[0] = Math.min(result[0], index - previousIndex);
                    }
                    previousIndex = index;
                }
                index++;
                previous = previous.next;
            }
        }

        if (result[1] == -1) {
            result[0] = -1;
        }
        return result;
    }
}