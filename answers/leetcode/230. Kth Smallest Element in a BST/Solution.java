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
    public int kthSmallest(TreeNode root, int k) {
        TreeNode current = root;
        Stack<TreeNode> stack = new Stack<>();

        while (current != null) {
            stack.add(current);
            current = current.left;
        }

        while (k > 0) {
            current = stack.pop();
            k--;
            if (k == 0) {
                return current.val;
            }

            current = current.right;
            while (current != null) {
                stack.add(current);
                current = current.left;
            }
        }

        return -1;
    }
}
//Runtime: 1 ms, faster than 70.51% of Java online submissions for Kth Smallest Element in a BST.
//Memory Usage: 42.3 MB, less than 87.53% of Java online submissions for Kth Smallest Element in a BST.
