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

    private int previous = Integer.MAX_VALUE;

    public int getMinimumDifference(TreeNode root) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }
        int min = this.getMinimumDifference(root.left);
        if (previous != Integer.MAX_VALUE) {
            min = Math.min(min, root.val - previous);
        }
        this.previous = root.val;
        min = Math.min(min, this.getMinimumDifference(root.right));
        return min;
    }
}