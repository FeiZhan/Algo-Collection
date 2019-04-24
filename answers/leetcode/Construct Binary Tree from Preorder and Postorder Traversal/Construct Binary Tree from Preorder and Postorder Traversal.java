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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return this.constructFromPrePost(0, pre.length - 1, pre, 0, post.length - 1, post);
    }

    private TreeNode constructFromPrePost(int preStart, int preEnd, int[] pre, int postStart, int postEnd, int[] post) {
        if (preStart > preEnd || postStart > postEnd) {
            return null;
        }
        TreeNode root = new TreeNode(pre[preStart]);
        if (preStart < preEnd) {
            int leftSize = 0;
            int leftValue = pre[preStart + 1];
            for (int i = postStart; i <= postEnd; i++) {
                if (post[i] == leftValue) {
                    leftSize = i - postStart;
                    break;
                }
            }
            root.left = this.constructFromPrePost(preStart + 1, preStart + leftSize + 1, pre, postStart, postStart + leftSize, post);
            root.right = this.constructFromPrePost(preStart + leftSize + 2, preEnd, pre, postStart + leftSize + 1, postEnd - 1, post);
        }
        return root;
    }
}