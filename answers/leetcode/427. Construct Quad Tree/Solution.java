/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;


    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        return construct(0, 0, grid.length, grid);
    }

    private Node construct(int x, int y, int length, int[][] grid) {
        if (length == 0) {
            return null;
        } else if (length == 1) {
            return new Node(grid[x][y] == 1, true);
        }

        length /= 2;
        Node node = new Node(false, false);
        node.topLeft = construct(x, y, length, grid);
        node.topRight = construct(x, y + length, length, grid);
        node.bottomLeft = construct(x + length, y, length, grid);
        node.bottomRight = construct(x + length, y + length, length, grid);
        if (node.topLeft.isLeaf && node.topRight.isLeaf && node.bottomLeft.isLeaf && node.bottomRight.isLeaf
            && node.topLeft.val == node.topRight.val && node.topLeft.val == node.bottomLeft.val && node.topLeft.val == node.bottomRight.val) {
                return node.topLeft;
        } else {
            return node;
        }
    }
}