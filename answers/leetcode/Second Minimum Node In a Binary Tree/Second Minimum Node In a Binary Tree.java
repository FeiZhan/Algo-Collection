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
    public int findSecondMinimumValue(TreeNode root) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        this.dfs(root, queue);
        return queue.size() >= 2 ? queue.peek() : -1;
    }

    private void dfs(TreeNode root, PriorityQueue<Integer> queue) {
        if (root == null) {
            return;
        }
        if (!queue.contains(root.val)) {
            queue.add(root.val);
        }
        if (queue.size() > 2) {
            queue.poll();
        }
        this.dfs(root.left, queue);
        this.dfs(root.right, queue);
    }
}