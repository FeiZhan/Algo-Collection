/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        return this.sortedListToBST(head, null);
    }
    
    private TreeNode sortedListToBST(ListNode head, ListNode tail) {
        if (head == tail) {
            return null;
        }
        
        ListNode left = head;
        ListNode right = head;
        while (right != tail && right.next != tail) {
            left = left.next;
            right = right.next.next;
        }
        TreeNode root = new TreeNode(left.val);
        root.left = this.sortedListToBST(head, left);
        root.right = this.sortedListToBST(left.next, tail);
        return root;
    }
}