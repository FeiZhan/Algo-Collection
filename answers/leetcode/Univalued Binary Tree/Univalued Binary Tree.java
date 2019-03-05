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
    public boolean isUnivalTree(TreeNode root) {
        return root == null || this.isUnivalTree(root, root.val);
    }

    private boolean isUnivalTree(TreeNode root, int value) {
        return root == null || (root.val == value && this.isUnivalTree(root.left, value) && this.isUnivalTree(root.right, value));
    }
}