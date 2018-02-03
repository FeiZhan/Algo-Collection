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
    private List<String> paths;

    public List<String> binaryTreePaths(TreeNode root) {
        this.paths = new ArrayList<String>();
        getPaths(root, new StringBuilder());
        return this.paths;
    }

    private void getPaths(TreeNode root, StringBuilder path) {
        if (null == root) {
            return;
        }

        if (path.length() > 0) {
            path.append("->");
        }
        path.append(root.val);
        if (root.left == null && root.right == null) {
            this.paths.add(path.toString());
        } else {
            getPaths(root.left, new StringBuilder(path));
            getPaths(root.right, new StringBuilder(path));
        }
    }
}