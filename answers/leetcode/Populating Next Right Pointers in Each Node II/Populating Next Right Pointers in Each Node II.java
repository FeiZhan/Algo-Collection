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
        TreeLinkNode firstChild = root;
        while (firstChild != null) {
            TreeLinkNode current = firstChild;
            firstChild = null;
            while (current != null) {
                if (firstChild == null) {
                    firstChild = current.left != null ? current.left : current.right;
                }
                if (current.left != null && current.right != null) {
                    current.left.next = current.right;
                }
                TreeLinkNode child = current.right != null ? current.right : current.left;
                if (child != null) {
                    TreeLinkNode next = current.next;
                    while (next != null) {
                        if (next.left != null) {
                            child.next = next.left;
                            break;
                        } else if (next.right != null) {
                            child.next = next.right;
                            break;
                        }
                        next = next.next;
                    }
                }
                current = current.next;
            }
        }
    }
}