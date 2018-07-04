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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length == 0) {
            return null;
        }
        
        return this.buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }
    
    private TreeNode buildTree(int[] preorder, int preLeft, int preRight, int[] inorder, int inLeft, int inRight) {
        if (preLeft > preRight) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preLeft]);
        int rootIndex = 0;
        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == preorder[preLeft]) {
                rootIndex = i;
                break;
            }
        }
        root.left = this.buildTree(preorder, preLeft + 1, preLeft + rootIndex - inLeft, inorder, inLeft, rootIndex - 1);
        root.right = this.buildTree(preorder, preLeft + rootIndex - inLeft + 1, preRight, inorder, rootIndex + 1, inRight);
        return root;
    }
}