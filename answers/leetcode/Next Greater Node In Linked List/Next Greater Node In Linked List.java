/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        ListNode current = head;
        Map<ListNode, Integer> largerMap = new HashMap<>();
        Stack<ListNode> stack = new Stack<>();
        while (current != null) {
            while (!stack.isEmpty()) {
                ListNode top = stack.peek();
                if (top.val < current.val) {
                    largerMap.put(top, current.val);
                    //System.out.println(top.val + " -> " + current.val);
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(current);
            current = current.next;
        }
        current = head;
        int i = 0;
        int[] results = new int[largerMap.size() + stack.size()];
        while (current != null) {
            results[i] = largerMap.getOrDefault(current, 0);
            i++;
            current = current.next;
        }
        return results;
    }
}