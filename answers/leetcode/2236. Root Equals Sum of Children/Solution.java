/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean checkTree(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return true;
        }

        int sum = 0;
        if (root.left != null) {
            sum += root.left.val;
        }
        if (root.right != null) {
            sum += root.right.val;
        }

        return root.val == sum
            && this.checkTree(root.left)
            && this.checkTree(root.right);
    }
}
//Runtime: 1 ms, faster than 100.00% of Java online submissions for Root Equals Sum of Children.
//Memory Usage: 42.6 MB, less than 100.00% of Java online submissions for Root Equals Sum of Children.
