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
    public int[] findFrequentTreeSum(TreeNode root) {
        Map<Integer, Integer> sums = new HashMap<>();
        this.dfs(root, sums);
        if (sums.size() == 0) {
            return new int[0];
        }
        int max = sums.entrySet()
            .stream()
            .max(Map.Entry.comparingByValue())
            .get()
            .getValue();
        return sums.entrySet()
            .stream()
            .filter(e -> e.getValue().equals(max))
            .map(e -> e.getKey())
            .mapToInt(i -> i)
            .toArray();
    }
    
    private int dfs(TreeNode root, Map<Integer, Integer> sums) {
        if (null == root) {
            return 0;
        }
        int sum = root.val + this.dfs(root.left, sums) + this.dfs(root.right, sums);
        int count = sums.getOrDefault(sum, 0) + 1;
        sums.put(sum, count);
        return sum;
    }
}