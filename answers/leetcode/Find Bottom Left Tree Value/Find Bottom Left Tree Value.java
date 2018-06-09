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
    public int findBottomLeftValue(TreeNode root) {
        int[] values = new int[2];
        this.dfs(root, 0, values);
        return values[1];
    }
    
    private void dfs(TreeNode root, int level, int[] values) {
        if (null == root) {
            return;
        }
        this.dfs(root.right, level + 1, values);
        this.dfs(root.left, level + 1, values);
        if (level >= values[0]) {
            values[0] = level;
            values[1] = root.val;
        }
    }
}