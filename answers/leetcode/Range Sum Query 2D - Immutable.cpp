class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	sum_mat.clear();
        for (size_t i = 0; i < matrix.size(); ++ i) {
        	vector<int> sum_list;
        	for (size_t j = 0; j < matrix[i].size(); ++ j) {
        		sum_list.push_back(matrix[i][j] + (j ? sum_list.back() : 0));
        	}
        	if (i) {
	        	for (size_t j = 0; j < sum_list.size(); ++ j) {
	        		sum_list[j] += sum_mat.back()[j];
	        	}
        	}
        	sum_mat.push_back(sum_list);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sum_mat[row2][col2];
        if (row1 > 0) {
        	sum -= sum_mat[row1 - 1][col2];
        }
        if (col1 > 0) {
        	sum -= sum_mat[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
        	sum += sum_mat[row1 - 1][col1 - 1];
        }
        return sum;
    }
    vector<vector<int> > sum_mat;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);