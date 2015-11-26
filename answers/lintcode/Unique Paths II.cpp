class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        vector<vector<int> > path_list(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), 0));
        for (size_t i = 0; i < obstacleGrid.size(); ++ i) {
            for (size_t j = 0; j < obstacleGrid[i].size(); ++ j) {
                if (0 == i && 0 == j) {
                    path_list[i][j] = 0 == obstacleGrid[i][j];
                }
                if (i > 0) {
                    path_list[i][j] += path_list[i - 1][j];
                }
                if (j > 0) {
                    path_list[i][j] += path_list[i][j - 1];
                }
                if (obstacleGrid[i][j]) {
                    path_list[i][j] = 0;
                }
            }
        }
        return path_list.back().back();
    }
};
