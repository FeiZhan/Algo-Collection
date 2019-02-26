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
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        int result = 0;
        for (Node child : root.children) {
            result = Math.max(result, this.maxDepth(child));
        }
        return result + 1;
    }
}