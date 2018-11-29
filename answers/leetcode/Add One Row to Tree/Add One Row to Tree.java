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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode newRoot = new TreeNode(v);
            newRoot.left = root;
            root = newRoot;
        } else if (d == 2 && root != null) {
            TreeNode left = root.left;
            TreeNode right = root.right;
            root.left = new TreeNode(v);
            root.left.left = left;
            root.right = new TreeNode(v);
            root.right.right = right;
        } else if (d > 2 && root != null) {
            root.left = this.addOneRow(root.left, v, d - 1);
            root.right = this.addOneRow(root.right, v, d - 1);
        }
        return root;
    }
}