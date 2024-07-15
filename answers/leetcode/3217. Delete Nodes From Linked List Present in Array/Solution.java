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
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> numbers = new HashSet<>();
        for (int number : nums) {
            numbers.add(number);
        }
        ListNode dummy = new ListNode(-1, head);
        ListNode current = dummy;

        while (current.next != null) {
            ListNode next = current.next;
            if (numbers.contains(next.val)) {
                current.next = next.next;
            } else {
                current = next;
            }
        }

        return dummy.next;
    }
}