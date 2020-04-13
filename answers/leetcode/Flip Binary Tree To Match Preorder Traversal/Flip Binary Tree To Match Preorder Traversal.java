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
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        List<Integer> result = new LinkedList<>();
        if (!this.dfs(root, 0, voyage.length - 1, voyage, result)) {
            result.clear();
            result.add(-1);
        }
        return result;
    }

    private boolean dfs(TreeNode root, int start, int end, int[] voyage, List<Integer> result) {
        if (root == null) {
            return true;
        }
        if (root.val != voyage[start]) {
            return false;
        }
        if (root.left == null && root.right == null) {
            return true;
        }
        int left = -1;
        int right = -1;
        for (int i = start + 1; i <= end; i++) {
            if (root.left != null && root.left.val == voyage[i]) {
                left = i;
            }
            if (root.right != null && root.right.val == voyage[i]) {
                right = i;
            }
        }
        if (left == start + 1) {
            if (root.right == null) {
                return this.dfs(root.left, left, end, voyage, result);
            } else if (right >= 0) {
                return this.dfs(root.left, left, right - 1, voyage, result)
                    && this.dfs(root.right, right, end, voyage, result);
            }
        } else if (right == start + 1) {
            if (root.left == null) {
                return this.dfs(root.right, right, end, voyage, result);
            } else if (left >= 0) {
                result.add(root.val);
                return this.dfs(root.right, right, left - 1, voyage, result)
                    && this.dfs(root.left, left, end, voyage, result);
            }
        }
        return false;
    }
}