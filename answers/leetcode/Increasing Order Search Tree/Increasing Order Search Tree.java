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
    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode(-1);
        this.inorder(root, dummy);
        return dummy.right;
    }

    private TreeNode inorder(TreeNode root, TreeNode current) {
        if (root == null) {
            return current;
        }
        current = this.inorder(root.left, current);
        current.right = root;
        TreeNode right = root.right;
        root.left = null;
        root.right = null;
        return this.inorder(right, current.right);
    }
}