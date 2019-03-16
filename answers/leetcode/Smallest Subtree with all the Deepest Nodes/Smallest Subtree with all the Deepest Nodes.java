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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        Map<TreeNode, Integer> depthMap = new HashMap<>();
        this.getDepth(0, root, depthMap);
        return this.dfs(root, depthMap);
    }

    private int getDepth(int depth, TreeNode root, Map<TreeNode, Integer> depthMap) {
        if (!depthMap.containsKey(root)) {
            if (root == null) {
                depthMap.put(root, -1);
            } else {
                int result = depth;
                int left = this.getDepth(depth + 1, root.left, depthMap);
                result = Math.max(result, left);
                int right = this.getDepth(depth + 1, root.right, depthMap);
                result = Math.max(result, right);
                depthMap.put(root, result);
            }
        }
        return depthMap.get(root);
    }

    private TreeNode dfs(TreeNode root, Map<TreeNode, Integer> depthMap) {
        if (root != null) {
            int left = depthMap.get(root.left);
            int right = depthMap.get(root.right);
            if (left > right) {
                return this.dfs(root.left, depthMap);
            } else if (left < right) {
                return this.dfs(root.right, depthMap);
            }
        }
        return root;
    }
}