class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int> > path_list(m, vector<int> (n, 0));
        for (size_t i = 0; i < path_list.size(); ++ i) {
            for (size_t j = 0; j < path_list[i].size(); ++ j) {
                if (0 == i && 0 == j) {
                    path_list[i][j] = 1;
                }
                if (i > 0) {
                    path_list[i][j] += path_list[i - 1][j];
                }
                if (j > 0) {
                    path_list[i][j] += path_list[i][j - 1];
                }
            }
        }
        return path_list.back().back();
    }
};
