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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        TreeNode current = new TreeNode(val);
        if (root == null) {
            root = current;
        } else if (val > root.val) {
            current.left = root;
            root = current;
        } else if (root.right == null || val > root.right.val) {
            current.left = root.right;
            root.right = current;
        } else {
            root.right = this.insertIntoMaxTree(root.right, val);
        }
        return root;
    }
}