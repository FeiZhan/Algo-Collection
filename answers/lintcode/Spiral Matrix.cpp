class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> spiral;
        for (size_t i = 0; i * 2 < matrix.size(); ++ i) {
            for (size_t j = i; j + i < matrix[i].size(); ++ j) {
                spiral.push_back(matrix[i][j]);
            }
            if (i * 2 < matrix[i].size()) {
                for (size_t j = i + 1; j + i < matrix.size() && i < matrix[j].size(); ++ j) {
                    spiral.push_back(matrix[j][matrix[j].size() - 1 - i]);
                }
            }
            if (i * 2 + 1 < matrix.size()) {
                for (size_t j = i + 1; j + i + 1 < matrix[i].size(); ++ j) {
                    spiral.push_back(matrix[matrix.size() - 1 - i][matrix[matrix.size() - 1 - i].size() - 1 - j]);
                }
            }
            if (i * 2 + 1 < matrix[i].size()) {
                for (size_t j = i; j + i + 1 < matrix.size(); ++ j) {
                    spiral.push_back(matrix[matrix.size() - 1 - j][i]);
                }
            }
        }
        return spiral;
    }
};
