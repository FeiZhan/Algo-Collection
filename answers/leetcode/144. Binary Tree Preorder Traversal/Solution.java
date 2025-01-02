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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> traversal = new ArrayList<Integer>();
        this.dfs(root, traversal);
        return traversal;
    }
    
    private void dfs(TreeNode root, List<Integer> traversal) {
        if (null == root) {
            return;
        }
        traversal.add(root.val);
        this.dfs(root.left, traversal);
        this.dfs(root.right, traversal);
    }
}