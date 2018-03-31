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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return this.isSame(s, t) || (null != s && (this.isSubtree(s.left, t) || this.isSubtree(s.right, t)));
    }

    private boolean isSame(TreeNode s, TreeNode t) {
        return s == t || (null != s && null != t && s.val == t.val && this.isSame(s.left, t.left) && this.isSame(s.right, t.right));
    }
}