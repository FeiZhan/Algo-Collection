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
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) {
            return null;
        }

        Queue<TreeNode> nextQueue = new LinkedList<>();
        nextQueue.add(root);
        int level = 0;
        while (!nextQueue.isEmpty()) {
            Queue<TreeNode> queue = new LinkedList<>(nextQueue);
            nextQueue.clear();
            List<TreeNode> parent = new LinkedList<>(queue);

            while (!queue.isEmpty()) {
                TreeNode current = queue.poll();
                if (current.left != null) {
                    nextQueue.add(current.left);
                }
                if (current.right != null) {
                    nextQueue.add(current.right);
                }
            }

            if (level % 2 == 0) {
                Stack<Integer> numbers = new Stack<>();
                for (TreeNode node : nextQueue) {
                    numbers.push(node.val);
                }
                for (int i = 0; i < parent.size() && !numbers.isEmpty(); i++) {
                    TreeNode current = parent.get(i);
                    current.left.val = numbers.pop();
                    current.right.val = numbers.pop();
                }
            }
            level++;
        }

        return root;
    }
}