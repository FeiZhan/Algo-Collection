class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (this.bfs(i, j, board, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean bfs(int i, int j, char[][] board, int index, String word) {
        if (index >= word.length()) {
            return true;
        } else if (i < 0 || i >= board.length || j < 0 || j >= board[i].length || board[i][j] != word.charAt(index)) {
            return false;
        }
        board[i][j] = '.';
        if (this.bfs(i - 1, j, board, index + 1, word)
            || this.bfs(i + 1, j, board, index + 1, word)
            || this.bfs(i, j - 1, board, index + 1, word)
            || this.bfs(i, j + 1, board, index + 1, word)) {
            return true;
        } else {
            board[i][j] = word.charAt(index);
            return false;
        }
    }
}