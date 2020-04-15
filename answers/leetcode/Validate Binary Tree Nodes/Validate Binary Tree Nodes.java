class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        Set<Integer> children = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0) {
                children.add(leftChild[i]);
            }
            if (rightChild[i] >= 0) {
                children.add(rightChild[i]);
            }
        }
        if (children.size() != n - 1) {
            return false;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!children.contains(i)) {
                root = i;
                break;
            }
        }
        Set<Integer> visited = new HashSet<>();
        if (!this.dfs(root, visited, leftChild, rightChild)) {
            return false;
        }
        return visited.size() == n;
    }

    private boolean dfs(int current, Set<Integer> visited, final int[] leftChild, final int[] rightChild) {
        if (current < 0) {
            return true;
        }
        if (visited.contains(current)) {
            return false;
        }
        visited.add(current);
        return this.dfs(leftChild[current], visited, leftChild, rightChild)
            && this.dfs(rightChild[current], visited, leftChild, rightChild);
    }
}