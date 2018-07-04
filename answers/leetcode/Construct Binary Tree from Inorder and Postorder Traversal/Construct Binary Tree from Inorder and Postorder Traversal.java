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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || inorder.length == 0) {
            return null;
        }
        
        return this.buildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }
    
    private TreeNode buildTree(int[] inorder, int inLeft, int inRight, int[] postorder, int postLeft, int postRight) {
        if (inLeft > inRight) {
            return null;
        }
        
        int rootIndex = inLeft;
        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == postorder[postRight]) {
                rootIndex = i;
                break;
            }
        }
        TreeNode root = new TreeNode(postorder[postRight]);
        root.left = this.buildTree(inorder, inLeft, rootIndex - 1, postorder, postLeft, postLeft + rootIndex - inLeft - 1);
        root.right = this.buildTree(inorder, rootIndex + 1, inRight, postorder, postLeft + rootIndex - inLeft, postRight - 1);
        return root;
    }
}