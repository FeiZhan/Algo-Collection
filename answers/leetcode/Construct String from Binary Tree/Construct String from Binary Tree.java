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
    public String tree2str(TreeNode t) {
        StringBuilder sb = new StringBuilder();
        if (t != null) {
            sb.append(t.val);
            if (t.left != null || t.right != null) {
                sb.append("(");
                sb.append(this.tree2str(t.left));
                sb.append(")");
                if (t.right != null) {
                    sb.append("(");
                    sb.append(this.tree2str(t.right));
                    sb.append(")");
                }
            }
        }
        return sb.toString();
    }
}