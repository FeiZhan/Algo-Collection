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

    private int index;

    public boolean isCompleteTree(TreeNode root) {
        int depth = this.getDepth(root);
        this.index = Integer.MAX_VALUE;
        return this.isCompleteTree(root, depth, 0);
    }

    private int getDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(this.getDepth(root.left), this.getDepth(root.right)) + 1;
    }

    private boolean isCompleteTree(TreeNode root, int depth, int index) {
        if (root == null) {
            if (depth > 1) {
                return false;
            } else if (depth == 1) {
                this.index = Math.min(this.index, index);
                return true;
            } else {
                return true;
            }
        } else {
            if (depth > 1) {
                return this.isCompleteTree(root.left, depth - 1, index * 2)
                    && this.isCompleteTree(root.right, depth - 1, index * 2 + 1);
            } else if (depth == 1) {
                return this.index > index || this.index == Integer.MAX_VALUE;
            } else {
                return false;
            }
        }
    }
}