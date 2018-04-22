import java.util.Set;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        List<Integer> sudoku;
        for (int i = 0; i < 9; i++) {
            sudoku = new LinkedList<>();
            for (int j = 0; j < 9; j++) {
                if (Character.isDigit(board[i][j])) {
                    sudoku.add(Character.getNumericValue(board[i][j]));
                }
            }
            if (!this.check(sudoku)) {
                return false;
            }

            sudoku = new LinkedList<>();
            for (int j = 0; j < 9; j++) {
                if (Character.isDigit(board[j][i])) {
                    sudoku.add(Character.getNumericValue(board[j][i]));
                }
            }
            if (!this.check(sudoku)) {
                return false;
            }

            if (i % 3 == 0) {
                for (int j = 0; j < 9; j += 3) {
                    sudoku = new LinkedList<>();
                    for (int k = 0; k < 3; k++) {
                        for (int m = 0; m < 3; m++) {
                            if (Character.isDigit(board[i + k][j + m])) {
                                sudoku.add(Character.getNumericValue(board[i + k][j + m]));
                            }
                        }
                    }
                    if (!this.check(sudoku)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private boolean check(List<Integer> sudoku) {
        Set<Integer> set = new HashSet<Integer>(sudoku);
        return set.size() == sudoku.size();
    }
}