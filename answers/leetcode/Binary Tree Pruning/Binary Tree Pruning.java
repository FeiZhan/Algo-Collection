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
    public TreeNode pruneTree(TreeNode root) {
        if (root != null) {
            root.left = this.pruneTree(root.left);
            root.right = this.pruneTree(root.right);
            if (root.val != 1 && root.left == null && root.right == null) {
                root = null;
            }
        }
        return root;
    }
}