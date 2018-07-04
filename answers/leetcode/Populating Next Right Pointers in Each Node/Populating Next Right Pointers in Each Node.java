/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null) {
            return;
        }
        
        if (root.left != null && root.right != null) {
            root.left.next = root.right;
        }
        TreeLinkNode child = root.right != null ? root.right : root.left;
        if (child != null) {
            TreeLinkNode next = root.next;
            while (next != null && next.left == null && next.right == null) {
                next = next.next;
            }
            TreeLinkNode nextChild = null;
            if (next != null) {
                nextChild = next.left != null ? next.left : next.right;
                child.next = nextChild;
            }
        }
        this.connect(root.left);
        this.connect(root.right);
    }
}