/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    
    private Stack<TreeNode> nodes;

    public BSTIterator(TreeNode root) {
        this.nodes = new Stack<>();
        TreeNode current = root;
        while (current != null) {
            this.nodes.push(current);
            current = current.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !this.nodes.empty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode next = this.nodes.pop();
        if (next.right == null) {
            TreeNode current = next;
            while (!this.nodes.empty() && this.nodes.peek().right == current) {
                current = this.nodes.pop();
            }
        } else {
            TreeNode current = next.right;
            while (current != null) {
                this.nodes.push(current);
                current = current.left;
            }
        }
        return next.val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */