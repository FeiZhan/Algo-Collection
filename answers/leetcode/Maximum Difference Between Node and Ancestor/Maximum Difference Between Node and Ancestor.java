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
    public int maxAncestorDiff(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(this.dfs(root.left, root.val, root.val),
            this.dfs(root.right, root.val, root.val));
    }

    private int dfs(TreeNode root, int min, int max) {
        if (root == null) {
            return 0;
        }
        int result = Math.abs(root.val - min);
        result = Math.max(result, Math.abs(root.val - max));
        min = Math.min(min, root.val);
        max = Math.max(max, root.val);
        result = Math.max(result, this.dfs(root.left, min, max));
        result = Math.max(result, this.dfs(root.right, min, max));
        return result;
    }
}