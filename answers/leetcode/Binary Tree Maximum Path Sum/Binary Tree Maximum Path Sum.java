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
    
    private int maxSum;
    
    public int maxPathSum(TreeNode root) {
        this.maxSum = Integer.MIN_VALUE;
        this.maxChildSum(root);
        return this.maxSum;
    }
    
    private int maxChildSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = this.maxChildSum(root.left);
        int right = this.maxChildSum(root.right);
        this.maxSum = Math.max(this.maxSum, root.val);
        this.maxSum = Math.max(this.maxSum, root.val + left);
        this.maxSum = Math.max(this.maxSum, root.val + right);
        this.maxSum = Math.max(this.maxSum, root.val + left + right);
        int childSum = root.val;
        childSum = Math.max(childSum, root.val + left);
        childSum = Math.max(childSum, root.val + right);
        return childSum;
    }
}