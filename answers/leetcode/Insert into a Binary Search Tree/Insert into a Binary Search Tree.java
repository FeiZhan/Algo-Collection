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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            root = new TreeNode(val);
        } else if (val > root.val) {
            root.right = this.insertIntoBST(root.right, val);
        } else {
            root.left = this.insertIntoBST(root.left, val);
        }
        return root;
    }
}