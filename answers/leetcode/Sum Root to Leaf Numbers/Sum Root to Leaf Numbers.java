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
    public int sumNumbers(TreeNode root) {
        return this.dfs(root, 0);
    }

    private int dfs(TreeNode root, int num) {
        if (null == root) {
            return 0;
        } else if (null == root.left && null == root.right) {
            return num * 10 + root.val;
        } else {
            return this.dfs(root.left, num * 10 + root.val) + this.dfs(root.right, num * 10 + root.val);
        }
    }
}