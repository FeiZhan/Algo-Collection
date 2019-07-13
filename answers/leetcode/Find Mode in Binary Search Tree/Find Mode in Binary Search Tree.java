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
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> counts = new HashMap<>();
        this.dfs(root, counts);
        int maxCount = 0;
        List<Integer> result = new LinkedList<>();
        for (int key : counts.keySet()) {
            int count = counts.get(key);
            if (count > maxCount) {
                maxCount = count;
                result.clear();
            }
            if (count == maxCount) {
                result.add(key);
            }
        }
        int[] temp = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            temp[i] = result.get(i);
        }
        return temp;
    }

    private void dfs(TreeNode root, Map<Integer, Integer> counts) {
        if (root == null) {
            return;
        }
        counts.put(root.val, counts.getOrDefault(root.val, 0) + 1);
        this.dfs(root.left, counts);
        this.dfs(root.right, counts);
    }
}