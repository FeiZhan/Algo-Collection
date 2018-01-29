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
    private int longest;
    
    public int longestUnivaluePath(TreeNode root) {
        longest = 0;
        help(root, -1);
        return longest;
    }
    
    private int help(TreeNode root, int value) {
        if (root == null) {
            return 0;
        }
        int left = help(root.left, root.val);
        int right = help(root.right, root.val);
        if (left + right > longest) {
            longest = left + right;
        }
        if (value == root.val) {
            return Math.max(left, right) + 1;
        } else {
            return 0;
        }
    }
}