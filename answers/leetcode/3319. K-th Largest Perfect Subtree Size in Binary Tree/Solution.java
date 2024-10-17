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
    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        List<Integer> sizes = new LinkedList<>();
        findPerfectSubtree(root, sizes);
        Collections.sort(sizes, Collections.reverseOrder());
        
        return sizes.size() >= k ? sizes.get(k - 1) : -1;
    }

    private int findPerfectSubtree(TreeNode node, List<Integer> sizes) {
        if (node == null) {
            return 0;
        }

        int leftCount = findPerfectSubtree(node.left, sizes);
        int rightCount = findPerfectSubtree(node.right, sizes);
        if (leftCount != -1 && leftCount == rightCount) {
            int count = leftCount + rightCount + 1;
            sizes.add(count);
            return count;
        } else {
            return -1;
        }
    }
}