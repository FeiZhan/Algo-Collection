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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaves1 = this.getLeaves(root1);
        List<Integer> leaves2 = this.getLeaves(root2);
        if (leaves1.size() != leaves2.size()) {
            return false;
        }
        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1.get(i) != leaves2.get(i)) {
                return false;
            }
        }
        return true;
    }

    private List<Integer> getLeaves(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        if (root != null) {
            if (root.left == null && root.right == null) {
                result.add(root.val);
            } else {
                result.addAll(this.getLeaves(root.left));
                result.addAll(this.getLeaves(root.right));
            }
        }
        return result;
    }
}