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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> largest = new ArrayList<>();
        this.dfs(root, 0, largest);
        return largest;
    }
    
    private void dfs(TreeNode root, int level, List<Integer> largest) {
        if (root == null) {
            return;
        }
        while (largest.size() <= level) {
            largest.add(Integer.MIN_VALUE);
        }
        largest.set(level, Math.max(largest.get(level), root.val));
        this.dfs(root.left, level + 1, largest);
        this.dfs(root.right, level + 1, largest);
    }
}