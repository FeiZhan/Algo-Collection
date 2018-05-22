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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> view = new ArrayList<Integer>();
        this.dfs(root, 0, view);
        return view;
    }
    
    private void dfs(TreeNode root, int level, List<Integer> view) {
        if (null == root) {
            return;
        }
        while (level >= view.size()) {
            view.add(-1);
        }
        view.set(level, root.val);
        this.dfs(root.left, level + 1, view);
        this.dfs(root.right, level + 1, view);
    }
}