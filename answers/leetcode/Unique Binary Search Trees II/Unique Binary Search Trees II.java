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
    private Map<Integer, List<TreeNode>> treeMap = new HashMap<>();
    
    public Solution() {
        this.treeMap.put(0, new LinkedList<>());
    }
    
    public List<TreeNode> generateTrees(int n) {
        if (!this.treeMap.containsKey(n)) {
            List<TreeNode> treeList = new LinkedList<>();
            for (int i = 1; i <= n; i++) {
                List<TreeNode> leftList = this.generateTrees(i - 1);
                if (leftList.size() == 0) {
                    leftList.add(null);
                }
                List<TreeNode> rightList = this.generateTrees(n - i);
                if (rightList.size() == 0) {
                    rightList.add(null);
                }
                for (TreeNode right : rightList) {
                    right = this.add(right, i);
                    for (TreeNode left : leftList) {
                        TreeNode root = new TreeNode(i);
                        root.left = left;
                        root.right = right;
                        treeList.add(root);
                    }
                }
            }
            this.treeMap.put(n, treeList);
        }
        return this.treeMap.get(n);
    }
    
    private TreeNode add(TreeNode root, int num) {
        if (root != null) {
            TreeNode temp = new TreeNode(root.val + num);
            temp.left = this.add(root.left, num);
            temp.right = this.add(root.right, num);
            return temp;
        }
        return root;
    }
}