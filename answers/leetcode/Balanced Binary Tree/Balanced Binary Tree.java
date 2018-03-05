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
    public boolean isBalanced(TreeNode root) {
        return this.checkHeight(root) >= 0;
    }

    private int checkHeight(TreeNode root) {
        if (null == root) {
            return 0;
        }
        int left = this.checkHeight(root.left);
        if (left < 0) {
            return -1;
        }
        int right = this.checkHeight(root.right);
        if (right < 0) {
            return -1;
        }
        if (Math.abs(left - right) > 1) {
            return -1;
        }
        return Math.max(left, right) + 1;
    }
}