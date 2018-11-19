//@result 137 / 137 test cases passed. Status: Accepted Runtime: 84 ms Submitted: 0 minutes ago You are here! Your runtime beats 60.93% of cppsubmissions.

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return 0;
        }
        vector<vector<int> > length_mat(matrix.size(), vector<int> (matrix[0].size(), INT_MAX));
        int longest = 0;
        for (size_t i = 0; i < matrix.size(); ++ i) {
            for (size_t j = 0; j < matrix[i].size(); ++ j) {
                dfs(i, j, matrix, length_mat);
                longest = max(longest, length_mat[i][j]);
            }
        }
        return longest;
    }
    void dfs(size_t i, size_t j, const vector<vector<int> > &matrix, vector<vector<int> > &length_mat) {
        if (i >= matrix.size() || j >= matrix[i].size() || length_mat[i][j] < INT_MAX) {
            return;
        }
        int longest = 1;
        if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
            dfs(i - 1, j, matrix, length_mat);
            longest = max(longest, length_mat[i - 1][j] + 1);
        }
        if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j]) {
            dfs(i + 1, j, matrix, length_mat);
            longest = max(longest, length_mat[i + 1][j] + 1);
        }
        if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
            dfs(i, j - 1, matrix, length_mat);
            longest = max(longest, length_mat[i][j - 1] + 1);
        }
        if (j + 1 < matrix[i].size() && matrix[i][j] < matrix[i][j + 1]) {
            dfs(i, j + 1, matrix, length_mat);
            longest = max(longest, length_mat[i][j + 1] + 1);
        }
        length_mat[i][j] = longest;
        //cout << "debug " << i << " " << j << " " << length_mat[i][j] << endl;
    }
};