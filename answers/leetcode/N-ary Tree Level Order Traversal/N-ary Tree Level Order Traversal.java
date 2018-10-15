/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        this.dfs(0, root, result);
        return result;
    }

    private void dfs(int level, Node root, List<List<Integer>> result) {
        if (root == null) {
            return;
        }
        while (result.size() <= level) {
            result.add(new ArrayList<>());
        }
        result.get(level).add(root.val);
        for (Node child : root.children) {
            this.dfs(level + 1, child, result);
        }
    }
}