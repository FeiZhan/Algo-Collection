/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int length1 = this.getLength(l1);
        int length2 = this.getLength(l2);
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        while (length1 != length2) {
            if (length1 > length2) {
                length1--;
                current.next = l1;
                l1 = l1.next;
            } else {
                length2--;
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        current.next = this.dfs(l1, l2);
        this.calculateCarry(dummy);
        return dummy.val > 0 ? dummy : dummy.next;
    }

    private int getLength(ListNode root) {
        int length = 0;
        if (root != null) {
            length = this.getLength(root.next) + 1;
        }
        return length;
    }

    private ListNode dfs(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return null;
        }
        ListNode root = new ListNode(l1.val + l2.val);
        root.next = this.dfs(l1.next, l2.next);
        return root;
    }

    private int calculateCarry(ListNode root) {
        if (root == null) {
            return 0;
        }
        root.val += this.calculateCarry(root.next);
        int carry = root.val / 10;
        root.val %= 10;
        return carry;
    }
}