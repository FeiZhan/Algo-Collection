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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        int pDiff = p.val - root.val;
        int qDiff = q.val - root.val;
        if (pDiff * qDiff <= 0) {
            return root;
        } else if (pDiff > 0 && qDiff > 0) {
            return this.lowestCommonAncestor(root.right, p, q);
        } else {
            return this.lowestCommonAncestor(root.left, p, q);
        }
    }
}