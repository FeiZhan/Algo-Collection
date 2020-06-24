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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList<>();
        this.dfs(root1, list1);
        List<Integer> list2 = new ArrayList<>();
        this.dfs(root2, list2);
        List<Integer> result = new LinkedList<>();
        for (int i = 0, j = 0; i < list1.size() || j < list2.size();) {
            if (j >= list2.size() || (i < list1.size() && list1.get(i) < list2.get(j))) {
                result.add(list1.get(i));
                i++;
            } else {
                result.add(list2.get(j));
                j++;
            }
        }
        return result;
    }

    private void dfs(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        this.dfs(root.left, list);
        list.add(root.val);
        this.dfs(root.right, list);
    }
}