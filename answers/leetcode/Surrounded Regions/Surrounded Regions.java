class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        for (int i = 0; i < board.length; i++) {
            this.dfs(board, i, 0);
            this.dfs(board, i, board[i].length - 1);
        }
        for (int i = 0; i < board[0].length; i++) {
            this.dfs(board, 0, i);
            this.dfs(board, board.length - 1, i);
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    private void dfs(char[][] board, int x, int y) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[x].length || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        this.dfs(board, x - 1, y);
        this.dfs(board, x + 1, y);
        this.dfs(board, x, y - 1);
        this.dfs(board, x, y + 1);
    }
}