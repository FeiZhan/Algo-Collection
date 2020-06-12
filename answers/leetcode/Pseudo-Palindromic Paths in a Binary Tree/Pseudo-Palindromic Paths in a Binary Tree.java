/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pseudoPalindromicPaths (TreeNode root) {
        return this.dfs(root, new HashSet<>());
    }

    private int dfs(TreeNode root, Set<Integer> numbers) {
        if (root == null) {
            return 0;
        }

        if (numbers.contains(root.val)) {
            numbers.remove(root.val);
        } else {
            numbers.add(root.val);
        }
        int count = 0;
        if (root.left == null && root.right == null) {
            count = numbers.size() <= 1 ? 1 : 0;
        } else {
            count = this.dfs(root.left, numbers) + this.dfs(root.right, numbers);
        }
        if (numbers.contains(root.val)) {
            numbers.remove(root.val);
        } else {
            numbers.add(root.val);
        }
        return count;
    }
}