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
    public void recoverTree(TreeNode root) {
        List<TreeNode> mistakes = new ArrayList<>();
        mistakes.add(null);
        mistakes.add(null);
        this.dfs(root, null, mistakes);
        int temp = mistakes.get(0).val;
        mistakes.get(0).val = mistakes.get(1).val;
        mistakes.get(1).val = temp;
    }
    
    private TreeNode dfs(TreeNode root, TreeNode previous, List<TreeNode> mistakes) {
        if (root == null) {
            return previous;
        }
        previous = this.dfs(root.left, previous, mistakes);
        if (previous != null && previous.val >= root.val) {
            if (mistakes.get(0) == null) {
                mistakes.set(0, previous);
            }
            mistakes.set(1, root);
        }
        return this.dfs(root.right, root, mistakes);
    }
}