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
    private class Result {
        public int depth = -1;
        public int distance = -1;
        public int time = -1;
    }

    public int amountOfTime(TreeNode root, int start) {
        Result result = this.run(0, root, start);
        return result.time;
    }

    private Result run(int level, TreeNode root, int target) {
        Result result = new Result();
        if (root == null) {
            return result;
        }

        Result leftResult = this.run(level + 1, root.left, target);
        Result rightResult = this.run(level + 1, root.right, target);
        result.depth = Math.max(leftResult.depth, rightResult.depth) + 1;

        if (root.val == target) {
            result.distance = 0;
            result.time = result.depth;
        } else if (leftResult.distance >= 0) {
            result.distance = leftResult.distance + 1;
            result.time = result.distance + rightResult.depth + 1;
        } else if (rightResult.distance >= 0) {
            result.distance = rightResult.distance + 1;
            result.time = result.distance + leftResult.depth + 1;
        }

        result.time = Math.max(result.time, leftResult.time);
        result.time = Math.max(result.time, rightResult.time);
        return result;
    }
}