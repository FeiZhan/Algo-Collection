class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if (0 == board.size() || 0 == board[0].size()) {
            return;
        }
        for (size_t i = 0; i < board[0].size(); ++ i) {
            dfs(0, i, board);
            dfs(board.size() - 1, i, board);
        }
        for (size_t i = 0; i < board.size(); ++ i) {
            dfs(i, 0, board);
            dfs(i, board[i].size() - 1, board);
        }
        for (size_t i = 0; i < board.size(); ++ i) {
            for (size_t j = 0; j < board[i].size(); ++ j) {
                switch(board[i][j]) {
                case 'O':
                    board[i][j] = 'X';
                    break;
                case '.':
                    board[i][j] = 'O';
                    break;
                default:
                    break;
                }
            }
        }
    }
    void dfs(size_t x, size_t y, vector<vector<char>>& board) {
        if (x >= board.size() || y >= board[x].size() || 'O' != board[x][y]) {
            return;
        }
        board[x][y] = '.';
        dfs(x - 1, y, board);
        dfs(x + 1, y, board);
        dfs(x, y - 1, board);
        dfs(x, y + 1, board);
    }
};
