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
    private int diameter;
    
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        getDepth(root);
        return diameter;
    }
    
    private int getDepth(TreeNode root) {
        if (null == root) {
            return 0;
        }
        int left = getDepth(root.left);
        int right = getDepth(root.right);
        if (left + right > diameter) {
            diameter = left + right;
        }
        return Math.max(left, right) + 1;
    }
}