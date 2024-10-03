class Solution {
    public void solveSudoku(char[][] board) {
        solve(0, 0, board);
    }

    private boolean solve(int x, int y, char[][] board) {
        int length = board.length;
        for (int i = x; i < length; i++) {
            for (int j = y; j < length; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        char c = (char)(k + '0');
                        if (isValid(c, i, j, board)) {
                            board[i][j] = c;
                            if (solve(x, y, board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isValid(char c, int x, int y, char[][] board) {
        int length = board.length;
        for (int i = 0; i < length; i++) {
            if (board[i][y] == c || board[x][i] == c || board[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == c) {
                return false;
            }
        }
        return true;
    }
}