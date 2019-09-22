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
    private TreeNode result = null;

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        Map<TreeNode, Integer> depths = new HashMap<>();
        int maxDepth = this.getDepths(0, root, depths);
        this.result = null;
        this.dfs(root, depths, maxDepth);
        return this.result;
    }

    private int getDepths(int depth, TreeNode root, Map<TreeNode, Integer> depths) {
        if (root == null || depths.containsKey(root)) {
            return -1;
        }
        depths.put(root, depth);
        int left = this.getDepths(depth + 1, root.left, depths);
        int right = this.getDepths(depth + 1, root.right, depths);
        return Math.max(depth, Math.max(left, right));
    }

    private int dfs(TreeNode root, Map<TreeNode, Integer> depths, int maxDepth) {
        if (root == null) {
            return -1;
        }
        int left = this.dfs(root.left, depths, maxDepth);
        int right = this.dfs(root.right, depths, maxDepth);
        if ((left == maxDepth && right == maxDepth) || depths.get(root) == maxDepth) {
            this.result = root;
        }
        return Math.max(depths.get(root), Math.max(left, right));
    }
}