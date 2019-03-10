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
    public boolean isCousins(TreeNode root, int x, int y) {
        int depth0 = this.getDepth(root, x);
        int depth1 = this.getDepth(root, y);
        if (depth0 != depth1) {
            return false;
        }
        TreeNode parent0 = this.getParent(root, x);
        TreeNode parent1 = this.getParent(root, y);
        return parent0 != parent1;
    }

    private int getDepth(TreeNode root, int value) {
        int depth = Integer.MAX_VALUE;
        if (root == null) {
            return depth;
        } else if (root.val == value) {
            return 0;
        }
        depth = this.getDepth(root.left, value);
        if (depth != Integer.MAX_VALUE) {
            return depth + 1;
        }
        depth = this.getDepth(root.right, value);
        return depth != Integer.MAX_VALUE ? depth + 1 : Integer.MAX_VALUE;
    }

    private TreeNode getParent(TreeNode root, int value) {
        if (root == null || root.val == value) {
            return null;
        } else if ((root.left != null && root.left.val == value) || (root.right != null && root.right.val == value)) {
            return root;
        }
        TreeNode parent = this.getParent(root.left, value);
        if (parent != null) {
            return parent;
        }
        return this.getParent(root.right, value);
    }
}