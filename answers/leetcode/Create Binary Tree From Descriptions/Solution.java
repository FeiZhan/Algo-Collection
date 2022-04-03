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
    public TreeNode createBinaryTree(int[][] descriptions) {
        Set<Integer> children = new HashSet<>();
        Map<Integer, TreeNode> nodes = new HashMap<>();
        for (int[] description : descriptions) {
            children.add(description[1]);
            TreeNode parent = nodes.getOrDefault(description[0], new TreeNode(description[0]));
            TreeNode child = nodes.getOrDefault(description[1], new TreeNode(description[1]));
            if (description[2] == 1) {
                parent.left = child;
            } else {
                parent.right = child;
            }
            nodes.put(description[0], parent);
            nodes.put(description[1], child);
        }

        for (int index : nodes.keySet()) {
            if (!children.contains(index)) {
                return nodes.get(index);
            }
        }

        return null;
    }
}
//Runtime: 66 ms, faster than 94.55% of Java online submissions for Create Binary Tree From Descriptions.
//Memory Usage: 51 MB, less than 96.68% of Java online submissions for Create Binary Tree From Descriptions.
