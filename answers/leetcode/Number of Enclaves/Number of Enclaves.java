class Solution {
    public int numEnclaves(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            if (A[i][0] == 1) {
                this.dfs(i, 0, A);
            }
            if (A[i][A[i].length - 1] == 1) {
                this.dfs(i, A[i].length - 1, A);
            }
        }
        for (int i = 0; i < A[0].length; i++) {
            if (A[0][i] == 1) {
                this.dfs(0, i, A);
            }
            if (A[A.length - 1][i] == 1) {
                this.dfs(A.length - 1, i, A);
            }
        }
        int count = 0;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[i].length; j++) {
                if (A[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }

    private void dfs(int x, int y, int[][] A) {
        if (x < 0 || x >= A.length || y < 0 || y >= A[x].length || A[x][y] != 1) {
            return;
        }
        A[x][y] = 0;
        this.dfs(x - 1, y, A);
        this.dfs(x + 1, y, A);
        this.dfs(x, y - 1, A);
        this.dfs(x, y + 1, A);
    }
}