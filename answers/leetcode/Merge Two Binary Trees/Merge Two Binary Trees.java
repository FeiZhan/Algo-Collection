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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (null == t1 && null == t2) {
            return null;
        }
        TreeNode t = new TreeNode(0);
        if (t1 != null) {
            t.val += t1.val;
        }
        if (t2 != null) {
            t.val += t2.val;
        }
        t.left = mergeTrees((t1 != null ? t1.left : null), (t2 != null ? t2.left : null));
        t.right = mergeTrees((t1 != null ? t1.right : null), (t2 != null ? t2.right : null));
        return t;
    }
}