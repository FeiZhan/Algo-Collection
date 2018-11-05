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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return this.constructMaximumBinaryTree(0, nums.length - 1, nums);
    }

    private TreeNode constructMaximumBinaryTree(int left, int right, int[] nums) {
        if (left > right) {
            return null;
        }

        int index = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[index]) {
                index = i;
            }
        }
        TreeNode root = new TreeNode(nums[index]);
        root.left = this.constructMaximumBinaryTree(left, index - 1, nums);
        root.right = this.constructMaximumBinaryTree(index + 1, right, nums);
        return root;
    }
}