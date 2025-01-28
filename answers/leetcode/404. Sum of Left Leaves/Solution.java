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
    public int sumOfLeftLeaves(TreeNode root) {
        return root != null ? ((root.left != null && root.left.left == null && root.left.right == null ? root.left.val : 0) + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right)) : 0;
    }
}