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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> results = new LinkedList<>();
        this.distanceK(target, K, results);
        Map<TreeNode, Integer> siblingMap = new HashMap<>();
        this.dfs(root, target, K, siblingMap, results);
        for (Map.Entry<TreeNode, Integer> entry : siblingMap.entrySet()) {
            this.distanceK(entry.getKey(), entry.getValue(), results);
        }
        return results;
    }

    private int dfs(TreeNode root, TreeNode target, int value, Map<TreeNode, Integer> siblingMap, List<Integer> results) {
        if (root != null) {
            if (root == target) {
                return value;
            }
            int left = this.dfs(root.left, target, value, siblingMap, results);
            if (left >= 0) {
                siblingMap.put(root.right, left - 2);
                if (left == 1) {
                    results.add(root.val);
                }
                return left - 1;
            }
            int right = this.dfs(root.right, target, value, siblingMap, results);
            if (right >= 0) {
                siblingMap.put(root.left, right - 2);
                if (right == 1) {
                    results.add(root.val);
                }
                return right - 1;
            }
        }
        return -1;
    }

    private void distanceK(TreeNode root, int value, List<Integer> results) {
        if (root != null) {
            if (value == 0) {
                results.add(root.val);
            } else {
                this.distanceK(root.left, value - 1, results);
                this.distanceK(root.right, value - 1, results);
            }
        }
    }
}