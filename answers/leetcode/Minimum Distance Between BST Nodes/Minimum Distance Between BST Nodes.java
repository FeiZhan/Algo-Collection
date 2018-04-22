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

    public int minDiffInBST(TreeNode root) {
        if (null == root) {
            return Integer.MAX_VALUE;
        }
        int min = this.minDiffInBST(root.left);
        if (this.previous != Integer.MAX_VALUE) {
            min = Math.min(min, root.val - this.previous);
        }
        this.previous = root.val;
        min = Math.min(min, this.minDiffInBST(root.right));
        return min;
    }
}