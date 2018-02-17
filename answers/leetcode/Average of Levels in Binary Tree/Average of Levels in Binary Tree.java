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
    private List<Double> sums;
    private List<Integer> counts;

    public List<Double> averageOfLevels(TreeNode root) {
        this.sums = new ArrayList<Double>();
        this.counts = new ArrayList<Integer>();
        this.averageOfLevels(root, 0);
        for (int i = 0; i < this.counts.size(); i++) {
            this.sums.set(i, this.sums.get(i) / this.counts.get(i));
        }
        return this.sums;
    }

    private void averageOfLevels(TreeNode root, int level) {
        if (null == root) {
            return;
        }
        while (this.sums.size() <= level) {
            this.sums.add(0.0);
        }
        while (this.counts.size() <= level) {
            this.counts.add(0);
        }
        this.sums.set(level, this.sums.get(level) + root.val);
        this.counts.set(level, this.counts.get(level) + 1);
        this.averageOfLevels(root.left, level + 1);
        this.averageOfLevels(root.right, level + 1);
    }
}