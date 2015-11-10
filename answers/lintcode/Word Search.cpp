class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        vector<vector<bool> > visit_flag(board.size(), vector<bool> (board[0].size(), false));
        for (size_t i = 0; i < board.size(); ++ i) {
            for (size_t j = 0; j < board[i].size(); ++ j) {
                if (exist(0, word, i, j, visit_flag, board)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool exist(size_t current, const string &word, size_t x, size_t y, vector<vector<bool> > &visit_flag, const vector<vector<char> > &board) {
        bool ans_flag = false;
        if (current >= word.length() || x >= board.size() || y >= board[x].size() || visit_flag[x][y] || word[current] != board[x][y]) {
            ans_flag = false;
        }
        else if (current + 1 == word.length() && ! visit_flag[x][y] && word[current] == board[x][y]) {
            ans_flag = true;
        }
        else {
            visit_flag[x][y] = true;
            ans_flag = exist(current + 1, word, x - 1, y, visit_flag, board) || exist(current + 1, word, x + 1, y, visit_flag, board) || exist(current + 1, word, x, y - 1, visit_flag, board) || exist(current + 1, word, x, y + 1, visit_flag, board);
            visit_flag[x][y] = false;
        }
        //cout << "debug " << current << " " << word[current] << " " << x << " " << y << " " << ans_flag << endl;
        return ans_flag;
    }
};
