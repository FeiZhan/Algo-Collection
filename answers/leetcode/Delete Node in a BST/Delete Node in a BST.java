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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root != null) {
            if (root.val == key) {
                root = this.combine(root.left, root.right);
            } else if (key < root.val) {
                root.left = this.deleteNode(root.left, key);
            } else {
                root.right = this.deleteNode(root.right, key);
            }
        }
        return root;
    }
    
    private TreeNode combine(TreeNode left, TreeNode right) {
        if (null == left) {
            return right;
        } else if (null == right) {
            return left;
        } else {
            left.right = this.combine(left.right, right);
            return left;
        }
    }
}