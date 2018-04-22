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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        this.dfs(root, 0, result);
        return result;
    }

    private void dfs(TreeNode root, int level, List<List<Integer>> result) {
        if (null == root) {
            return;
        }
        while (result.size() <= level) {
            result.add(new ArrayList<>());
        }
        int index = level % 2 != 0 ? 0 : result.get(level).size();
        result.get(level).add(index, root.val);
        this.dfs(root.left, level + 1, result);
        this.dfs(root.right, level + 1, result);
    }
}