/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int diff = 0;
        ListNode currentA = headA;
        while (currentA != null) {
            diff++;
            currentA = currentA.next;
        }
        ListNode currentB = headB;
        while (currentB != null) {
            diff--;
            currentB = currentB.next;
        }
        currentA = headA;
        currentB = headB;
        while (diff > 0) {
            currentA = currentA.next;
            diff--;
        }
        while (diff < 0) {
            currentB = currentB.next;
            diff++;
        }
        while (currentA != currentB) {
            currentA = currentA.next;
            currentB = currentB.next;
        }
        return currentA;
    }
}