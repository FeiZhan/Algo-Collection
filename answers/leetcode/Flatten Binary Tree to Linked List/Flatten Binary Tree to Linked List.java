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
    public void flatten(TreeNode root) {
        this.flattenAndGetTail(root);
    }

    private TreeNode flattenAndGetTail(TreeNode root) {
        if (null == root) {
            return null;
        }
        TreeNode leftHead = root.left;
        TreeNode leftTail = this.flattenAndGetTail(leftHead);
        TreeNode rightHead = root.right;
        TreeNode rightTail = this.flattenAndGetTail(rightHead);
        root.left = null;
        if (leftHead != null) {
            root.right = leftHead;
            leftTail.right = rightHead;
        } else {
            root.right = rightHead;
        }
        return rightTail != null ? rightTail : (leftTail != null ? leftTail : root);
    }
}