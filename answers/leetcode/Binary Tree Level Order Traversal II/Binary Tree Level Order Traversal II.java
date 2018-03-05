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
    private List<List<Integer>> traversal;

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        this.traversal = new ArrayList<List<Integer>>();
        this.levelOrderBottom(root, 0);
        return this.traversal;
    }

    private void levelOrderBottom(TreeNode root, int level) {
        if (null == root) {
            return;
        }
        while (level >= this.traversal.size()) {
            this.traversal.add(0, new ArrayList<Integer>());
        }
        this.traversal.get(this.traversal.size() - level - 1).add(root.val);
        levelOrderBottom(root.left, level + 1);
        levelOrderBottom(root.right, level + 1);
    }
}