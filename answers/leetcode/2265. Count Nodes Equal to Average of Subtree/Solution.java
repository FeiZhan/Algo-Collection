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
    public int averageOfSubtree(TreeNode root) {
        List<Integer> result = dfs(root);
        return result.get(2);
    }

    private List<Integer> dfs(TreeNode current) {
        List<Integer> result = new ArrayList<>();
        result.add(0);
        result.add(0);
        result.add(0);
        if (current != null) {
            List<Integer> leftResult = dfs(current.left);
            List<Integer> rightResult = dfs(current.right);
            result.set(0, leftResult.get(0) + rightResult.get(0) + 1);
            result.set(1, leftResult.get(1) + rightResult.get(1) + current.val);
            result.set(2, leftResult.get(2) + rightResult.get(2) + (result.get(1) / result.get(0) == current.val ? 1 : 0));
        }

        return result;
    }
}