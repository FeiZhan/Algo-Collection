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
    public TreeNode bstToGst(TreeNode root) {
        this.dfs(root, 0);
        return root;
    }
    
    private int dfs(TreeNode root, int value) {
        if (root == null) {
            return value;
        }
        value = this.dfs(root.right, value);
        root.val += value;
        return this.dfs(root.left, root.val);
    }
}