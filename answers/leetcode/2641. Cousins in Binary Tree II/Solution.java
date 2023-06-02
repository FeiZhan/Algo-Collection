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
    public TreeNode replaceValueInTree(TreeNode root) {
        List<Integer> levelValues = new ArrayList<>();
        dfs(0, root, levelValues);

        if (root != null) {
            root.val = 0;
        }
        replace(0, root, levelValues);

        return root;
    }

    private void dfs(int level, TreeNode root, List<Integer> levelValues) {
        if (root == null) {
            return;
        }

        while (level >= levelValues.size()) {
            levelValues.add(0);
        }
        levelValues.set(level, levelValues.get(level) + root.val);
        dfs(level + 1, root.left, levelValues);
        dfs(level + 1, root.right, levelValues);
    }

    private void replace(int level, TreeNode root, List<Integer> levelValues) {
        if (root == null) {
            return;
        }

        int children = (root.left != null ? root.left.val : 0) + (root.right != null ? root.right.val : 0);
        if (root.left != null) {
            root.left.val = levelValues.get(level + 1) - children;
        }
        if (root.right != null) {
            root.right.val = levelValues.get(level + 1) - children;
        }

        replace(level + 1, root.left, levelValues);
        replace(level + 1, root.right, levelValues);
    }
}