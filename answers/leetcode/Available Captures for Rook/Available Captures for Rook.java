class Solution {
    public int numRookCaptures(char[][] board) {
        boolean flag = false;
        int x = 0;
        int y = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'R') {
                    flag = true;
                    x = i;
                    y = j;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        int count = 0;
        for (int i = x - 1; i >= 0; i--) {
            if (board[i][y] == 'p') {
                count++;
                break;
            } else if (board[i][y] == 'B') {
                break;
            }
        }
        for (int i = x + 1; i < board.length; i++) {
            if (board[i][y] == 'p') {
                count++;
                break;
            } else if (board[i][y] == 'B') {
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (board[x][i] == 'p') {
                count++;
                break;
            } else if (board[x][i] == 'B') {
                break;
            }
        }
        for (int i = y + 1; i < board[x].length; i++) {
            if (board[x][i] == 'p') {
                count++;
                break;
            } else if (board[x][i] == 'B') {
                break;
            }
        }
        return count;
    }
}