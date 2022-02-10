class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> result = new LinkedList<>();

        for (String word : words) {
            boolean flag = false;
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[i].length; j++) {
                    if (dfs(i, j, 0, word, board)) {
                        result.add(word);
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }

        return result;
    }

    private boolean dfs(int x, int y, int index, String word, char[][] board) {
        if (index >= word.length()) {
            return true;
        } else if (x < 0 || x >= board.length || y < 0 || y >= board[x].length || word.charAt(index) != board[x][y]) {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '.';
        boolean result = dfs(x - 1, y, index + 1, word, board) ||
            dfs(x + 1, y, index + 1, word, board) ||
            dfs(x, y - 1, index + 1, word, board) ||
            dfs(x, y + 1, index + 1, word, board);
        board[x][y] = temp;

        return result;
    }
}
//Runtime: 2206 ms, faster than 7.48% of Java online submissions for Word Search II.
//Memory Usage: 42.6 MB, less than 35.50% of Java online submissions for Word Search II.
