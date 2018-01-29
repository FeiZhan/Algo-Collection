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
    public TreeNode convertBST(TreeNode root) {
        convertBST(root, 0);
        return root;
    }
    public int convertBST(TreeNode root, int val) {
        if (root == null) {
            return val;
        }
        int right = convertBST(root.right, val);
        root.val += (root.right != null ? right : val);
        int left = convertBST(root.left, root.val);
        return left;
    }
}