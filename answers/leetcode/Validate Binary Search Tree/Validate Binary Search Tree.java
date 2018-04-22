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
    public boolean isValidBST(TreeNode root) {
        return this.isValidBST(root, null, null);
    }

    private boolean isValidBST(TreeNode root, Integer minValue, Integer maxValue) {
        if (null == root) {
            return true;
        } else if ((maxValue != null && root.val >= maxValue) || (minValue != null && root.val <= minValue)) {
            return false;
        } else {
            int newMax = (maxValue != null && maxValue < root.val) ? maxValue : root.val;
            int newMin = (minValue != null && minValue > root.val) ? minValue : root.val;
            return this.isValidBST(root.left, minValue, newMax)
                && this.isValidBST(root.right, newMin, maxValue);
        }
    }
}