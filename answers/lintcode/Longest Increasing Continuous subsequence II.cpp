//@result TLE

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        if (0 == A.size() || 0 == A[0].size()) {
            return 0;
        }
        vector<vector<int> > dp(A.size(), vector<int> (A[0].size(), 0));
        vector<vector<bool> > visit(A.size(), vector<bool> (A[0].size(), false));
        for (size_t i = 0; i < A.size(); ++ i) {
            for (size_t j = 0; j < A[i].size(); ++ j) {
                dfs(0, INT_MIN, i, j, dp, visit, A);
            }
        }
        int longest = 0;
        for (size_t i = 0; i < dp.size(); ++ i) {
            for (size_t j = 0; j < dp[i].size(); ++ j) {
                longest = max(longest, dp[i][j]);
            }
        }
        return longest;
    }
    void dfs(int length, int parent, size_t x, size_t y, vector<vector<int> > &dp, vector<vector<bool> > &visit, const vector<vector<int>> &A) {
        if (x >= A.size() || y >= A[x].size() || visit[x][y]) {
            return;
        }
        if (A[x][y] > parent && dp[x][y] < length + 1) {
            dp[x][y] = length + 1;
            visit[x][y] = true;
            dfs(dp[x][y], A[x][y], x - 1, y, dp, visit, A);
            dfs(dp[x][y], A[x][y], x + 1, y, dp, visit, A);
            dfs(dp[x][y], A[x][y], x, y - 1, dp, visit, A);
            dfs(dp[x][y], A[x][y], x, y + 1, dp, visit, A);
            visit[x][y] = false;
        }
    }
};
