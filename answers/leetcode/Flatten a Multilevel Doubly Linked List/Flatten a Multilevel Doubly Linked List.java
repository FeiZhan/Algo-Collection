/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    public Node flatten(Node head) {
        Node[] result = this.dfs(head);
        return result[0];
    }

    private Node[] dfs(Node head) {
        Node[] result = new Node[2];
        result[0] = head;
        result[1] = head;
        if (head != null) {
            System.out.println(head.val);
            Node[] nextResult = this.dfs(head.next);
            Node[] childResult = this.dfs(head.child);
            if (childResult[0] != null) {
                head.next = childResult[0];
                childResult[0].prev = head;
                childResult[1].next = nextResult[0];
                if (nextResult[0] != null) {
                    nextResult[0].prev = childResult[1];
                }
            }
            if (nextResult[1] != null) {
                result[1] = nextResult[1];
            } else if (childResult[1] != null) {
                result[1] = childResult[1];
            }
            head.child = null;
        }
        return result;
    }
}