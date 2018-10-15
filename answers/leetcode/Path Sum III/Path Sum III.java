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
    public int pathSum(TreeNode root, int sum) {
        return this.dfs(root, sum, true) + this.dfs(root, sum, false);
    }

    private int dfs(TreeNode root, int sum, boolean continuous) {
        int count = 0;
        if (root != null) {
            if (continuous) {
                count += root.val == sum ? 1 : 0;
                count += this.dfs(root.left, sum - root.val, true);
                count += this.dfs(root.right, sum - root.val, true);
            } else {
                count += this.pathSum(root.left, sum);
                count += this.pathSum(root.right, sum);
            }
        }
        return count;
    }
}