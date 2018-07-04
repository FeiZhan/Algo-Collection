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
    public int kthSmallest(TreeNode root, int k) {
        if (root == null) {
            return -1;
        }
        int count = this.count(root.left);
        if (count + 1 < k) {
            return this.kthSmallest(root.right, k - count - 1);
        } else if (count >= k) {
            return this.kthSmallest(root.left, k);
        } else {
            return root.val;
        }
    }
    
    private int count(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return this.count(root.left) + this.count(root.right) + 1;
    }
}