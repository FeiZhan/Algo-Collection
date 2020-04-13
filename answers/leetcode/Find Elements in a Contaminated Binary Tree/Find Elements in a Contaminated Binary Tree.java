/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class FindElements {

    private Set<Integer> numbers = new HashSet<>();

    public FindElements(TreeNode root) {
        this.dfs(root, 0);
    }

    public boolean find(int target) {
        return this.numbers.contains(target);
    }

    private void dfs(TreeNode root, int value) {
        if (root == null) {
            return;
        }
        root.val = value;
        this.numbers.add(value);
        this.dfs(root.left, value * 2 + 1);
        this.dfs(root.right, value * 2 + 2);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */