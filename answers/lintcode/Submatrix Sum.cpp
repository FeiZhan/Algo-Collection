//@result Accepted Total Runtime: 61 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int> > sum_mat(matrix.size() + 1, vector<int> (matrix[0].size() + 1, 0));
        for (size_t i = 1; i < sum_mat.size(); ++ i) {
            for (size_t j = 1; j < sum_mat[i].size(); ++ j) {
                sum_mat[i][j] = matrix[i - 1][j - 1] + sum_mat[i - 1][j] + sum_mat[i][j - 1] - sum_mat[i - 1][j - 1];
            }
        }
        vector<vector<int> > sum_index(2, vector<int> (2, 0));
        for (size_t i = 0; i < sum_mat.size(); ++ i) {
            for (size_t j = i + 1; j < sum_mat.size(); ++ j) {
                unordered_map<int, size_t> sum_map;
                for (size_t k = 0; k < sum_mat[i].size(); ++ k) {
                    int sum = sum_mat[j][k] - sum_mat[i][k];
                    if (sum_map.end() != sum_map.find(sum)) {
                        sum_index[0][0] = i;
                        sum_index[0][1] = sum_map[sum];
                        sum_index[1][0] = j - 1;
                        sum_index[1][1] = k - 1;
                        return sum_index;
                    }
                    sum_map.insert(make_pair(sum, k));
                }
            }
        }
        return sum_index;
    }
};
