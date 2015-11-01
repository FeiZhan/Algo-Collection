class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
		if (0 == matrix.size() || 0 == matrix[0].size()) {
			return;
		}
		bool flag0 = false;
		for (size_t i = 0; i < matrix.size(); ++ i) {
			if (0 == matrix[i][0]) {
				flag0 = true;
			}
		}
		bool flag1 = false;
		for (size_t i = 0; i < matrix[0].size(); ++ i) {
			if (0 == matrix[0][i]) {
				flag1 = true;
			}
		}
		for (size_t i = 1; i < matrix.size(); ++ i) {
			for (size_t j = 1; j < matrix[i].size(); ++ j) {
				if (0 == matrix[i][j]) {
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		for (size_t i = 1; i < matrix.size(); ++ i) {
			for (size_t j = 1; j < matrix[i].size(); ++ j) {
				if (0 == matrix[0][j] || 0 == matrix[i][0]) {
					matrix[i][j] = 0;
				}
			}
		}
		if (flag0) {
			for (size_t i = 0; i < matrix.size(); ++ i) {
				matrix[i][0] = 0;
			}
		}
		if (flag1) {
			for (size_t i = 0; i < matrix[0].size(); ++ i) {
				matrix[0][i] = 0;
			}
		}
    }
};
