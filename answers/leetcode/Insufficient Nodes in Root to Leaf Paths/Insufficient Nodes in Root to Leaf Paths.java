class Solution {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if (root == null) {
            return null;
        } else if (root.left == null && root.right == null) {
            return root.val >= limit ? root : null;
        } else {
            root.left = this.sufficientSubset(root.left, limit - root.val);
            root.right = this.sufficientSubset(root.right, limit - root.val);
            if (root.left == null && root.right == null) {
                return null;
            }
            return root;
        }
    }
}