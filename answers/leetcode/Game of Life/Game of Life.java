class Solution {
    public void gameOfLife(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                int count = (i > 0 && j > 0 && board[i - 1][j - 1] > 0 ? 1 : 0)
                    + (i > 0 && board[i - 1][j] > 0 ? 1 : 0)
                    + (i > 0 && j + 1 < board[i].length && board[i - 1][j + 1] > 0 ? 1 : 0)
                    + (j > 0 && board[i][j - 1] > 0 ? 1 : 0)
                    + (i + 1 < board.length && j > 0 && board[i + 1][j - 1] > 0 ? 1 : 0)
                    + (j + 1 < board[i].length && board[i][j + 1] > 0 ? 1 : 0)
                    + (i + 1 < board.length && j + 1 < board[i].length && board[i + 1][j + 1] > 0 ? 1 : 0)
                    + (i + 1 < board.length && board[i + 1][j] > 0 ? 1 : 0);
                if (board[i][j] == 1 && count < 2) {
                    board[i][j] = 2;
                } else if (board[i][j] == 1 && count > 3) {
                    board[i][j] = 2;
                } else if (board[i][j] == 0 && count == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
}