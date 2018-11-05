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
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        Map<TreeNode, String> nodeMap = new HashMap<>();
        nodeMap.put(null, "");
        this.dfs(root, nodeMap);

        Map<String, TreeNode> pathMap = new HashMap<>();
        Set<TreeNode> duplicates = new HashSet<>();
        for (TreeNode node : nodeMap.keySet()) {
            String path = nodeMap.get(node);
            if (pathMap.containsKey(path)) {
                duplicates.add(pathMap.get(path));
            } else {
                pathMap.put(path, node);
            }
        }
        return new ArrayList<>(duplicates);
    }

    private void dfs(TreeNode root, Map<TreeNode, String> nodeMap) {
        if (root == null) {
            return;
        }
        this.dfs(root.left, nodeMap);
        this.dfs(root.right, nodeMap);
        String traversal = root.val + "," + nodeMap.get(root.left) + "," + nodeMap.get(root.right);
        nodeMap.put(root, traversal);
    }
}