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
    public TreeNode bstFromPreorder(int[] preorder) {
        return this.bstFromPreorder(preorder, 0, preorder.length - 1);
    }

    private TreeNode bstFromPreorder(int[] preorder, int left, int right) {
        if (left > right) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[left]);
        int index = left + 1;
        while (index <= right && preorder[index] < preorder[left]) {
            index++;
        }
        root.left = this.bstFromPreorder(preorder, left + 1, index - 1);
        root.right = this.bstFromPreorder(preorder, index, right);
        return root;
    }
}