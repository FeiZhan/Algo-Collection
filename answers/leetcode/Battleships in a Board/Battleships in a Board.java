class Solution {
    public int countBattleships(char[][] board) {
        int count = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if ('X' == board[i][j] && (0 == i || '.' == board[i - 1][j]) && (0 == j || '.' == board[i][j - 1])) {
                    count++;
                }
            }
        }
        return count;
    }
}