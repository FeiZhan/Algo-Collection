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
    private int tilt = 0;

    public int findTilt(TreeNode root) {
        this.getSum(root);
        return this.tilt;
    }

    private int getSum(TreeNode root) {
        if (null == root) {
            return 0;
        }
        int left = this.getSum(root.left);
        int right = this.getSum(root.right);
        this.tilt += Math.abs(left - right);
        return root.val + left + right;
    }
}