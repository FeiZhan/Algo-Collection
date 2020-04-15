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
    public int deepestLeavesSum(TreeNode root) {
        int maxLevel = this.findMaxLevel(root);
        return this.dfs(root, 1, maxLevel);
    }

    private int findMaxLevel(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(this.findMaxLevel(root.left), this.findMaxLevel(root.right)) + 1;
    }

    private int dfs(TreeNode root, int level, final int maxLevel) {
        if (root == null) {
            return 0;
        }
        if (level == maxLevel) {
            return root.val;
        }
        return this.dfs(root.left, level + 1, maxLevel) + this.dfs(root.right, level + 1, maxLevel);
    }
}