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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> traversal = new ArrayList<>();
        if (root != null) {
            traversal.addAll(this.postorderTraversal(root.left));
            traversal.addAll(this.postorderTraversal(root.right));
            traversal.add(root.val);
        }
        return traversal;
    }
}