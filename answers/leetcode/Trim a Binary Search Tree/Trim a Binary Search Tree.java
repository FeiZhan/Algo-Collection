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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (null == root) {
            return null;
        }
        if (root.val >= L && root.val <= R) {
            root.left = this.trimBST(root.left, L, R);
            root.right = this.trimBST(root.right, L, R);
        } else if (root.val < L) {
            root = this.trimBST(root.right, L, R);
        } else {
            root = this.trimBST(root.left, L, R);
        }
        return root;
    }
}