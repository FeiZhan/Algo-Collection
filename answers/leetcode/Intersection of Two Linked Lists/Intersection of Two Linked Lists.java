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
        ListNode tailA = reverse(headA);
        ListNode tailB = reverse(headB);
        headA = tailA;
        headB = tailB;
        while (headA != null && headB != null && headA.val == headB.val) {
            headA = headA.next;
            headB = headB.next;
        }
        ListNode intersection = headA;
        reverse(tailA);
        reverse(tailB);
        return headA != null ? headA.next : null;
    }

    public ListNode reverse(ListNode head) {
        if (null == head) {
            return null;
        }
        ListNode
    }
}