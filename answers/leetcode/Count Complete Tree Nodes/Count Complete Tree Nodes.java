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
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftHeight = this.getHeight(root.left);
        int rightHeight = this.getHeight(root.right);
        int count = 1;
        if (leftHeight == rightHeight) {
            count += this.countNodes(root.right);
            for (int i = 0; i < leftHeight; i++) {
                count += 1 << i;
            }
        } else {
            count += this.countNodes(root.left);
            for (int i = 0; i < rightHeight; i++) {
                count += 1 << i;
            }
        }
        //System.out.println(root.val + ": " + leftHeight + " " + rightHeight + " " + count);
        return count;
    }
    
    private int getHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + this.getHeight(root.left);
    }
}