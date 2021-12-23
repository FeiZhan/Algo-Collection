/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public String getDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder sb0 = this.dfs(startValue, root);
        StringBuilder sb1 = this.dfs(destValue, root);

        int index = 0;
        if (sb0 != null && sb1 != null) {
            while (index < sb0.length() && index < sb1.length() && sb0.charAt(index) == sb1.charAt(index)) {
                index++;
            }
        }

        StringBuilder sb = new StringBuilder();
        if (sb0 != null) {
            sb.append("U".repeat(sb0.length() - index));
        }
        if (sb1 != null) {
            sb.append(sb1.substring(index));
        }

        return sb.toString();
    }

    private StringBuilder dfs(int current, TreeNode root) {
        if (root == null) {
            return null;
        } else if (root.val == current) {
            return new StringBuilder();
        }

        StringBuilder sb = this.dfs(current, root.left);
        if (sb != null) {
            sb.insert(0, 'L');
            return sb;
        }

        sb = this.dfs(current, root.right);
        if (sb != null) {
            sb.insert(0, 'R');
            return sb;
        }

        return null;
    }
}
//Runtime: 555 ms, faster than 9.40% of Java online submissions for Step-By-Step Directions From a Binary Tree Node to Another.
//Memory Usage: 110.4 MB, less than 38.64% of Java online submissions for Step-By-Step Directions From a Binary Tree Node to Another.
