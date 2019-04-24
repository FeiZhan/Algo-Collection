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
    public int sumRootToLeaf(TreeNode root) {
        return this.sumRootToLeaf(root, 0);
    }

    private int sumRootToLeaf(TreeNode root, int parentValue) {
        if (root == null) {
            return 0;
        }
        int value = parentValue * 2 + root.val;
        int result = 0;
        if (root.left == null && root.right == null) {
            result = value;
        } else {
            if (root.left != null) {
                result += this.sumRootToLeaf(root.left, value);
            }
            if (root.right != null) {
                result += this.sumRootToLeaf(root.right, value);
            }
        }
        return result;
    }
}