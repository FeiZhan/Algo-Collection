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
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> toDelete = new HashSet<>();
        for (int num : to_delete) {
            toDelete.add(num);
        }
        List<TreeNode> result = new LinkedList<>();
        TreeNode newRoot = this.dfs(result, root, toDelete);
        if (newRoot != null) {
            result.add(newRoot);
        }
        return result;
    }

    private TreeNode dfs(List<TreeNode> result, TreeNode root, Set<Integer> toDelete) {
        if (root == null) {
            return null;
        }
        root.left = this.dfs(result, root.left, toDelete);
        root.right = this.dfs(result, root.right, toDelete);
        if (toDelete.contains(root.val)) {
            if (root.left != null) {
                result.add(root.left);
            }
            if (root.right != null) {
                result.add(root.right);
            }
            return null;
        } else {
            return root;
        }
    }
}