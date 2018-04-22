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
    public List<Integer> inorderTraversal(TreeNode root) {
        if (null == root) {
            return new ArrayList<>();
        }
        List<Integer> result = this.inorderTraversal(root.left);
        result.add(root.val);
        result.addAll(this.inorderTraversal(root.right));
        return result;
    }
}