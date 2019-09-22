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
    public int maxLevelSum(TreeNode root) {
        List<Integer> sums = new LinkedList<>();
        this.dfs(0, root, sums);
        int result = 0;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < sums.size(); i++) {
            if (sums.get(i) > max) {
                max = sums.get(i);
                result = i;
            }
        }
        return result + 1;
    }

    private void dfs(int level, TreeNode root, List<Integer> sums) {
        if (root == null) {
            return;
        }
        while (sums.size() <= level) {
            sums.add(0);
        }
        sums.set(level, sums.get(level) + root.val);
        this.dfs(level + 1, root.left, sums);
        this.dfs(level + 1, root.right, sums);
    }
}