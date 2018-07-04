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
    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int[] rob2 = this.rob2(root);
        return Math.max(rob2[0], rob2[1]);
    }
    
    private int[] rob2(TreeNode root) {
        int[] values = new int[2];
        if (root == null) {
            return values;
        }
        int[] left = this.rob2(root.left);
        int[] right = this.rob2(root.right);
        values[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        values[1] = root.val + left[0] + right[0];
        return values;
    }
}