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
    public boolean findTarget(TreeNode root, int k) {
        return this.findTarget(root, root, k);
    }

    private boolean findTarget(TreeNode current, TreeNode root, int k) {
        if (current == null || root == null) {
            return false;
        }
        if (this.findNumber(root, k - current.val, current)) {
            return true;
        }
        return this.findTarget(current.left, root, k) || this.findTarget(current.right, root, k);
    }

    private boolean findNumber(TreeNode root, int number, TreeNode current) {
        if (root == null) {
            return false;
        }
        if (root.val == number && root != current) {
            return true;
        }
        return this.findNumber(root.left, number, current) || this.findNumber(root.right, number, current);
    }
}