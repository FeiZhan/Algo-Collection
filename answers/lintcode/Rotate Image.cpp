class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
		for (size_t i = 0; i < matrix.size() / 2; ++ i) {
			for (size_t j = i; j < matrix[i].size() - 1 - i && j < matrix[i].size(); ++ j) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[matrix.size() - 1 - j][i];
				matrix[matrix.size() - 1 - j][i] = matrix[matrix.size() - 1 - i][matrix[matrix.size() - 1 - i].size() - 1 - j];
				matrix[matrix.size() - 1 - i][matrix[matrix.size() - 1 - i].size() - 1 - j] = matrix[j][matrix[j].size() - 1 - i];
				matrix[j][matrix[j].size() - 1 - i] = temp;
			}
		}
    }
};
