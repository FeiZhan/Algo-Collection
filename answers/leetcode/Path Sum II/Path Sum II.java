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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        this.dfs(new ArrayList<>(), root, sum, result);
        return result;
    }

    private void dfs(List<Integer> path, TreeNode root, int sum, List<List<Integer>> result) {
        if (null == root) {
            return;
        }
        path.add(root.val);
        if (null == root.left && null == root.right && sum == root.val) {
            result.add(new ArrayList<>(path));
        }
        this.dfs(path, root.left, sum - root.val, result);
        this.dfs(path, root.right, sum - root.val, result);
        path.remove(path.size() - 1);
    }
}