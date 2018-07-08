class Solution {
    public int findCircleNum(int[][] M) {
        int count = 0;
        boolean[] visited = new boolean[M.length];
        for (int i = 0; i < M.length; i++) {
            if (!visited[i]) {
                this.dfs(i, visited, M);
                count++;
            }
        }
        return count;
    }

    private void dfs(int index, boolean[] visited, int[][] M) {
        if (visited[index]) {
            return;
        }
        visited[index] = true;
        for (int i = 0; i < M[index].length; i++) {
            if (M[index][i] > 0) {
                this.dfs(i, visited, M);
            }
        }
    }
}